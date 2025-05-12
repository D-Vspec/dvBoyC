#include "memory.h"
#include <stdio.h>
#include <string.h>

void memory_init(Memory* RAM){
  memset(RAM->data, 0, sizeof(RAM->data));
  printf("Initialized empty RAM\n");
}
