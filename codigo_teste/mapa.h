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

typedef struct MessageWindow MessageWindow;

typedef struct MOB MOB;

typedef struct COORD COORD;

void gerarMundo(int templateRows, int templateCols, MOB *mobs, int num_mobs, STATE *st);

void drawlight(STATE *st, int r, int co);

int mapa_pode_andar (int x, int y);

void endmap(STATE *st, int i, int rows, int cols);

void nextlevel(STATE *st, int i, int rows, int cols, MessageWindow* msg_window, MOB *mobs, int num_mobs);

void gerar_Random_item(int templateRows, int templateCols);

void itemPickUp(STATE *st, int i, MessageWindow* msg_window);

void inventory(int i,int row,int col);

void lightaux(char c, int j, int i);

void lights(int rows, int cols);

#endif
