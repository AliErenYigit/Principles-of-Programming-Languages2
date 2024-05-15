#include "Sinek.h"

char *sinek_gorunum(Sinek *sinek) {
  if (sinek->super.alive == 1)
    return "S";
  return "X";
}