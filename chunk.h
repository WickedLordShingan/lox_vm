#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"
#include "value.h"

typedef enum {
  OP_CONST,
  OP_RETURN,
} OPCode;

typedef struct {
  uint8_t *code;
  int *lines;
  ValueArray constants;
  int count;
  int capacity;
} Chunk;

void init_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte, int line);
void free_chunk(Chunk *chunk);
int addConstant(Chunk *chunk, Value value);

#endif // !CLOX_CHUNK_H
