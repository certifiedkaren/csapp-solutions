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
  unsigned sign = i & 0x80000000;
  unsigned frac = i;
  if (i == 0)
    return 0;

  int msb = 31 - __builtin_clz((unsigned) i);

  if (msb > 23) {
    int shift = msb - 23;
    unsigned discarded = frac & ((1 << (shift)) - 1);
    unsigned half = 1 << (shift - 1);
    if (discarded > half) {
      frac++; 
    } else if (discarded == half) {
      // guard bit: LSB
      // round bit: 1st bit removed
      // sticky bit: OR of remaining bits
      unsigned lsb = (frac >> (shift - 1)) & 1;
      unsigned round_bit = (frac >> (shift - 1)) & 1;
      unsigned sticky_bit = (i & ((1 << (shift - 2)) - 1)) != 0;
      if (round_bit == 1 && (sticky_bit == 1 || lsb == 1))
        frac++;
    }
    frac >>= (msb - 23);
    frac &= 0x007FFFFF;
  } else if (msb < 23){
    frac <<= (23 - msb);
    frac &= 0x007FFFFF;
  } else {
    frac &= 0x007FFFFF;
  }

  unsigned exp = msb + 127;
  exp <<= 23;

  return sign | exp | frac;
}

int main(void) {
  // int to float
  for (int64_t i = 0; i <= 0xFFFFFFFF; i++) {
    float_bits f = (float_bits)i;
    float expected = (float) f;
    float_bits expected_bits = f2u(expected);
    int result = float_i2f(f);

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
