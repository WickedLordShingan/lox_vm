#ifndef CLOX_MEMORY_H
#define CLOX_MEMORY_H

#include "common.h"

#define GROW_CAPACITY(capacity) ((capacity < 8) ? 8 : 2 * (capacity))
#define GROW_ARRAY(type, array, old_count, new_count)                          \
  (type *)reallocate(array, sizeof(type) * old_count, sizeof(type) * new_count)
#define FREE_ARRAY(type, array, curr_size)                                     \
  reallocate(array, sizeof(type) * curr_size, 0)

void *reallocate(void *pointer, size_t old_size, size_t new_size);

#endif // !CLOX_MEMORY_H
