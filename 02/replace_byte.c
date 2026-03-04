#include <stdio.h>

// 2.60

unsigned int replace_byte(unsigned int x, int i, unsigned char b) {
  if (i > sizeof(unsigned int) || i < 0)
    return -1;
  unsigned int mask = ~0 & ~(0xFF << i * 8);
  x &= mask;
  x |= b << i * 8;
  return x;
}

int main(void) {
  printf("0x%X\n", replace_byte(0x12345678, 2, 0xAB));
  printf("0x%X\n", replace_byte(0x12345678, 0, 0xAB));
  printf("0x%X\n", replace_byte(0x12345678, 3, 0x9F));
}
