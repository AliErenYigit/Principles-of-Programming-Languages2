#ifndef SINEK_H
#define SINEK_H

#include "Canli.h"
#include "Habitat.h"

// Sinek yapısı
typedef struct {
    Canli super;
} Sinek;

// Diğer fonksiyon prototipleri
char* sinek_gorunum(Sinek *);

#endif /* SINEK_H */
