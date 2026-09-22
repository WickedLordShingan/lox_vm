#ifndef CLOX_VM_H
#define CLOX_VM_H

#include "chunk.h"
#include "value.h"
#include <stdint.h>

#define STACK_MAX 256

typedef struct {
  Chunk *chunk;
  uint8_t *ip;
  Value stack[STACK_MAX];
  Value *sp;
} VM;

typedef enum {
  INERPRET_OK,
  INTERPRET_COMPILE_ERROR,
  INTERPRET_RUNTIME_ERROR,
} InterpretResult;

void initVM();
void push(Value val);
Value pop();
InterpretResult interpret(Chunk *chunk);
void freeVM();

#endif // !CLOX_VM_H
