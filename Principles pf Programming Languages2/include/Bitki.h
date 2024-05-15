#ifndef BITKI_H
#define BITKI_H

#include "Canli.h"
#include "Habitat.h"

// Bitki yapısı
typedef struct {
    Canli super;
} Bitki;

// Diğer fonksiyon prototipleri
char* bitki_gorunum(Bitki *);

#endif /* BITKI_H */
