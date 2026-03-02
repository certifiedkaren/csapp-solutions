#include <stdio.h>

// for a 32-bit int
int div16(int x) {
  int bias = (x >> 31) & 15;
  return (x + bias) >> 4;
}

int main(void) {
  printf("%d\n", div16(44));
  printf("%d\n", div16(64));
  printf("%d\n", div16(-81));
  printf("%d\n", -81 >> 4);
}
