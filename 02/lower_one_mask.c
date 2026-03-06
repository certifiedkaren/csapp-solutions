#include <stdio.h>

// 2.68
//
// mask with least significant n bits set to 1
// ex. n = 6 -> 0x3F;

int lower_one_mask(int n) { return ~0u >> (32 - n); }

int main(void) {
  printf("0x%08X\n", lower_one_mask(6));
  printf("0x%08X\n", lower_one_mask(17));
}
