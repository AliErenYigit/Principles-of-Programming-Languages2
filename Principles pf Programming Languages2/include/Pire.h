#ifndef PIRE_H
#define PIRE_H

#include "Canli.h"
#include "Habitat.h"

// Pire yapısı
typedef struct {
    Canli super;
} Pire;

// Diğer fonksiyon prototipleri
char* pire_gorunum(Pire *);

#endif /* PIRE_H */
