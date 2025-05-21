#include "gameboy.h"
#include <stdio.h>

int main(){
  GameBoy gb;
  gameboy_init(&gb);
  gameboy_run(&gb);
  return 0;
}
