#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "mapa.h"

#define MAX_MOBS 10

void do_movement_action(STATE *st, int dx, int dy) {
int new_x = st->playerX + dx;
int new_y = st->playerY + dy;
  if (mapa_pode_andar(new_x, new_y)) {
	st->playerX += dx;
	st->playerY += dy;
 }
}

void update(STATE *st, MOB *mobs, int num_mobs, int rows, int cols) {
    int key = getch();
    int col=5, row=rows+5;

        attron(COLOR_PAIR(2));
	mvaddch(st->playerX, st->playerY, ' ');
	attroff(COLOR_PAIR(2));
	switch(key) {
		case KEY_A1:
		case '7': endmap(st, 1, rows, cols), nextlevel(st, 1, rows, cols), itemPickUp(st, 1), do_movement_action(st, -1, -1), drawlight(st, rows, cols); break;
		case KEY_UP:
		case '8': endmap(st, 1, rows, cols), nextlevel(st, 1, rows, cols), itemPickUp(st, 1), do_movement_action(st, -1, +0), drawlight(st, rows, cols); break;
		case KEY_A3:
		case '9': endmap(st, 1, rows, cols), nextlevel(st, 1, rows, cols), itemPickUp(st, 1), do_movement_action(st, -1, +1), drawlight(st, rows, cols); break;
		case KEY_LEFT:
		case '4': endmap(st, 3, rows, cols), nextlevel(st, 3, rows, cols), itemPickUp(st, 3), do_movement_action(st, +0, -1), drawlight(st, rows, cols); break;
		case KEY_B2:
		case '5': break;
		case KEY_RIGHT:
		case '6': endmap(st, 4, rows, cols), nextlevel(st, 4, rows, cols), itemPickUp(st, 4), do_movement_action(st, +0, +1), drawlight(st, rows, cols); break;
		case KEY_C1:
		case '1': endmap(st, 2, rows, cols), nextlevel(st, 2, rows, cols), itemPickUp(st, 2), do_movement_action(st, +1, -1), drawlight(st, rows, cols); break;
		case KEY_DOWN:
		case '2': endmap(st, 2, rows, cols), nextlevel(st, 2, rows, cols), itemPickUp(st, 2), do_movement_action(st, +1, +0), drawlight(st, rows, cols); break;
		case KEY_C3:
		case '3': endmap(st, 2, rows, cols), nextlevel(st, 2, rows, cols), itemPickUp(st, 2),do_movement_action(st, +1, +1), drawlight(st, rows, cols); break;
		case 'q': endwin(); exit(0); break;
	}

    // atualiza o estado dos inimigos
    for (int i = 0; i < num_mobs; i++) {
        // verifique se o inimigo está vivo
        if (mobs[i].hp > 0) {
            // verifique se o inimigo está adjacente ao jogador
            if ((abs(mobs[i].x - st->playerX) <= 1) && (abs(mobs[i].y - st->playerY) <= 1)) {
                // inicie uma batalha
                int damage_to_player = mobs[i].atk - st->playerDef;
                int damage_to_mob = st->playerAtk - mobs[i].def;
                if (damage_to_player > 0) {
                    st->playerHp -= damage_to_player;
                }
                if (damage_to_mob > 0) {
                    mobs[i].hp -= damage_to_mob;
                }
            } else {
                // caso contrário, mova o inimigo aleatoriamente
                int dx = rand() % 3 - 1;
                int dy = rand() % 3 - 1;
                if (dx != 0 || dy != 0) {
                    int new_x = mobs[i].x + dx;
                    int new_y = mobs[i].y + dy;
                    if ((pow((st->playerX-new_x),2)+pow((st->playerY-new_y),2))<=36) {
                     attron(COLOR_PAIR(2));
              	     mvaddch(mobs[i].x, mobs[i].y, ' ');
	             attroff(COLOR_PAIR(2));                    
                    }
                    else{ 
                         if (mvinch(new_x, new_y) == '-') {
                           attron(COLOR_PAIR(4));
              	           mvaddch(mobs[i].x, mobs[i].y, '-');
	                   attroff(COLOR_PAIR(4));                   
                         }
                         else {
                              attron(COLOR_PAIR(1));
                     	      mvaddch(mobs[i].x, mobs[i].y, '.');
	                      attroff(COLOR_PAIR(1));                        
                         }
                         }
                    if (mapa_pode_andar(new_x, new_y) && new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                        mobs[i].x = new_x;
                        mobs[i].y = new_y;
                    }
                }
            }
            // renderize o inimigo na tela
            mvaddch(mobs[i].x, mobs[i].y, 'M');
        }
    }
   mvprintw(row, col, "Inventory: ");  // desenha o inventario
   col +=11;
   for (int i = 0; i <= st->len; i++) {
    if (col==cols-8) {
     row += 1; col = 5;
     }
    if (i < st->len) {
    inventory(st->inv[i], row, col);
    col+=1;
    }
 }
} 
   











