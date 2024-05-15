#include "Canli.h"
#include "Bitki.h"
#include "Pire.h"
#include "Bocek.h"
#include "Sinek.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>



Canli *belirle_tur(int sayi, int satir, int sutun) {
  if (sayi >= 1 && sayi <= 9) {
    Bitki *bitki = malloc(sizeof(Bitki));
    bitki->super.gorunum = (char *(*)(struct CANLI *))bitki_gorunum;
    bitki->super.konum.satir = satir;
    bitki->super.konum.sutun = sutun;
    return (Canli *)bitki;
  } else if (sayi >= 10 && sayi <= 20) {
    Bocek *bocek = malloc(sizeof(Bocek));
    bocek->super.gorunum = (char *(*)(struct CANLI *))bocek_gorunum;
    bocek->super.konum.satir = satir;
    bocek->super.konum.sutun = sutun;
    return (Canli *)bocek;
  } else if (sayi >= 21 && sayi <= 50) {
    Sinek *sinek = malloc(sizeof(Sinek));
    sinek->super.gorunum = (char *(*)(struct CANLI *))sinek_gorunum;
    sinek->super.konum.satir = satir;
    sinek->super.konum.sutun = sutun;
    return (Canli *)sinek;
  } else if (sayi >= 51 && sayi <= 99) {
    Pire *pire = malloc(sizeof(Pire));
    pire->super.gorunum = (char *(*)(struct CANLI *))pire_gorunum;
    pire->super.konum.satir = satir;
    pire->super.konum.sutun = sutun;
    return (Canli *)pire;
  } else
    return NULL; // Geçersiz sayı
}
double hipotenus(int a, int b) {
  return sqrt(a * a + b * b); // sqrt fonksiyonu double döndürdüğü için dönüş
                              // değeri de double olacaktır
}

int isCanEat(Canli canli1, Canli canli2) {
  char canli1_type = canli1.gorunum(&canli1)[0];
  char canli2_type = canli2.gorunum(&canli2)[0];
  if (canli1_type == 'B' && canli2_type == 'P')
    return 1;
  if (canli1_type == 'B' && canli2_type == 'S')
    return 1;
  if (canli1_type == 'C' && canli2_type == 'B')
    return 1;
  if (canli1_type == 'C' && canli2_type == 'P')
    return 1;
  if (canli1_type == 'S' && canli2_type == 'P')
    return 1;
  if (canli1_type == 'S' && canli2_type == 'C')
    return 1;
  if (canli1_type == canli2_type && canli1.number == canli2.number)
    return hipotenus(canli1.konum.satir, canli1.konum.sutun) <
                   hipotenus(canli2.konum.satir, canli2.konum.sutun)
               ? 1
               : 0;
  if (canli1_type == canli2_type)
    return canli1.number > canli2.number ? 1 : 0;
  return 0;
}
void print_winner(Canli *winner) {
  //printf("\nKazanan Canli :\n");
  printf("\nKazanan: %s", winner->gorunum(winner));
  printf(" (%d,%d)", winner->konum.satir, winner->konum.sutun);
}
