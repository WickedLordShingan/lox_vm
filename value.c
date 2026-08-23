#include "value.h"
#include "memory.h"
#include <stdio.h>

void init_value_array(ValueArray *array) {
  array->capacity = 0;
  array->count = 0;
  array->values = NULL;
}

void write_value_array(ValueArray *array, Value value) {
  if (array->count >= array->capacity) {
    int old_cap = array->capacity;
    array->capacity = GROW_CAPACITY(old_cap);
    array->values = GROW_ARRAY(Value, array->values, old_cap, array->capacity);
  }
  (array->values)[array->count] = value;
  array->count++;
}

void free_value_array(ValueArray *array) {
  FREE_ARRAY(Value, array->values, array->capacity);
  init_value_array(array);
}

void print_value(Value val) { printf("%g", val); }
