#ifndef ___STATE_H___
#define ___STATE_H___

#include "mapa.h"

typedef struct {
    int x;
    int y;
    int hp;
    int atk;
    int def;
} MOB;

typedef struct STATE {
    int playerX;
    int playerY;
    int playerHp;
    int playerAtk;
    int playerDef;
    int inv[1000];
    int len;
} STATE;

void do_movement_action(STATE *st, int dx, int dy);
void update(STATE *st, MOB *mobs, int num_mobs, int rows, int cols);

#endif
