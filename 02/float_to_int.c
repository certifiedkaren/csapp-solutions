#include <stdint.h>
#include <stdio.h>

float u2f(unsigned n) {
  union {
    unsigned u;
    float f;
  } tmp;
  tmp.u = n;
  return tmp.f;
}

unsigned f2u(float n) {
  union {
    unsigned u;
    float f;
  } tmp;
  tmp.f = n;
  return tmp.u;
}

typedef unsigned float_bits;

int is_nan(float_bits f) {
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  return exp == 0xFF && frac != 0;
}

// compute (int) f
int float_f2i(float_bits f) {

  unsigned sign = f & 0x80000000;
  unsigned exp = (f >> 23) & 0xFF;
  int exp_val = exp - 127;
  unsigned frac = f & 0x7FFFFF;

  if (exp == 0xFF || exp_val > 30)
    return 0x80000000;
  if (exp_val < 0)
    return 0;

  frac |= 0x800000;
  if (exp_val > 23) {
    frac <<= exp_val - 23;
  } else if (exp_val < 23) {
    frac >>= 23 - exp_val;
  }

  return sign ? -frac : frac;
}

int main(void) {
  for (int64_t i = 0; i <= 0xFFFFFFFF; i++) {
    float_bits f = (float_bits)i;
    float input = u2f(f);
    int expected = (int)input;
    int result = float_f2i(f);

    if (is_nan(f))
      expected = 0x80000000;
    if (result != expected) {
      printf("Mismatch\n");
      printf("input: 0x%08x\n", f);
      printf("expected: 0x%08x\n", expected);
      printf("result: 0x%08x\n", result);
      return 1;
    }
  }

  printf("passed all tests\n");
  return 0;
}
