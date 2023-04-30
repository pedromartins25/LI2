#ifndef MAPA_H
#define MAPA_H

#include "state.h"

typedef struct STATE STATE;

void gerarMundo(STATE *s, int templateRows, int templateCols);

void drawlight(STATE *st, int r, int co);

int mapa_pode_andar (int x, int y);

void endmap(STATE *st, int i, int rows, int cols);

void nextlevel(STATE *st, int i, int rows, int cols);

#endif
