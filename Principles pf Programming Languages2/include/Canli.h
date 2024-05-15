#ifndef CANLI_H
#define CANLI_H

typedef struct CANLI Canli;
typedef struct SatirSutun SatirSutun;
typedef struct HABITAT Habitat;

// Gerekli diğer başlık dosyaları
#include "Habitat.h"

typedef struct SatirSutun {
    int satir;
    int sutun;
} SatirSutun;
// Canlı yapısı
typedef struct CANLI {
  char *(*gorunum)(struct CANLI *); // Görünüm fonksiyon göstericisi
  SatirSutun konum;                 // Konum bilgisi
  struct HABITAT *habitat;          // Canlının bulunduğu habitat
  int alive; // Canlının hayatta olup olmadığını belirten bayrak
  int number;
} Canli;

// Diğer fonksiyon prototipleri
Canli* belirle_tur(int, int, int);
double hipotenus(int a, int b);
int isCanEat(Canli canli1, Canli canli2);
void print_winner(Canli *winner);

#endif /* CANLI_H */
