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

float_bits float_twice(float_bits f) {

  if (is_nan(f))
    return f;

  unsigned sign = f & 0x80000000;
  unsigned exp = (f >> 23) & 0xFF;
  unsigned frac = f & 0x7FFFFF;

  if (exp == 0xFF)
    return f;

  // denormalized number
  if (exp == 0) {
    frac <<= 1;
    if (frac & 0x800000) {
      exp = 1;
      frac &= 0x7FFFFF;
    }
    return sign | (exp << 23) | frac;
  }

  exp += 1;
  if (exp == 0xFF)
    frac = 0;
  return sign | (exp << 23) | frac;
}

int main(void) {
  for (int64_t i = 0; i < 0xFFFFFFFF; i++) {
    float_bits f = (float_bits)i;
    float input = u2f(f);
    float expected = input * 2;
    unsigned expected_bits = f2u(expected);
    unsigned result = float_twice(f);

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

  printf("passed all tests\n");
  return 0;
}
