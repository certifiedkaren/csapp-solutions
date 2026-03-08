#include <stdio.h>

// 2.79
//
// multiplies 3 divides by 4 using bit-level rules

int mul3div4(int x) {
  int bias = (x >> 31) & 3;
  return (x + x + x + bias) >> 2;
}

int main(void) {
  printf("%d\n", mul3div4(89));
  printf("%d\n", (89 * 3) / 4);
  printf("%d\n", mul3div4(9922));
  printf("%d\n", (9922 * 3) / 4);
  printf("%d\n", mul3div4(-83272));
  printf("%d\n", (-83272 * 3) / 4);
  printf("%d\n", mul3div4(-3));
  printf("%d\n", (-3 * 3) / 4);
  return 0;
}
