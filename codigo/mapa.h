#ifndef MAPA_H
#define MAPA_H

#include "state.h"

#define N_MAXIMO_ITEMS 20
#define MAX_MOBS 10
#define TEMPLATE_SIZE 10
#define DARKFLOOR 8
#define FLOOR 11
#define WALL 10
#define DARKWALL 9
#define STATS 12


typedef struct STATE STATE;

typedef struct {
    int lin, cols;
    char symbol;
} Item;


void gerarMundo(int templateRows, int templateCols);

void drawlight(STATE *st, int r, int co);

int mapa_pode_andar (int x, int y);

void endmap(STATE *st, int i, int rows, int cols);

void nextlevel(STATE *st, int i, int rows, int cols);

void gerar_Random_item(int templateRows, int templateCols);

void itemPickUp(STATE *st, int i);

void inventory(int i,int row,int col);


#endif
