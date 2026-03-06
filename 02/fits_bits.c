#include <limits.h>
#include <stdio.h>

// 2.70
// return 1 when x can be represented as an n-bit 2's complement, 0 otherwise
// 1 <= n <= 32
int fits_bits(int x, int n) {
  int temp = x;
  temp <<= (32 - n);
  temp >>= (32 - n);
  return temp == x;
}

int main(void) {
  printf("%d\n", fits_bits(5, 3));
  printf("%d\n", fits_bits(2, 3));
  printf("%d\n", fits_bits(22939, 16));
  printf("%d\n", fits_bits(INT_MAX, 16));
}
