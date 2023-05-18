#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <string.h>

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

void update(STATE *st, MOB *mobs, int num_mobs, int rows, int cols, WINDOW *stats_window, MessageWindow *msg_window, int ncols){

    int key = getch();
    WINDOW *inv_window;
    WINDOW *equip_window;

    // Cria a janela do inventário
    inv_window = newwin(10, ncols/3-2, rows+1, 5+(ncols/3-2));
    equip_window = newwin(10, ncols/3-2, rows+1, 5+2*(ncols/3-2)); 

    attron(COLOR_PAIR(2));
    mvaddch(st->playerX, st->playerY, ' ');
    attroff(COLOR_PAIR(2));
    if (st->menu==0) {
    switch(key) {
        case KEY_A1:
        case '7': 
            endmap(st, 1, rows, cols);
            nextlevel(st, 1, rows, cols, msg_window); 
            itemPickUp(st, 1, msg_window); 
            do_movement_action(st, -1, -1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_UP:
        case '8': 
            endmap(st, 1, rows, cols);
            nextlevel(st, 1, rows, cols, msg_window); 
            itemPickUp(st, 1, msg_window); 
            do_movement_action(st, -1, +0); 
            drawlight(st, rows, cols); 
            break;
        case KEY_A3:
        case '9': 
            endmap(st, 1, rows, cols); 
            nextlevel(st, 1, rows, cols, msg_window); 
            itemPickUp(st, 1, msg_window); 
            do_movement_action(st, -1, +1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_LEFT:
        case '4': 
            endmap(st, 3, rows, cols); 
            nextlevel(st, 3, rows, cols, msg_window); 
            itemPickUp(st, 3, msg_window); 
            do_movement_action(st, +0, -1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_B2:
        case '5': 
            break;
        case KEY_RIGHT:
        case '6': 
            endmap(st, 4, rows, cols); 
            nextlevel(st, 4, rows, cols, msg_window); 
            itemPickUp(st, 4, msg_window); 
            do_movement_action(st, +0, +1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_C1:
        case '1': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window); 
            itemPickUp(st, 2, msg_window); 
            do_movement_action(st, +1, -1); 
            drawlight(st, rows, cols); 
            break;
        case KEY_DOWN:
        case '2': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window); 
            itemPickUp(st, 2, msg_window); 
            do_movement_action(st, +1, +0); 
            drawlight(st, rows, cols); 
            break;
        case KEY_C3:
        case '3': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window); 
            itemPickUp(st, 2, msg_window);
            do_movement_action(st, +1, +1); 
            drawlight(st, rows, cols); 
            break;
        case 'q': 
            endwin();
            exit(0); 
            break;
        case 'm':  // abre o inventario e pausa o jogo
            printInventory(st->inv, inv_window, st->n=0, st->m=8);
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
        case 'q':  // fecha o jogo
            endwin();
            exit(0); 
            break;
        case KEY_UP:  // faz scroll para cima do inventario
            if (st->equipPos >= 3) {
             if (st->n > 0) { st->n--; st->m--;
             printInventory(st->inv, inv_window, st->n, st->m);
             printEquip(st->equip, 3, equip_window);
             st->equipPos --;
             mvwprintw(inv_window,3, 1, "%c", '>');
             wrefresh(inv_window);
             }
            }
            break;
        case KEY_DOWN:  // faz scroll para baixo do inventario
            if (st->equipPos <= rows-2) {
             if (st->n < st->len) { st->n++; st->m++;
             printInventory(st->inv, inv_window, st->n, st->m);
             printEquip(st->equip, 3, equip_window);
             st->equipPos ++;
             mvwprintw(inv_window,3, 1, "%c", '>');
             wrefresh(inv_window);
             }
            }
            break;
        case 'e':  // equipa um item
            equipItem(st, msg_window);
            printInventory(st->inv, inv_window, st->n, st->m);
            printEquip(st->equip, 3, equip_window);
            wrefresh(equip_window);
            mvwprintw(inv_window,3, 1, "%c", '>');
            wrefresh(inv_window);
            break;
        case 'd':  // apaga um item
            dropItem(st, msg_window);
            if (st->n > 0) { st->n--; st->m--;
             st->equipPos--;
             printInventory(st->inv, inv_window, st->n, st->m);
             printInventory(st->inv, inv_window, st->n, st->m);
             printEquip(st->equip, 3, equip_window);
             wrefresh(equip_window);
             mvwprintw(inv_window,3, 1, "%c", '>');
             wrefresh(inv_window);
            }
            break;
        case KEY_BACKSPACE:  // fecha a janela do inventario
            wclear(inv_window);
            wrefresh(inv_window);
            wclear(equip_window);
            wrefresh(equip_window);
            refresh();
            st->menu=0;
            break;       
       }
    }
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


// Modifica o item que está equipado e atualiza os stats
void equipItem(STATE *st, MessageWindow* msg_window) {
Item temp;
  if (st->inv[st->equipPos-3].type == 1 || st->inv[st->equipPos-3].type == 2 || st->inv[st->equipPos-3].type == 3) { // no caso de ser uma arma
   st->playerAtk -= st->equip[0].stat; // atualiza os stats
   temp = st->equip[0];
   st->equip[0] = st->inv[st->equipPos-3];
   st->playerAtk += st->equip[0].stat;
   st->inv[st->equipPos-3] = temp;
    // Adicione uma mensagem à janela de mensagens
   const char* message = "Item equipado!            ";
   add_message(msg_window, message);
   
  }
  else {
  if (st->inv[st->equipPos-3].type == 9) { // no caso de ser uma armadura
   st->playerDef -= st->equip[1].stat;
   temp = st->equip[1];
   st->equip[1] = st->inv[st->equipPos-3];  
   st->playerDef += st->equip[1].stat;
   st->inv[st->equipPos-3] = temp;
    // Adicione uma mensagem à janela de mensagens
    const char* message = "Item equipado!            ";
    add_message(msg_window, message);
  }
  else {
  if (st->inv[st->equipPos-3].type == 10) { // no caso de ser um colar
   st->playerHp -= st->equip[2].stat;
   temp = st->equip[2];
   st->equip[2] = st->inv[st->equipPos-3];  
   st->playerHp += st->equip[2].stat;
   st->inv[st->equipPos-3] = temp;
   // Adicione uma mensagem à janela de mensagens
   const char* message = "Item equipado!            ";
   add_message(msg_window, message);
  }
  else {
   // Adicione uma mensagem à janela de mensagens
   const char* message = "Não é possível equipar!";
   add_message(msg_window, message);  
  }
  }
 }
}

void printEquip(Item *equip, int len, WINDOW *equip_window) {

    // Desenha a borda da janela
    box(equip_window, 0, 0);

    // Imprime o título
    mvwprintw(equip_window, 1, 2,"%s", "Equipamento:");

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

void printInventory(Item *inv, WINDOW *inv_window, int n, int m) {
int j=3;
    // Desenha a borda da janela
    box(inv_window, 0, 0);

    // Imprime o título
    mvwprintw(inv_window, 1, 2, "Inventário:");

    // Imprime cada item na janela
    for (int i = n; i < m; i++) {
       if (inv[i].quantity == 0) {
        mvwprintw(inv_window, j, 2,"%s", inv[i].name);
        j++;
       }
       else {
        mvwprintw(inv_window, j, 2, "%s %d", inv[i].name, inv[i].quantity);
        j++;
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

void init_message_window(MessageWindow* msg_window) {
    msg_window->num_messages = 0;
}

void add_message(MessageWindow* msg_window, const char* message) {
    if (msg_window->num_messages <= MAX_MESSAGES) {
     if (msg_window->num_messages > 1) {
        // Move todas as mensagens existentes uma posição para cima
        for (int i = msg_window->num_messages-1; i > 0; i--) {
           if (msg_window->num_messages == MAX_MESSAGES) {
            strcpy(msg_window->messages[i], msg_window->messages[i - 1]);
           }
           else {
            strcpy(msg_window->messages[i+1], msg_window->messages[i]);
            strcpy(msg_window->messages[i], msg_window->messages[i - 1]);
           }
        }
       }
     else {  
      strcpy(msg_window->messages[1], msg_window->messages[0]);
     }
        // Adiciona a nova mensagem na posição 0
        strcpy(msg_window->messages[0], message);

        // Incrementa o número de mensagens, mas garante que não exceda o limite
        msg_window->num_messages++;
        if (msg_window->num_messages > MAX_MESSAGES) {
            msg_window->messages[msg_window->num_messages-1][0]=0;
            msg_window->num_messages = MAX_MESSAGES;
        }
    }
}


void draw_message_window(WINDOW* window, MessageWindow* msg_window, int start_row, int start_col) {
    box(window, 0, 0);

    int row = start_row + 1;
    int col = start_col + 1;

    for (int i = 0; i < msg_window->num_messages; i++) {
        mvwprintw(window, row, col, "%s", msg_window->messages[i]);
        row++;
    }

    wrefresh(window);
}

// Função que apaga um item do inventário
void dropItem(STATE *st, MessageWindow* msg_window) {
int i;
 for (i=st->equipPos; i<st->len; i++) { // apaga o item na posição selecionada
  st->inv[i] = st->inv[i+1];
 }
    strcpy(st->inv[st->len - 1].name, ""); // apaga o item extra final que fica depois de mover o array
    st->inv[st->len - 1].lin = 0;
    st->inv[st->len - 1].cols = 0;
    st->inv[st->len - 1].symbol = '\0';
    st->inv[st->len - 1].stat = 0;
    st->inv[st->len - 1].type = 0;
    st->inv[st->len - 1].quantity = 0;
    st->len--;
   // Adicione uma mensagem à janela de mensagens
   const char* message = "Item Apagado!";
   add_message(msg_window, message);
}



