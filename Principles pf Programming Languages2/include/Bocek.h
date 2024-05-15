#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"
#include "Habitat.h"

// Bocek yapısı
typedef struct {
    Canli super;
} Bocek;

// Diğer fonksiyon prototipleri
char* bocek_gorunum(Bocek *);

#endif /* BOCEK_H */
