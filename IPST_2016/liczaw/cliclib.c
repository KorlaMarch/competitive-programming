/*
  Przykladowa biblioteka licytacji dla zawodnikow
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "cliclib.h"

static int n;
static int zainicjowane = 0; // czy zostala juz wywolana funkcja inicjuj
static int stos, stawka;
static int kolej; // aktualny gracz

// Inicjuje gre pomiedzy Alojzym i Bajtazarem
int inicjuj() {
  if (zainicjowane) {
    fprintf(stderr, "ERROR: Reinitialising library :(\n");
    printf("ZLE\n");
    exit(0);
  }
  fprintf(stderr, "Initialize: Enter a value n\n");
  scanf("%d", &n);
  fprintf(stderr, "N = %d\n",n);
  if (n < 1) {
    fprintf(stderr, "ERROR: Invalid value n :(\n");
    printf("ZLE\n");
    exit(0);
  }
  zainicjowane = 1;
  stos = 0;
  stawka = 1;
  kolej = 1;
  return n;
}

// Aktualizuje stos i stawke, biorac pod uwage ruch x
static void wykonaj_ruch(int x) {
  if (x == 1) {
    stos = stos + stawka;
    stawka = 1;
  }
  else if (x == 2) {
    stawka = stawka * 2;
  }
  else if (x == 3) {
    stawka = stawka * 3;
  }
}

// Wykonuje ruch Alojzego
void alojzy(int x) {
  if (!zainicjowane) {
    fprintf(stderr, "ERROR: No initialization library :(\n");
    printf("ZLE\n");
    exit(0);
  }
  if (kolej != 1) {
    fprintf(stderr, "ERROR: Aloysius motion without prior traffic Byteasar :(\n");
    printf("ZLE\n");
    exit(0);
  }
  fprintf(stderr, "Aloysius move\n");
  fprintf(stderr, "The number of pebbles on the stack: %d, the current size of the pot: %d\n", stos, stawka);
  if (stos + stawka >= n) {
    fprintf(stderr, "Win Byteasar - a program player gets 0 points :(\n");
    printf("ZLE\n");
    exit(0);
  }
  if (x < 1 || x > 3) {
    fprintf(stderr, "ERROR: Invalid movement Aloysius :(\n");
    printf("ZLE\n");
    exit(0);
  }
  if (x == 1) fprintf(stderr, "Alojzy pass\n");
  if (x == 2) fprintf(stderr, "Alojzy double\n");
  if (x == 3) fprintf(stderr, "Alojzy triple\n");
  kolej = 2;
  wykonaj_ruch(x);
}

// Generuje i wykonuje ruch Bajtazara
int bajtazar() {
  if (!zainicjowane) {
    fprintf(stderr, "ERROR: The library has not been initialized :(\n");
    printf("ZLE\n");
    exit(0);
  }
  if (kolej != 2) {
    fprintf(stderr, "ERROR: The question of the movement Byteasar before moving Aloysius :(\n");
    printf("ZLE\n");
    exit(0);
  }
  fprintf(stderr, "Bajtazara move\n");
  fprintf(stderr, "The number of pebbles on the stack: %d, the current size of the pot: %d\n", stos, stawka);
  if (stos + stawka >= n) {
    fprintf(stderr, "Bajtazar loss, Alojzy win :)\n");
    printf("OK\n");
    exit(0);
  }
  fprintf(stderr, "What move should perform Byteasar? 1: Pass, 2: Double , 3: Triple ?\n");
  int x;
  scanf("%d", &x);
  if (x < 1 || x > 3) {
    fprintf(stderr, "ERROR: Invalid movement Byteasar :(n");
    printf("ZLE\n");
    exit(0);
  }
  if (x == 1) fprintf(stderr, "Byteasar pass\n");
  if (x == 2) fprintf(stderr, "Byteasar double\n");
  if (x == 3) fprintf(stderr, "Byteasar triple\n");
  kolej = 1;
  wykonaj_ruch(x);
  return x;
}
