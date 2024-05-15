#ifndef HABITAT_H
#define HABITAT_H

#include "Canli.h"

// Habitat yapısı
typedef struct HABITAT {
  Canli **canlilar; // Habitat içindeki canlılar
  int kapasite;     // Habitatın tutabileceği maksimum canlı sayısı
  int canli_sayisi; // Mevcut canlı sayısı
} Habitat;

// Diğer fonksiyon prototipleri
Habitat* habitat_olustur();
void habitat_temizle(Habitat *);
void print_habitat(Habitat *habitat, int sutun);


#endif /* HABITAT_H */
