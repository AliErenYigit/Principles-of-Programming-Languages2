#include "Pire.h"

char *pire_gorunum(Pire *pire) {
  if (pire->super.alive == 1)
    return "P";
  return "X";
}