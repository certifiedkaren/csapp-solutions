#include <stdio.h>

float u2f(unsigned u) {
  union {
    unsigned u;
    float f;
  } tmp;
  tmp.u = u;
  return tmp.f;
}

unsigned f2u(float f) {
  union {
    unsigned u;
    float f;
  } tmp;
  tmp.f = f;
  return tmp.u;
}

typedef unsigned float_bits;

int is_nan(float_bits f) {
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  if (exp == 0xFF && frac != 0)
    return 1;
  return 0;
}

float_bits float_negative(float_bits f) {
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  if (exp == 0xFF && frac != 0)
    return f;
  return f ^ 0x80000000;
}

#include <stdint.h>

int main(void) {
  for (uint64_t i = 0; i < 0xFFFFFFFF; i++) {
    float_bits f = (float_bits)i;

    float input = u2f(f);
    float expected = -input;
    float_bits expected_bits = f2u(expected);
    float_bits result = float_negative(f);

    if (is_nan(f))
      expected_bits = f;

    if (result != expected_bits) {
      printf("Mismatch\n");
      printf("input: 0x%08x\n", f);
      printf("expected: 0x%08x\n", expected_bits);
      printf("result: 0x%08x\n", result);
      return 1;
    }
  }
  printf("All tests passed!\n");
  return 0;
}
