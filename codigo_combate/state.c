#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "state.h"
#include "mapa.h"


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
            do_movement_action(st, mobs, num_mobs,-1, -1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_UP:
        case '8': 
            endmap(st, 1, rows, cols);
            nextlevel(st, 1, rows, cols, msg_window); 
            itemPickUp(st, 1, msg_window); 
            do_movement_action(st, mobs, num_mobs,-1, +0, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_A3:
        case '9': 
            endmap(st, 1, rows, cols); 
            nextlevel(st, 1, rows, cols, msg_window); 
            itemPickUp(st, 1, msg_window); 
            do_movement_action(st, mobs, num_mobs,-1, +1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_LEFT:
        case '4': 
            endmap(st, 3, rows, cols); 
            nextlevel(st, 3, rows, cols, msg_window); 
            itemPickUp(st, 3, msg_window); 
            do_movement_action(st, mobs, num_mobs,+0, -1, msg_window); 
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
            do_movement_action(st, mobs, num_mobs,+0, +1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_C1:
        case '1': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window); 
            itemPickUp(st, 2, msg_window); 
            do_movement_action(st, mobs, num_mobs,+1, -1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_DOWN:
        case '2': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window); 
            itemPickUp(st, 2, msg_window); 
            do_movement_action(st, mobs, num_mobs,+1, +0, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_C3:
        case '3': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window); 
            itemPickUp(st, 2, msg_window);
            do_movement_action(st, mobs, num_mobs,+1, +1, msg_window); 
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
            // Atualiza o estado dos inimigos
        update_enemy_states(st, mobs, num_mobs, rows, cols, msg_window); 
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


void do_movement_action(STATE *st, MOB *mobs, int num_mobs, int dx, int dy, MessageWindow* msg_window) {
    int new_x = st->playerX + dx;
    int new_y = st->playerY + dy;

    // Procura a mob na nova posição
    int mob_index = -1;
    for (int i = 0; i < num_mobs; i++) {
        MOB mob = mobs[i];
        if (mob.x == new_x && mob.y == new_y) {
            mob_index = i;
            break;
        }
    }

    // Se houver uma mob na nova posição, ataca a mob específica
    if (mob_index != -1) {
        MOB *mob = &mobs[mob_index];
        attack_mob(st, mob, msg_window);

        // Verifica se a mob foi derrotada
        if (mob->hp <= 0) {
            // Remove a mob do jogo
            remove_mob(mobs, &num_mobs, mob_index);
        }
    }

    // Verifica se o jogador pode se mover
    if (mapa_pode_andar(new_x, new_y)) {
        st->playerX += dx;
        st->playerY += dy;
    }
}


// Função para atacar uma mob
void attack_mob(STATE *st, MOB *mob, MessageWindow* msg_window) {
    // Reduz a vida da mob com base no ataque do jogador
    int dano;
    char message[100]; 
    dano = st->playerAtk - mob->def;
    mob->hp -= dano;
    if (mob->hp <= 0) { // Verifica se a vida da mob é menor ou igual a 0
        snprintf(message, sizeof(message), "A mob foi derrotada.\n");
        mob->hp = 0;
    }
    else {
        snprintf(message, sizeof(message), "Causaste %d de dano.\n", dano); 
    
    // Adiciona a mensagem à janela de mensagens
    add_message(msg_window, message);
       snprintf(message, sizeof(message), "Vida restante da mob: %d\n", mob->hp);
    
    // Adiciona a mensagem à janela de mensagens
    add_message(msg_window, message);
   }
}


// Função para remover uma mob da lista de mobs
void remove_mob(MOB *mobs, int *num_mobs, int index) {
    // Move as mobs restantes para preencher o espaço da mob removida
    for (int i = index; i < *num_mobs - 1; i++) {
        mobs[i] = mobs[i + 1];
    }
    (*num_mobs)--;
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

void mobAttack(STATE *st, MOB *mob, MessageWindow* msg_window) {
    int damage_to_player = mob->atk - st->playerDef;
    if (damage_to_player > 0) {
        st->playerHp -= damage_to_player;

    // Cria uma mensagem com o dano causado pela mob
    char message[100];
    snprintf(message, sizeof(message), "A mob causou %d de dano.", damage_to_player);

    // Adiciona a mensagem à janela de mensagens
    add_message(msg_window, message);

    }
}

int is_enemy_adjacent_to_player(const MOB *enemy, int playerX, int playerY) {
    return abs(enemy->x - playerX) <= 1 && abs(enemy->y - playerY) <= 1;
}




void update_enemy_states(STATE *st, MOB *mobs, int num_mobs, int rows, int cols, MessageWindow* msg_window) {
    for (int i = 0; i < num_mobs; i++) {
        // Verifica se o inimigo está vivo
        if (mobs[i].hp > 0) {
            // Verifica se o inimigo está adjacente ao jogador
            if (is_enemy_adjacent_to_player(&mobs[i], st->playerX, st->playerY)) {
                mobAttack(st, &mobs[i], msg_window);
                st->playerHp -= mobs[i].atk;
            } else {
                // Caso contrário, move o inimigo aleatoriamente
                int dx = rand() % 3 - 1;
                int dy = rand() % 3 - 1;
                int new_x = mobs[i].x + dx;
                int new_y = mobs[i].y + dy;

                // Verifica se o novo local está dentro dos limites do mapa
                if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                    // Apaga o caractere na posição anterior
                    mvaddch(mobs[i].x, mobs[i].y, ' ');

                    // Verifica se o novo local está dentro da distância permitida do jogador
                    if (is_enemy_adjacent_to_player(&mobs[i], st->playerX, st->playerY)) {
                        attron(COLOR_PAIR(2));
                        mvaddch(mobs[i].x, mobs[i].y, ' ');
                        attroff(COLOR_PAIR(2));
                    } else if (mvinch(new_x, new_y) == '-') {
                        attron(COLOR_PAIR(4));
                        mvaddch(mobs[i].x, mobs[i].y, '-');
                        attroff(COLOR_PAIR(4));
                    } else {
                        attron(COLOR_PAIR(1));
                        mvaddch(mobs[i].x, mobs[i].y, '.');
                        attroff(COLOR_PAIR(1));
                    }

                    if (mapa_pode_andar(new_x, new_y)) {
                        mobs[i].x = new_x;
                        mobs[i].y = new_y;
                    }
                }
            }

            // Renderiza o inimigo na tela
            draw_mob(mobs[i], st->playerX, st->playerY);
        }
    }
}

void draw_mob(MOB mob, int playerX, int playerY) {
    int distance = sqrt(pow(mob.x - playerX, 2) + pow(mob.y - playerY, 2));

    if (distance <= 6) {
        attron(COLOR_PAIR(18));  // mob visível - cor preta
        mvaddch(mob.x, mob.y, mob.symbol);
        attroff(COLOR_PAIR(18));
        mob.seen = true; // Marca a MOB como vista
    } else if (mob.seen) {
        attron(COLOR_PAIR(4));  // mob não visível, mas já foi vista - cor cinza
        mvaddch(mob.x, mob.y, mob.symbol);
        attroff(COLOR_PAIR(4));
    } else {
        attron(COLOR_PAIR(17));  // mob não visível e nunca foi vista - cor branca
        mvaddch(mob.x, mob.y, mob.symbol);
        attroff(COLOR_PAIR(1));
    }
}


COORD generateRandomCoords(int rows, int cols) {
    COORD coords;
    coords.x = rand() % rows;
    coords.y = rand() % cols;
    return coords;
}





































































void gameOver() {
    clear();  // Limpa a tela
    refresh();

    // Cria uma nova janela para exibir "Game Over" em tamanho grande
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    WINDOW* game_over_win = newwin(rows, cols, 0, 0);

    // Configura as cores
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1) | A_BOLD);

    // Centraliza a mensagem "Game Over" na janela
    int x = (cols - 9) / 2;
    int y = rows / 2;

    mvwprintw(game_over_win, y, x, "Game Over");

    // Atualiza a janela e aguarda um tempo antes de encerrar o jogo
    wrefresh(game_over_win);
    napms(2000);  // Aguarda 2 segundos

    // Limpa a janela e libera a memória
    delwin(game_over_win);
    endwin();
    exit(0);  // Encerra o programa
}




