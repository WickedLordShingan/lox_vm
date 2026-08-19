#include "chunk.h"
#include "debug.h"

int main() {
  Chunk *chunk = (Chunk *)malloc(sizeof(Chunk));
  init_chunk(chunk);
  write_chunk(chunk, OP_RETURN);
  disassembleChunk(chunk, "test chunk");
  free_chunk(chunk);
}
