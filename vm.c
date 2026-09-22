#include "vm.h"
#include "chunk.h"
#include "debug.h"
#include "value.h"

#include <stdint.h>
#include <stdio.h>

VM vm;

static void reset_stack() { vm.sp = vm.stack; }

void initVM() { reset_stack(); }

void freeVM() {}

void push(Value val) {
  *vm.sp = val;
  vm.sp++;
}

Value pop() {
  vm.sp--;
  return *vm.sp;
}

static InterpretResult run() {
#define READ_BYTE() *vm.ip++
#define READ_CONST() vm.chunk->constants.values[READ_BYTE()]
#define binary(op)                                                             \
  do {                                                                         \
    double b = pop();                                                          \
    double a = pop();                                                          \
    push(a op b);                                                              \
  } while (false)

  while (true) {
#ifdef DEBUG_TRACE_EXECUTION
    printf("     ");
    for (Value *slot = vm.stack; slot < vm.sp; slot++) {
      printf("[  ");
      print_value(*slot);
      printf("  ]");
    }
    printf("\n");

    disassembleInstruction(vm.chunk, (int)(vm.ip - vm.chunk->code));
#endif

    uint8_t instruction = READ_BYTE();
    // idk why they've done some weird shi in the code here
    switch (instruction) {
    case OP_ADD:
      binary(+);
      break;
    case OP_SUB:
      binary(-);
      break;
    case OP_MULTIPLY:
      binary(*);
      break;
    case OP_DIVIDE:
      binary(/);
      break;
    case OP_NEGATE: {
      push(-pop());
      break;
    }

    case OP_CONST: {
      Value constant = READ_CONST();
      push(constant);
      break;
    }

    case OP_RETURN: {
      print_value(pop());
      printf("\n");
      return INERPRET_OK;
    }
    }
  }
#undef READ_BYTE
#undef READ_CONST
}

InterpretResult interpret(Chunk *chunk) {
  vm.chunk = chunk;
  vm.ip = chunk->code;
  return run();
}
