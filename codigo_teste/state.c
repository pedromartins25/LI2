#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "mapa.h"



void do_movement_action(STATE *st, int dx, int dy) {

    int new_x = st->playerX + dx;
    int new_y = st->playerY + dy;
    
    if (mapa_pode_andar(new_x, new_y)) {
        st->playerX += dx;
        st->playerY += dy;
 }
}


void update(STATE *st, MOB *mobs, int num_mobs, int rows, int cols, WINDOW *stats_window) {
    
    int key = getch();
    WINDOW *inv_window;
    WINDOW *equip_window;

    // Cria a janela do inventário
    inv_window = newwin(rows - 2, cols/2-2, INV_WINDOW_Y, INV_WINDOW_X);
    equip_window = newwin(rows - 2, cols/2-2, EQUIP_WINDOW_Y, cols/2); 

    lights(rows,cols);
    attron(COLOR_PAIR(2));
    mvaddch(st->playerX, st->playerY, ' ');
    attroff(COLOR_PAIR(2));
    if (st->menu==0) {
    switch(key) {
        case KEY_A1:
        case '7': 
            endmap(st, 1, rows, cols);
            nextlevel(st, 1, rows, cols); 
            itemPickUp(st, 1); 
            do_movement_action(st, -1, -1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_UP:
        case '8': 
            endmap(st, 1, rows, cols);
            nextlevel(st, 1, rows, cols); 
            itemPickUp(st, 1); 
            do_movement_action(st, -1, +0); 
            drawlight(st, rows, cols); 
            break;
        case KEY_A3:
        case '9': 
            endmap(st, 1, rows, cols); 
            nextlevel(st, 1, rows, cols); 
            itemPickUp(st, 1); 
            do_movement_action(st, -1, +1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_LEFT:
        case '4': 
            endmap(st, 3, rows, cols); 
            nextlevel(st, 3, rows, cols); 
            itemPickUp(st, 3); 
            do_movement_action(st, +0, -1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_B2:
        case '5': 
            break;
        case KEY_RIGHT:
        case '6': 
            endmap(st, 4, rows, cols); 
            nextlevel(st, 4, rows, cols); 
            itemPickUp(st, 4); 
            do_movement_action(st, +0, +1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_C1:
        case '1': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols); 
            itemPickUp(st, 2); 
            do_movement_action(st, +1, -1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_DOWN:
        case '2': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols); 
            itemPickUp(st, 2); 
            do_movement_action(st, +1, +0); 
            drawlight(st, rows, cols); 
            break;
        case KEY_C3:
        case '3': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols); 
            itemPickUp(st, 2);
            do_movement_action(st, +1, +1); 
            drawlight(st, rows, cols); 
            break;
        case 'q': 
            endwin();
            exit(0); 
            break;
        case 'm':
            printInventory(st->inv, cols/2-2, inv_window);
            printEquip(st->equip, 3, equip_window);
            st->menu=1;
            mvwprintw(inv_window,3, 1, ">");
            st->equipPos = 3;
            wrefresh(inv_window);
            break;
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
    }
    else {
       switch(key) {
        case 'q': 
            endwin();
            exit(0); 
            break;
        case KEY_UP:
            if (st->equipPos >= 3) {
             printInventory(st->inv, cols/2-2, inv_window);
             printEquip(st->equip, 3, equip_window);
             st->equipPos --;
             mvwprintw(inv_window,st->equipPos, 1, "%c", '>');
             wrefresh(inv_window);
            }
            break;
        case KEY_DOWN:
            if (st->equipPos <= rows-2) {
             printInventory(st->inv, cols/2-2, inv_window);
             printEquip(st->equip, 3, equip_window);
             st->equipPos ++;
             mvwprintw(inv_window,st->equipPos, 1, "%c", '>');
             wrefresh(inv_window);
            }
            break;
        case 'e':
            equipItem(st);
            printInventory(st->inv, cols/2-2, inv_window);
            printEquip(st->equip, 3, equip_window);
            wrefresh(equip_window);
            mvwprintw(inv_window,st->equipPos, 1, "%c", '>');
            wrefresh(inv_window);
            break;
        case KEY_BACKSPACE:
            wclear(inv_window);
            wrefresh(inv_window);
            wclear(equip_window);
            wrefresh(equip_window);
            refresh();
            st->menu=0;
            break;       
       }
    }
            lights(rows,cols);
            update_stats_window(stats_window, st);
}



void update_stats_window(WINDOW *stats_window, STATE *st) {
    wclear(stats_window); // limpa a janela antes de atualizar

    // adiciona os stats do player à janela
    wattron(stats_window, COLOR_PAIR(STATS));
    mvwprintw(stats_window, 1, 1, "HP: %d", st->playerHp);
    mvwprintw(stats_window, 2, 1, "ATK: %d", st->playerAtk);
    mvwprintw(stats_window, 3, 1, "DEF: %d", st->playerDef);
    wattroff(stats_window, COLOR_PAIR(STATS));

    wrefresh(stats_window); // atualiza a janela na tela
}

void equipItem(STATE *st) {
Item temp;
  if (st->inv[st->equipPos-3].type == 1 || st->inv[st->equipPos-3].type == 2 || st->inv[st->equipPos-3].type == 3) {
   st->playerAtk -= st->equip[0].stat;
   temp = st->equip[0];
   st->equip[0] = st->inv[st->equipPos-3];
   st->playerAtk += st->equip[0].stat;
   st->inv[st->equipPos-3] = temp;
  }
  if (st->inv[st->equipPos-3].type == 9) {
   st->playerDef -= st->equip[1].stat;
   temp = st->equip[1];
   st->equip[1] = st->inv[st->equipPos-3];  
   st->playerDef += st->equip[1].stat;
   st->inv[st->equipPos-3] = temp;
  }
  if (st->inv[st->equipPos-3].type == 10) {
   st->playerHp -= st->equip[2].stat;
   temp = st->equip[2];
   st->equip[2] = st->inv[st->equipPos-3];  
   st->playerHp += st->equip[2].stat;
   st->inv[st->equipPos-3] = temp;
  }
  if (st->inv[st->equipPos-3].type == 6) {
   if 
  }
}

void printEquip(Item *equip, int len, WINDOW *equip_window) {

    // Desenha a borda da janela
    box(equip_window, 0, 0);

    // Imprime o título
    mvwprintw(equip_window, 1, 2, "Equipamento:");

    // Imprime cada item na janela
    for (int i = 0; i < len; i++) {
       if (i==0) {
        mvwprintw(equip_window, i + 3, 2,"%s%s","Arma: ", equip[i].name);
       }
       if (i==1) {
        mvwprintw(equip_window, i + 3, 2,"%s%s","Armadura: ", equip[i].name);
       }
       if (i==2) {
        mvwprintw(equip_window, i + 3, 2,"%s%s","Colar: ", equip[i].name);
       }
    }

    // Atualiza a janela na tela
    wrefresh(equip_window);

}

void printInventory(Item *inv, int len, WINDOW *inv_window) {

    // Desenha a borda da janela
    box(inv_window, 0, 0);

    // Imprime o título
    mvwprintw(inv_window, 1, 2, "Inventário:");

    // Imprime cada item na janela
    for (int i = 0; i < len; i++) {
       if (inv[i].quantity == 0) {
        mvwprintw(inv_window, i + 3, 2,"%s", inv[i].name);
       }
       else {
        mvwprintw(inv_window, i + 3, 2, "%s %d", inv[i].name, inv[i].quantity);
       }
    }

    // Atualiza a janela na tela
    wrefresh(inv_window);

}

void addItem(Item *inv, int *len, Item newItem) {
    // Adiciona o novo item na próxima posição vazia do inventário
    inv[*len] = newItem;
    (*len)++;
}
