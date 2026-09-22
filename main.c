#include "chunk.h"
#include "common.h"
#include "debug.h"
#include "vm.h"

int main() {
  initVM();

  Chunk chunk;
  init_chunk(&chunk);

  int ind = addConstant(&chunk, 1.8);
  write_chunk(&chunk, OP_CONST, 122);
  write_chunk(&chunk, ind, 122);

  ind = addConstant(&chunk, 1.2);
  write_chunk(&chunk, OP_CONST, 122);
  write_chunk(&chunk, ind, 122);
  write_chunk(&chunk, OP_NEGATE, 122);

  write_chunk(&chunk, OP_SUB, 123);
  write_chunk(&chunk, OP_RETURN, 123);

  // disassembleChunk(&chunk, "test chunk");
  interpret(&chunk);

  freeVM();
  free_chunk(&chunk);
}
