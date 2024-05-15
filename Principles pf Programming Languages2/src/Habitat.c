#include "Habitat.h"
#include <stdlib.h>
#include <stdio.h>

Habitat *habitat_olustur(int kapasite) {
  Habitat *habitat = malloc(sizeof(Habitat));
  habitat->kapasite = kapasite;
  habitat->canlilar = malloc(kapasite * sizeof(Canli *));
  habitat->canli_sayisi = 0;
  return habitat;
}

// Habitat temizleme fonksiyonu
void habitat_temizle(Habitat *habitat) {
    for (int i = 0; i < habitat->canli_sayisi; ++i) {
        free(habitat->canlilar[i]);
    }
	  free(habitat->canlilar);
    free(habitat);
}
void print_habitat(Habitat *habitat, int sutun) {
  for (int i = 0; i < habitat->canli_sayisi; ++i) {
    if (i % sutun == 0)
      printf("\n");
    printf("%s ", habitat->canlilar[i]->gorunum(habitat->canlilar[i]));
  }
}
