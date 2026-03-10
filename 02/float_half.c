#include <stdint.h>
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
  return exp == 0xFF && frac != 0;
}

// 2.95
// computes 0.5*f, if f is NaN, then return f.
float_bits float_half(float_bits f) {
  unsigned sign = f & 0x80000000;
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x7FFFFF;
  int round_even = (f & 0x3) == 0x3;

  if (is_nan(f))
    return f;
  if (exp == 0xFF)
    return f;

  if (exp == 0) {
    frac >>= 1;
    if (round_even)
      frac += 1;
    return sign | (exp << 23) | frac;
  }

  if (exp == 1) {
    exp = 0;
    frac |= 0x800000;
    frac >>= 1;
    if (round_even)
      frac += 1;
    return sign | (exp << 23) | frac;
  }

  exp -= 1;
  return sign | (exp << 23) | frac;
}

int main(void) {
  for (int64_t i = 0; i < 0xFFFFFFFF; i++) {
    float_bits f = (float_bits)i;
    float input = u2f(f);
    float expected = input * 0.5;
    unsigned expected_bits = f2u(expected);
    unsigned result = float_half(f);

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
  printf("passed all tests!\n");
  return 0;
}
