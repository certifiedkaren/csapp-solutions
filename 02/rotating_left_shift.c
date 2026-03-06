#include <stdio.h>

// 2.69

// the & 31 acts like % 32 on n
unsigned rotate_left(unsigned x, int n) {
  unsigned mask = x >> (32 - n) & 31;
  return (x << n) | mask;
}

int main(void) {
  printf("0x%08X\n", rotate_left(0xAA000000, 4));
  printf("0x%08X\n", rotate_left(0x12345678, 4));
  printf("0x%08X\n", rotate_left(0x12345678, 20));
  printf("0x%08X\n", rotate_left(0x12345678, 0));
  printf("0x%08X\n", rotate_left(0xF234ABCD, 0));
}
