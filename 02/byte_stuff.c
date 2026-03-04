#include <stdio.h>

// 2.59

// least significant byte of x and the remaining bytes of y
unsigned int foo(unsigned int x, unsigned int y) {
  y &= 0xFFFFFF00;
  x &= 0x000000FF;
  return y | x;
}

int main(void) {
  printf("%#08X\n", foo(0x89ABCDEF, 0x76543210));
  printf("%#08X\n", foo(0x12345678, 0xAABBCCDD));
}
