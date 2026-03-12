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

// returns the bit-level representation of (float) i
float_bits float_i2f(int i) {
  unsigned sign = 0;
  unsigned x = (unsigned) i;
  if (i == 0)
    return 0;
  if (i < 0) {
    sign = i & 0x80000000;
    x = ~x + 1;
  }
  unsigned frac = x;

  int msb = 31 - __builtin_clz(x);
  unsigned exp = (msb + 127) << 23;
  if (msb > 23) {
    int shift = msb - 23;
    unsigned truncated = frac >> shift;
    unsigned discarded = frac & ((1 << (shift)) - 1);
    unsigned half = 1 << (shift - 1);
    if (discarded > half || (discarded == half && (truncated & 1)))
      truncated++; 

    if (truncated & 0x01000000) {
      exp += 1 << 23;
      truncated >>= 1; 
    }
    frac = truncated & 0x007FFFFF;
  } else { 
    frac <<= (23 - msb);
    frac &= 0x007FFFFF;
  } 

  return sign | exp | frac;
}

int main(void) {
  for (int64_t i = 0; i <= 0xFFFFFFFF; i++) {
    int x = (int) i;
    float expected = (float) x;
    float_bits expected_bits = f2u(expected);
    int result = float_i2f(x);

    if (result != expected_bits) {
      printf("Mismatch\n");
      printf("input: 0x%08x\n", x);
      printf("expected: 0x%08x\n", expected_bits);
      printf("result: 0x%08x\n", result);
      return 1;
    }
  }

  printf("passed all tests!\n");
  return 0;
}
