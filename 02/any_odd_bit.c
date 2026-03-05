#include <stdio.h>

// 2.64
//
// return 1 if any of the odd bits are 1

int any_odd_one(unsigned int x) {
  unsigned int mask = 0xAAAAAAAA;
  return (x & mask) != 0;
}

int main(void) {
  printf("test 1: %d\n", any_odd_one(0x00000001));
  printf("test 2: %d\n", any_odd_one(0x00000002));
}
