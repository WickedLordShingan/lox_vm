#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "common.h"

typedef enum {
  OP_RETURN,
} OPCode;

typedef struct {
  uint8_t *code;
  int count;
  int capacity;
} Chunk;

void init_chunk(Chunk *chunk);
void write_chunk(Chunk *chunk, uint8_t byte);
void free_chunk(Chunk *chunk);

#endif // !CLOX_CHUNK_H
