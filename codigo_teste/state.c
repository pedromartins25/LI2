#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "state.h"
#include "mapa.h"


char messaget[100]; 


/** a93617 Pedro Martins a104444 João Serrão
 * Uma das funções principais, contem as teclas e todas as funcionalidades, atualização dos inimigos(mobs), atualização da janela
 *  de status, etc.
 */ 
void update(STATE *st, MOB *mobs, int num_mobs, int rows, int cols, WINDOW *stats_window, MessageWindow *msg_window, int ncols){ 

    int key = getch();
    int l = 0;
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
            nextlevel(st, 1, rows, cols, msg_window, mobs, num_mobs); 
            itemPickUp(st, 1, msg_window); 
            do_movement_action(st, mobs, num_mobs,-1, -1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_UP:
        case '8': 
            endmap(st, 1, rows, cols);
            nextlevel(st, 1, rows, cols, msg_window, mobs, num_mobs); 
            itemPickUp(st, 1, msg_window); 
            do_movement_action(st, mobs, num_mobs,-1, +0, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_A3:
        case '9': 
            endmap(st, 1, rows, cols); 
            nextlevel(st, 1, rows, cols, msg_window, mobs, num_mobs); 
            itemPickUp(st, 1, msg_window); 
            do_movement_action(st, mobs, num_mobs,-1, +1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_LEFT:
        case '4': 
            endmap(st, 3, rows, cols); 
            nextlevel(st, 3, rows, cols, msg_window, mobs, num_mobs); 
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
            nextlevel(st, 4, rows, cols, msg_window, mobs, num_mobs); 
            itemPickUp(st, 4, msg_window); 
            do_movement_action(st, mobs, num_mobs,+0, +1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_C1:
        case '1': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window, mobs, num_mobs); 
            itemPickUp(st, 2, msg_window); 
            do_movement_action(st, mobs, num_mobs,+1, -1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_DOWN:
        case '2': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window, mobs, num_mobs); 
            itemPickUp(st, 2, msg_window); 
            do_movement_action(st, mobs, num_mobs,+1, +0, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case KEY_C3:
        case '3': 
            endmap(st, 2, rows, cols); 
            nextlevel(st, 2, rows, cols, msg_window, mobs, num_mobs); 
            itemPickUp(st, 2, msg_window);
            do_movement_action(st, mobs, num_mobs,+1, +1, msg_window); 
            drawlight(st, rows, cols); 
            break;
        case 'r':
            if (st->playerHp < 100) {
            st->playerHp += 1;  // Regenera a vida do jogador
               if (st->playerHp > 100) {
                st->playerHp = 100;
            }
            do_movement_action(st, mobs, num_mobs,0, 0, msg_window);
            snprintf(messaget, sizeof(messaget), "Regeneraste 1 de vida ao descansar.       ");
            
        }
        else snprintf(messaget, sizeof(messaget), "Não consegues regenerar mais      ");
        add_message(msg_window,messaget);
            break;
        case 'q': 
            endwin();
            exit(0); 
            break;
        case 'm':  // abre o inventario e pausa o jogo
            printInventory(st->inv, inv_window, st->n=0, st->m=7);
            printEquip(st->equip, 3, equip_window);
            st->menu=1;
            mvwprintw(inv_window,3, 1, ">");
            st->equipPos = 3;
            wrefresh(inv_window);
            break;
        case ERR:
          update_enemy_states(st, mobs, num_mobs, rows, cols, msg_window);
          l = 1; 
          break;
    }


            // Atualiza o estado dos inimigos
       if (l == 0) {
        update_enemy_states(st, mobs, num_mobs, rows, cols, msg_window); 
       }
       else l = 0;
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
            lights(rows,cols);  // ilumina as tochas
            update_stats_window(stats_window, st);
}


/** A93617 Pedro Martins 
 * Movimento do jogador com procura de mobs e realização de ataques caso esteja perto
*/
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


/** A93617 Pedro Martins 
 * Função para realizar o ataque do jogador à mob
 */
void attack_mob(STATE *st, MOB *mob, MessageWindow* msg_window) {
    // Reduz a vida da mob com base no ataque do jogador
    int dano;
    char message[100]; 
    dano = st->playerAtk - mob->def;

    if (dano <= 1){
        dano = 1 ;
        snprintf(message, sizeof(messaget), "Ainda estás muito fraco, causaste 1 de dano.");
    }

    mob->hp -= dano;
    if (mob->hp <= 0) { // Verifica se a vida da mob é menor ou igual a 0
        snprintf(message, sizeof(messaget), "%s foi derrotado.\n", mob->name);
        mob->hp = 0;

    }

    else {
        snprintf(message, sizeof(messaget), "Causaste %d de dano             ", dano); 
    
   }

   add_message(msg_window, message);
   snprintf(message, sizeof(messaget), "Hp de %s: %d\n        ", mob->name, mob->hp); 
   add_message(msg_window, message);
}

/* A93617 Pedro Martins
*Função para remover uma mob da lista de mobs
*/
void remove_mob(MOB *mobs, int *num_mobs, int index) { 
        attron(COLOR_PAIR(2));
        mvaddch(mobs[index].x, mobs[index].y, ' ');
        attroff(COLOR_PAIR(2));  
    // Move as mobs restantes para preencher o espaço da mob removida
    for (int i = index; i < *num_mobs - 1; i++) {
        mobs[i] = mobs[i + 1];
    }
    (*num_mobs)--;
}

/**A93617 Pedro Martins 
 * Atualização da janela dos stats
 */
void update_stats_window(WINDOW *stats_window, STATE *st) { 
    wclear(stats_window); // Limpa a janela antes de atualizar

    // Adiciona os stats do player à janela
    mvwprintw(stats_window, 1, 1, "HP ");
    wattron(stats_window, COLOR_PAIR(19)); // Define a cor para HP
    mvwprintw(stats_window, 2, 1, "%d", st->playerHp);
    wattroff(stats_window, COLOR_PAIR(19)); // Desativa a cor para HP

    mvwprintw(stats_window, 4, 1, "ATK");
    wattron(stats_window, COLOR_PAIR(21)); // Define a cor para ATK
    mvwprintw(stats_window, 5, 1, "%d ", st->playerAtk);
    wattroff(stats_window, COLOR_PAIR(20)); // Desativa a cor para ATK

    mvwprintw(stats_window, 7, 1, "DEF");
    wattron(stats_window, COLOR_PAIR(20)); // Define a cor para DEF
    mvwprintw(stats_window, 8, 1, "%d ", st->playerDef);
    wattroff(stats_window, COLOR_PAIR(20)); // Desativa a cor para DEF

    wrefresh(stats_window); // Atualiza a janela na tela
}


/** A104444 João Serrão
 *  Modifica o item que está equipado e atualiza os stats
 */

void equipItem(STATE *st, MessageWindow* msg_window) {
Item temp;
  if (st->inv[st->equipPos-3].type == 1 || st->inv[st->equipPos-3].type == 2 || st->inv[st->equipPos-3].type == 3) { // no caso de ser uma arma
   st->playerAtk -= st->equip[0].stat; // atualiza os stats
   temp = st->equip[0];
   st->equip[0] = st->inv[st->equipPos-3];
   st->playerAtk += st->equip[0].stat;
   st->inv[st->equipPos-3] = temp;
    // Adicione uma mensagem à janela de mensagens
   const char* message = "Item equipado!              ";
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
    const char* message = "Item equipado!              ";
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
   const char* message = "Item equipado!               ";
   add_message(msg_window, message);
  }
  else {
   if (st->inv[st->equipPos-3].type == 7 && st->inv[st->equipPos-3].quantity > 0) {
    if (st->playerHp + st->inv[st->equipPos-3].stat >= 100+st->equip[2].stat) {
     st->playerHp = 100+st->equip[2].stat;
    }
    else {
     st->playerHp += st->inv[st->equipPos-3].stat;
    }
    st->inv[st->equipPos-3].quantity --;
    // Adicione uma mensagem à janela de mensagens
    snprintf(messaget, sizeof(messaget), "Curado!            \n");
    add_message(msg_window, messaget); 
   }
   else {
    // Adicione uma mensagem à janela de mensagens
    const char* message = "Não é possível equipar!\n             ";
    add_message(msg_window, message);  
   }
  }
  }
 }
}

/** A104444 João Serrão
 *  Impressão da janela do equipamento
 */

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


/** A104444 João Serrão
 *  Impressão da janela do inventário
 */

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


/** A104444 João Serrão
 *   Adiciona um novo item na próxima posição vazia do inventário
 */
void addItem(Item *inv, int *len, Item newItem) {
    inv[*len] = newItem;
    (*len)++;
}


/** A93617 Pedro Martins 
 * Inicialização da janela de mensagens
 */
void init_message_window(MessageWindow* msg_window) {
    msg_window->num_messages = 0;
}



/** A93617 Pedro Martins 
 * Função para adicionar uma mensagem à janela de mensagens
 */
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



/** A93617 Pedro Martins 
 * Função para desenhar a janela de mensagens
 */
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


/** A104444 João Serrão 
 * Função que apaga um item do inventário
 */
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
   const char* message = "Item Apagado!             ";
   add_message(msg_window, message);
}



