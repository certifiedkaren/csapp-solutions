#include <stdio.h>

// 2.58

int is_little_endian() {
  int n = 1;
  return *(char *)&n;
}

int main(void) { printf("%d\n", is_little_endian()); }
