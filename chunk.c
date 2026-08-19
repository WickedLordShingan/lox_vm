#include "chunk.h"
#include "common.h"
#include "memory.h"

void init_chunk(Chunk *chunk) {
  chunk->capacity = 0;
  chunk->count = 0;
  chunk->code = NULL;
}

void write_chunk(Chunk *chunk, uint8_t byte) {
  if (chunk->count >= chunk->capacity) {
    int oldCapacity = chunk->capacity;
    chunk->capacity = GROW_CAPACITY(oldCapacity);
    chunk->code =
        GROW_ARRAY(uint8_t, chunk->code, oldCapacity, chunk->capacity);
  }

  (chunk->code)[chunk->count] = byte;
  chunk->count += 1;
}

void free_chunk(Chunk *chunk) {
  FREE_ARRAY(uint8_t, chunk, chunk->capacity);
  init_chunk(chunk);
}
