#include "chunk.h"
#include "debug.h"

int main() {
  Chunk chunk;
  init_chunk(&chunk);

  int ind = addConstant(&chunk, 1.2);
  write_chunk(&chunk, OP_CONST, 122);
  write_chunk(&chunk, ind, 122);
  write_chunk(&chunk, OP_RETURN, 122);

  disassembleChunk(&chunk, "test chunk");
  free_chunk(&chunk);
}
