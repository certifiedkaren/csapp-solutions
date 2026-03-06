#include <stdio.h>

// 2.63
//
// logical right shift using an arithmetic right shift
unsigned srl(unsigned x, int k) {
  unsigned xsra = (int)x >> k;
  unsigned mask = (unsigned)0xFFFFFFFF >> k;
  return xsra & mask;
}

// arithmetic right shift using a logical right shift
unsigned sra(unsigned x, int k) {
  unsigned xsrl = (unsigned)x >> k;
  unsigned sign = (unsigned)x >> 31;
  unsigned mask = 0u - sign;
  unsigned top = ~(~0u >> k);
  return xsrl | (mask & top);
}

int main(void) {
  printf("logical right shift test\n");
  unsigned x1 = 0xFFFFFF00;
  printf("0x%08X\n", srl(x1, 16));

  printf("--------------------\n");

  printf("arithmetic right shift test\n");
  unsigned x2 = 0xFFFFFF00;
  printf("0x%08X\n", sra(x2, 16));
  unsigned x3 = 0x00FFFFFF;
  printf("0x%08X\n", sra(x3, 16));
}
