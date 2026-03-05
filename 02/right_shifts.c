#include <stdio.h>

// 2.63
//
// logical right shift using an arithmetic right shift
unsigned srl(unsigned x, int k) {
  unsigned xsra = (int)x >> k;
  return 0;
}

// arithmetic right shift using a logical right shift
unsigned sra(unsigned x, int k) {
  unsigned xsra = (unsigned)x >> k;
  return 0;
}

int main(void) { printf(""); }
