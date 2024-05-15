#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>
#include "Canli.h"

int main() {

  FILE *dosya = fopen("veriler.txt", "r");
  if (dosya == NULL) {
    printf("Dosya açılamadı.\n");
    return 1;
  }

  int sayi;
  int satir = 0;
  int sutun = 0;
  Habitat *myhabitat = habitat_olustur(10024);
  while (fscanf(dosya, "%d", &sayi) == 1) {
    Canli *canli = belirle_tur(sayi, satir, sutun);
    if (canli != NULL) {
      canli->alive = 1;
      canli->number = sayi;
      myhabitat->canlilar[myhabitat->canli_sayisi] = canli;
      myhabitat->canli_sayisi++;
      // printf("(%d,%d) ", canli->konum.satir, canli->konum.sutun);

    } else {
      printf("Hatalı sayı: %d\n", sayi);
    }

    // Satır sonunda boşluk tespiti yap ve alt satıra geç
    char karakter;
    if (fscanf(dosya, "%c", &karakter) == 1 && karakter == '\n') {
      satir++;   // Satır sayısını artır
      sutun = 0; // Sütun sayısını sıfırla
    } else {
      ungetc(karakter, dosya); // Okunan karakteri geri ver
      sutun++;                 // Sütun sayısını artır
    }
  }

  print_habitat(myhabitat, sutun);
  printf("\n");
  printf("\nSureci baslatmak icin bir tusa basin...\n");
  getchar(); // Bir tuşa basılmasını bekler
  fflush(stdin);

  Canli powerful_canli = *myhabitat->canlilar[0];
  int powerful_index = 0;
  for (int i = 0; i < myhabitat->canli_sayisi; i++) {

    Canli canli2 = *myhabitat->canlilar[i];

    if (isCanEat(canli2, powerful_canli) == 1) {
      myhabitat->canlilar[powerful_index]->alive = 0;
      powerful_canli = canli2;
      powerful_index = i;
    } else if (isCanEat(powerful_canli, canli2) == 1) {
      myhabitat->canlilar[i]->alive = 0;
    }
    system("cls");
    print_habitat(myhabitat, sutun);
    fflush(stdout);
    sleep(1);
  }

  // Kazanan canlının bulunması
  Canli *winner = NULL;
  for (int i = 0; i < myhabitat->canli_sayisi; i++) {
    Canli *current = myhabitat->canlilar[i];
    if (current->alive == 1) {
      // Eğer kazanan henüz belirlenmemişse veya current daha güçlü ise, current kazanan olur
      if (winner == NULL || isCanEat(*current, *winner)) {
        winner = current;
      }
    }
  }

  // Kazananı yazdırma
  if (winner != NULL) {
    print_winner(winner);
  } else {
    printf("\nKazanan yok!\n");
  }

  fclose(dosya);

  return 0;
}
