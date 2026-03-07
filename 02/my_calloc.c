#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// 2.76
//
// implements calloc using malloc and memset

void *my_calloc(size_t nmemb, size_t size) {
  if (nmemb == 0 || size == 0)
    return NULL;

  if (nmemb > SIZE_MAX / size)
    return NULL;

  void *ptr = malloc(nmemb * size);
  if (ptr == NULL)
    return NULL;
  memset(ptr, 0, sizeof(nmemb));
  return ptr;
}
