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


//STRUCTS
typedef struct STATE STATE;
typedef struct MessageWindow MessageWindow;
typedef struct MOB MOB;
typedef struct COORD COORD;



//MAPAS
void gerarMundo(int templateRows, int templateCols, MOB *mobs, int num_mobs, STATE *st);
void endmap(STATE *st, int i, int rows, int cols);
void nextlevel(STATE *st, int i, int rows, int cols, MessageWindow* msg_window, MOB *mobs, int num_mobs);
int mapa_pode_andar (int x, int y);


//ITENS E INVENTARIO
void gerar_Random_item(int templateRows, int templateCols);
void itemPickUp(STATE *st, int i, MessageWindow* msg_window);
void inventory(int i,int row,int col);

//ILUMINAÇÃO
void lightaux(char c, int j, int i);
void lights(int rows, int cols);
void drawlight(STATE *st, int r, int co);

//BOSS
void update_boss_state(STATE *st, MOB *boss, int rows, int cols, MessageWindow* msg_window);
void bossLevel(STATE *st, int rows,int cols, MOB *mobs, int num_mobs, MessageWindow* msg_window);

#endif
