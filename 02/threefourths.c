#include <limits.h>
#include <stdint.h>
#include <stdio.h>
// 2.80
//
// computes 3/4 * x rounded toward zero without overflow

// 3q + 3r/4
// q = x >> 2, r = x & 3
int threefourths(int x) {
  int q = x >> 2;
  int has_rem = ((x & 3) | ((x & 3) >> 1)) & 1;
  int is_pos = (x >> 31) + 1;
  int bias = has_rem & is_pos;
  return x - (q + bias);
}
int main() {
  int tests[] = {-8, -7,        -6,    -5,      -4,    -3,      -2,     -1,
                 0,  1,         2,     3,       4,     5,       6,      7,
                 8,  -82372387, 82721, -157571, 12123, INT_MAX, INT_MIN};

  for (int i = 0; i < sizeof(tests) / sizeof(int); i++) {
    int x = tests[i];
    int64_t numerator = 3 * x;
    printf("x=%d  result=%d  expected=%d\n", x, threefourths(x),
           (int)((3LL * x) / 4));
  }
}
