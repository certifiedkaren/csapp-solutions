#include <stdio.h>

// 2.66
//
// indicates leftmost 1 in x, if x=0 return 0
// ex. 0xFF00 -> 0x8000

int leftmost_one(unsigned x) {
  x |= (x >> 1);
  x |= (x >> 2);
  x |= (x >> 4);
  x |= (x >> 8);
  x |= (x >> 16);
  unsigned mask = x >> 1;
  return x ^ mask;
}

int main(void) {
  printf("0x%08X\n", leftmost_one(0xFF00));
  printf("0x%08X\n", leftmost_one(0x6600));
  printf("0x%08X\n", leftmost_one(0x60001000));
  printf("0x%08X\n", leftmost_one(0x902010F0));
}
