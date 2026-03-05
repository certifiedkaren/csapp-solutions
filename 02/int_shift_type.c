#include <stdio.h>

// 2.62

// if the system uses an arithmetic right shift, it returns 1, otherwise returns
// 0
int int_shifts_are_arithmetic() {
  int byte = -1;
  return (byte >> 1) == -1;
}

int main(void) { printf("%d\n", int_shifts_are_arithmetic()); }
