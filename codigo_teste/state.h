#ifndef ___STATE_H___
#define ___STATE_H___

#include "mapa.h"

#define MAX_MOBS 10
#define TEMPLATE_SIZE 10
#define DARKFLOOR 8
#define FLOOR 11
#define WALL 10
#define DARKWALL 9
#define STATS 12


#define INV_WINDOW_WIDTH 20
#define INV_WINDOW_HEIGHT 10
#define INV_WINDOW_X 1
#define INV_WINDOW_Y (LINES - INV_WINDOW_HEIGHT - 1)

#define MAX_INVENTORY_SIZE 20 // Tamanho máximo do inventário

typedef struct {
    char name[20];
    int lin, cols;
    char symbol;
    int type;
    int quantity;
} Item;


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
    Item inv[1000];
    int len;
} STATE;

void do_movement_action(STATE *st, int dx, int dy);
void update(STATE *st, MOB *mobs, int num_mobs, int rows, int cols);
void update_stats_window(WINDOW *stats_window, STATE *st);
void printInventory(Item *inv, int len);
void addItem(Item *inv, int *len, Item newItem);

#endif
