#include "Bitki.h"

char *bitki_gorunum(Bitki *bitki) {
  if (bitki->super.alive == 1)
    return "B";
  return "X";
}