/** A93617 Pedro Martins
 * Função para realizar o ataque da mob
 */
void player_attack(STATE *st, MOB *mob, MessageWindow* msg_window) {
    int damage_to_player = mob->atk - st->playerDef;
    if (damage_to_player > 0) {
        st->playerHp -= damage_to_player;

    // Cria uma mensagem com o dano causado pela mob
    char message[100];
    snprintf(message, sizeof(messaget), "%s causou %d de dano.                      ", mob-> name,damage_to_player);

    // Adiciona a mensagem à janela de mensagens
    add_message(msg_window, message);

    }
}

/** A93617 Pedro Martins
 * Função para calcular a distancia entre o jogador e a mob
 */
int is_enemy_adjacent_to_player(const MOB *enemy, int playerX, int playerY) {
    return abs(enemy->x - playerX) <= 1 && abs(enemy->y - playerY) <= 1;
}


/** A93617 Pedro Martins
 * A104444 João Serrão
 * Atualização do estado das mobs, para atacar, para perseguir, feitiços do boss
 */
void update_enemy_states(STATE *st, MOB *mobs, int num_mobs, int rows, int cols, MessageWindow* msg_window) {
    for (int i = 0; i < num_mobs; i++) {
        int px = mobs[i].x;
        int py = mobs[i].y;
        int n = 0;

        // Verifica se o inimigo está vivo
        if (mobs[i].hp > 0) {
            // Verifica se o inimigo está adjacente ao jogador
            if (is_enemy_adjacent_to_player(&mobs[i], st->playerX, st->playerY)) {
                player_attack(st, &mobs[i], msg_window);
            }
            else if ((abs(mobs[i].x - st->playerX) <= 3 && abs(mobs[i].y - st->playerY) <= 3) && (mobs[i].symbol == '&')) {
                zombie_persegue(st, &mobs[i], rows, cols);
            }
            else if ((abs(mobs[i].x - st->playerX) <= 3 && abs(mobs[i].y - st->playerY) <= 3) && (mobs[i].symbol == 'B')) {
                if (rand() % 100 < 10) {  // 10% de probabilidade
                    snprintf(messaget, sizeof(messaget), "%s atirou um feitiço!", mobs[i].name);
                    add_message(msg_window, messaget);
                    player_attack(st, &mobs[i], msg_window);
                }
            }
            else {
                // Caso contrário, move o inimigo aleatoriamente
                int dx = rand() % 3 - 1;
                int dy = rand() % 3 - 1;
                int new_x = mobs[i].x + dx;
                int new_y = mobs[i].y + dy;
                
                char c = mvinch(new_x, new_y);
                // Verifica se o novo local está dentro dos limites do mapa
                if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                    if (c == '.' || c == 'h' || (c != '-' && c != '+' && c != ' ' && c != 'H' && c != '@')) {
                        n = 1;
                        mobs[i].dark = true;
                    }
                    else if (c == '-' || c == '+') {
                        n = 2;
                        mobs[i].dark = false;
                    }
                    else if (c == ' ' || c == 'H' || c == '@') {
                        n = 3;
                        mobs[i].seen = true; // Marca a MOB como vista
                    }
                    
                    draw_prevMob(px, py, n);

                    // Verifica se o novo local está dentro da distância permitida do jogador
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

/** A104444 João Serrão
 * Correção da cor do piso depois da mobs se mover.
 */
void draw_prevMob(int x, int y, int n) {
  if (n == 1) {
        attron(COLOR_PAIR(1)); 
        mvaddch(x, y, '.');  
        attroff(COLOR_PAIR(1)); 
  }
  else if (n == 2) {
        attron(COLOR_PAIR(4));
        mvaddch(x, y, '-');
        attroff(COLOR_PAIR(4));  
  }
  else {
       if (n==3) {
        attron(COLOR_PAIR(2));
        mvaddch(x, y, ' ');
        attroff(COLOR_PAIR(2));  
       }
       else if (n==0) {
        attron(COLOR_PAIR(6));
        mvaddch(x, y, 'V');
        attroff(COLOR_PAIR(6));        
       }
  }
}

/** A93617 Pedro Martins
 * Função para desenhar mobs conforme o estado
 */
void draw_mob(MOB mob, int playerX, int playerY) { 
    int distance = sqrt(pow(mob.x - playerX, 2) + pow(mob.y - playerY, 2));

    if (distance <= 6) {
        attron(COLOR_PAIR(18));  // mob visível - cor preta
        mvaddch(mob.x, mob.y, mob.symbol);
        attroff(COLOR_PAIR(18));
    } else {
     if (mob.seen == true && mob.dark == false) {
        attron(COLOR_PAIR(4));  // mob não visível, mas já foi vista - cor cinza
        mvaddch(mob.x, mob.y, mob.symbol);
        attroff(COLOR_PAIR(4));
    } else {
       if (mob.dark == true) {
        attron(COLOR_PAIR(1));  // mob não visível e nunca foi vista - cor preta
        mvaddch(mob.x, mob.y, mob.symbol);
        attroff(COLOR_PAIR(1));
       }
    }
   }
}

/** A93617 Pedro Martins
 * Função para gerar coordenadas aleatórias para as mobs
 */
COORD generateRandomCoords(int rows, int cols) {
    COORD coords;
    coords.x = rand() % rows;
    coords.y = rand() % cols;
    if (mapa_pode_andar(coords.x,coords.y)) {
    return coords;
    }
    else {
     return generateRandomCoords(rows,cols);
    }
}

/** A93617 Pedro Martins
 * Perseguição do jogador por parte do zombie
 */
void zombie_persegue(STATE *st, MOB *zombie, int rows, int cols) {
    // Calcula a direção na qual o inimigo deve se mover para perseguir o jogador
    int dx = 0, dy = 0;
    if (st->playerX < zombie->x) {
        dx = -1; // Move para a esquerda
    } else if (st->playerX > zombie->x) {
        dx = 1; // Move para a direita
    }
    if (st->playerY < zombie->y) {
        dy = -1; // Move para cima
    } else if (st->playerY > zombie->y) {
        dy = 1; // Move para baixo
    }

    // Calcula as novas coordenadas do inimigo
    int new_x = zombie->x + dx;
    int new_y = zombie->y + dy;
                int px = zombie->x;
                int py = zombie->y;
                int n = 0;
                
    // Verifica se o novo local está dentro dos limites do mapa
    if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                char c = mvinch(new_x,new_y);
                // Verifica se o novo local está dentro dos limites do mapa
                if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                   if (c=='.' || c=='h' || (c!='-'&&c!='+'&&c!=' '&&c!='H'&&c!='@')) {n = 1; zombie->dark = true;}
                   else if (c=='-' || c=='+') {n = 2; zombie->dark = false;}
                       else if (c==' ' || c=='H' || c=='@') {n = 3; zombie->seen = true;}// Marca a MOB como vista
                       
                draw_prevMob(px,py,n);
                                
        if (mapa_pode_andar(new_x, new_y)) {
            zombie->x = new_x;
            zombie->y = new_y;
        }
    }
}
}

/** A93617 Pedro Martins
 * Reg de vida do player
 */

void rest(STATE *st) {
    st->playerHp += 1; // Incrementa a vida do jogador
    if (st->playerHp > 100+st->equip[2].stat) {
        st->playerHp = 100+st->equip[2].stat; // Limita a vida máxima do jogador
    }

}



/** A93617 Pedro Martins
 * Ultima janela
 */

void bossDefeat() {
    clear();  // Limpa a tela
    refresh();

    
    int rows, cols;
    getmaxyx(stdscr, rows, cols);
    WINDOW* boss_defeat_win = newwin(rows, cols, 0, 0);

    // Configura as cores
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1) | A_BOLD);

    
    int x = (cols - 9) / 2;
    int y = rows / 2;

    mvwprintw(boss_defeat_win, y, x, "BOSS DERROTADO! JOGO VENCIDO! PARABÉNS!");

    // Atualiza a janela e aguarda um tempo antes de encerrar o jogo
    wrefresh(boss_defeat_win);
    napms(2000);  // Aguarda 2 segundos

    // Limpa a janela e liberta a memória
    delwin(boss_defeat_win);
    endwin();
    exit(0);  // Encerra o programa
}


/** A93617 Pedro Martins
 * Janela de Gameover
 */
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

    // Limpa a janela e liberta a memória
    delwin(game_over_win);
    endwin();
    exit(0);  // Encerra o programa
}


