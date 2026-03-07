#include <stdio.h>

// 2.74

int tsub_ok(int x, int y) {
  int sum = x - y;
  int xsign = x >> 31;
  int ysign = y >> 31;
  int sumsign = sum >> 31;
  int overflow = (xsign ^ ysign) & (xsign ^ sumsign);
  return !overflow;
}

#include <limits.h>

int main(void) {
  printf("%d\n", tsub_ok(55, 9328));
  printf("%d\n", tsub_ok(10000, 9328));
  printf("%d\n", tsub_ok(INT_MIN, 9328));
  printf("%d\n", tsub_ok(9002, INT_MIN));
  return 0;
}
