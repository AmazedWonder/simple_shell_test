#include "memory.h"

/**
 * _realloc - funtion responsible for reallocation of memory
 * using malloc and free
 *
 * @ptr: pointer to void/memory previously allocated
 * @old_size: bytes of the allocated memory for ptr
 * @new_size: new size bytes of new memory realloc
 *
 * Return: pointer to char
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size) {
  char *s, *aux;
  unsigned int a;

  if (new_size == old_size)
    return (ptr);

  if (ptr == NULL) {
    s = malloc(new_size);
    if (s == NULL)
      return (NULL);

    return (s);
  }

  if (new_size == 0 && ptr != NULL) {
    free(ptr);
    return (NULL);
  }

  s = malloc(new_size);
  if (s == NULL)
    return (NULL);

  aux = ptr;
  for (a = 0; a < old_size; a++)
    s[a] = aux[a];

  free(ptr);

  return (s);
}