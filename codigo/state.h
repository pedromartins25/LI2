#ifndef ___STATE_H___
#define ___STATE_H___
    

/**
 *
 * Falta muita coisa, incluindo por exemplo:
 * - o mapa
 * - os monstros
 * - a fila de prioridade para saber quem se move
 * - o que está em cada casa
 *
 */
typedef struct {
    int x;
    int y;
    int hp;
    int atk;
    int def;
} MOB;

typedef struct state {
    int playerX;
    int playerY;
} STATE;


void do_movement_action(STATE *st, int dx, int dy);
void update(STATE *st, MOB *mobs, int num_mobs);

#endif
