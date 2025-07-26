#include "gameboy.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Usage: %s <rom_file>\n", argv[0]);
    printf("Example: %s tetris.gb\n", argv[0]);
    return 1;
  }

  GameBoy gb;
  gameboy_init(&gb, argv[1]);
  gameboy_run(&gb);
  return 0;
}
