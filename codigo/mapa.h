#ifndef MAPA_H
#define MAPA_H

#include "state.h"


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
