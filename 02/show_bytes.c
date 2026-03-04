#include <stdio.h>

void print_bytes(void *ptr, int size) {
  unsigned char *p = ptr;
  for (int i = 0; i < size; i++) {
    printf("%02hhX", p[i]);
  }
  printf("\n");
}

int main(void) {
  short s = 24;
  int i = 88;
  double d = 84.82;
  print_bytes(&s, sizeof(s));
  print_bytes(&i, sizeof(i));
  print_bytes(&d, sizeof(d));
}
