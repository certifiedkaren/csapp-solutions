#include <stdio.h>

// 2.78
//
// x/2^k with correct rounding

int divide_power2(int x, int k) {
  int sign = x >> 31;
  int bias = sign & ((1 << k) - 1);
  return (x + bias) >> k;
}

int main(void) {
  printf("%d\n", divide_power2(130, 1));   // 65
  printf("%d\n", divide_power2(131, 2));   // 32
  printf("%d\n", divide_power2(2001, 3));  // 250
  printf("%d\n", divide_power2(2111, 3));  // 263
  printf("%d\n", divide_power2(-151, 1));  // -75
  printf("%d\n", divide_power2(-2111, 3)); // -263
  return 0;
}
