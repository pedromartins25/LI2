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

//#define INV_WINDOW_X 31
//#define INV_WINDOW_Y 20
#define EQUIP_WINDOW_Y 1

#define MAX_INVENTORY_SIZE 20 // Tamanho máximo do inventário

#define MAX_MESSAGES 7 // Máximo de mensagens na janela

typedef struct {
    char name[20];
    int lin, cols;
    char symbol;
    int stat;
    int type;
    int quantity;
} Item;

typedef struct  COORD{
    int x;
    int y;
} COORD;

typedef struct MOB {
    char name[20];
    int x;
    int y;
    int hp;
    int atk;
    int def;
    char symbol;
    bool seen;
    bool dark;
} MOB;

typedef struct STATE {
    int playerX;
    int playerY;
    int playerHp;
    int playerAtk;
    int playerDef;
    Item inv[1000];
    Item equip[3];
    int n, m;
    int equipPos;
    int len;
    int menu;
    int level;
} STATE;

typedef struct MessageWindow {
    char messages[MAX_MESSAGES][80];
    int num_messages;
} MessageWindow;


void do_movement_action(STATE *st, MOB *mobs, int num_mobs, int dx, int dy, MessageWindow* msg_window);
void update(STATE *st, MOB *mobs, int num_mobs, int rows, int cols, WINDOW *stats_window, MessageWindow *msg_window, int ncols);
void update_stats_window(WINDOW *stats_window, STATE *st);
void printInventory(Item *inv,  WINDOW *inv_window, int n, int m);
void addItem(Item *inv, int *len, Item newItem);
void printEquip(Item *equip, int len, WINDOW *equip_window);
void equipItem(STATE *st, MessageWindow* msg_window);
void init_message_window(MessageWindow* msg_window);
void add_message(MessageWindow* msg_window, const char* message);
void draw_message_window(WINDOW* window, MessageWindow* msg_window, int start_row, int start_col);
void dropItem(STATE *st, MessageWindow* msg_window);




//COMBATE
int is_enemy_adjacent_to_player(const MOB *enemy, int playerX, int playerY);
void update_enemy_states(STATE *st, MOB *mobs, int num_mobs, int rows, int cols, MessageWindow* msg_window);
void player_attack(STATE *st, MOB *mob, MessageWindow* msg_window);
void draw_mob(MOB mob, int playerX, int playerY);
void draw_prevMob(int x, int y, int n);

void remove_mob(MOB *mobs, int *num_mobs, int index);
void attack_mob(STATE *st, MOB *mob, MessageWindow* msg_window);
COORD generateRandomCoords(int rows, int cols); // coordenadas aleatórias mobs


void zombie_persegue(STATE *st, MOB *zombie, int rows, int cols);

void gameOver();
#endif
