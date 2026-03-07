#include <stdio.h>

// 2.73
//
// returns intmax in positive overflow, intmin in negative overflow
int saturating_add(int x, int y) {
  int sum = x + y;
  int sum_sign = sum >> 31;
  int x_sign = x >> 31;
  int y_sign = y >> 31;

  int overflow = ~(x_sign ^ y_sign) & (x_sign ^ sum_sign);
  int tmin = 1 << 31;
  int tmax = ~tmin;
  int sat = (x_sign & tmin) | (~x_sign & tmax);
  return (overflow & sat) | (~overflow & sum);
}

#include <limits.h>

int main(void) {
  printf("%d\n", saturating_add(232, 22));
  printf("%d\n", saturating_add(INT_MIN, -382));
  printf("%d\n", saturating_add(INT_MAX, 82));
  return 0;
}
