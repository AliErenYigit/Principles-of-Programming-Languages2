#include "Bocek.h"

char *bocek_gorunum(Bocek *bocek) {
  if (bocek->super.alive == 1)
    return "C";
  return "X";
}