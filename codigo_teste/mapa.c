#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>
#include <string.h>

#include "state.h"
#include "mapa.h"

char message[100];


 // Listagem das salas posiveis do mapa
void template1(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhhhhhhhh");
    mvprintw(w*10+1, k*10, "h........h");
    mvprintw(w*10+2, k*10, "h........h");
    mvprintw(w*10+3, k*10, "h........h");
    mvprintw(w*10+4, k*10, "..........");
    mvprintw(w*10+5, k*10, "..........");
    mvprintw(w*10+6, k*10, "h........h");
    mvprintw(w*10+7, k*10, "h........h");
    mvprintw(w*10+8, k*10, "h........h");
    mvprintw(w*10+9, k*10, "hhhhhhhhhh");
    attroff(COLOR_PAIR(1));
}

void template2(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhh..hhhh");
    mvprintw(w*10+1, k*10, "h........h");
    mvprintw(w*10+2, k*10, "h........h");
    mvprintw(w*10+3, k*10, "h........h");
    mvprintw(w*10+4, k*10, "....S.....");
    mvprintw(w*10+5, k*10, "..........");
    mvprintw(w*10+6, k*10, "h........h");
    mvprintw(w*10+7, k*10, "h........h");
    mvprintw(w*10+8, k*10, "h........h");
    mvprintw(w*10+9, k*10, "hhhh..hhhh");
    attroff(COLOR_PAIR(1));
}

void template3(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhh..hhhh");
    mvprintw(w*10+1, k*10, "h........h");
    mvprintw(w*10+2, k*10, "h........h");
    mvprintw(w*10+3, k*10, "h........h");
    mvprintw(w*10+4, k*10, "h........h");
    mvprintw(w*10+5, k*10, "h........h");
    mvprintw(w*10+6, k*10, "h........h");
    mvprintw(w*10+7, k*10, "h........h");
    mvprintw(w*10+8, k*10, "h........h");
    mvprintw(w*10+9, k*10, "hhhh..hhhh");
    attroff(COLOR_PAIR(1));
}

void template4(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhh..hhhh");
    mvprintw(w*10+1, k*10, "h........h");
    mvprintw(w*10+2, k*10, "h........h");
    mvprintw(w*10+3, k*10, "h........h");
    mvprintw(w*10+4, k*10, "..........");
    mvprintw(w*10+5, k*10, "..........");
    mvprintw(w*10+6, k*10, "h........h");
    mvprintw(w*10+7, k*10, "h........h");
    mvprintw(w*10+8, k*10, "h........h");
    mvprintw(w*10+9, k*10, "hhhhhhhhhh");
    attroff(COLOR_PAIR(1));
}

void template5(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhhhhhhhh");
    mvprintw(w*10+1, k*10, "h........h");
    mvprintw(w*10+2, k*10, "h........h");
    mvprintw(w*10+3, k*10, "h........h");
    mvprintw(w*10+4, k*10, "..........");
    mvprintw(w*10+5, k*10, "..........");
    mvprintw(w*10+6, k*10, "h........h");
    mvprintw(w*10+7, k*10, "h........h");
    mvprintw(w*10+8, k*10, "h........h");
    mvprintw(w*10+9, k*10, "hhhh..hhhh");
    attroff(COLOR_PAIR(1));
}

void template6(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhh..hhhh");
    mvprintw(w*10+1, k*10, "hhhh..hhhh");
    mvprintw(w*10+2, k*10, "hhhh..hhhh");
    mvprintw(w*10+3, k*10, "hhhh..hhhh");
    mvprintw(w*10+4, k*10, "..........");
    mvprintw(w*10+5, k*10, "..........");
    mvprintw(w*10+6, k*10, "hhhh..hhhh");
    mvprintw(w*10+7, k*10, "hhhh..hhhh");
    mvprintw(w*10+8, k*10, "hhhh..hhhh");
    mvprintw(w*10+9, k*10, "hhhh..hhhh");
    attroff(COLOR_PAIR(1));
}

void template7(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhh..hhhh");
    mvprintw(w*10+1, k*10, "hh......hh");
    mvprintw(w*10+2, k*10, "h........h");
    mvprintw(w*10+3, k*10, "h........h");
    mvprintw(w*10+4, k*10, "....hh....");
    mvprintw(w*10+5, k*10, "....hh....");
    mvprintw(w*10+6, k*10, "h........h");
    mvprintw(w*10+7, k*10, "h........h");
    mvprintw(w*10+8, k*10, "hh      hh");
    mvprintw(w*10+9, k*10, "hhhhhhhhhh");
    attroff(COLOR_PAIR(1));
}

void template8(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhh..hhhh");
    mvprintw(w*10+1, k*10, "hhhh...hhh");
    mvprintw(w*10+2, k*10, "hhhhh...hh");
    mvprintw(w*10+3, k*10, "hhhhhh...h");
    mvprintw(w*10+4, k*10, "..hhhhh...");
    mvprintw(w*10+5, k*10, "...hhhhh..");
    mvprintw(w*10+6, k*10, "h...hhhhhh");
    mvprintw(w*10+7, k*10, "hh...hhhhh");
    mvprintw(w*10+8, k*10, "hhh...hhhh");
    mvprintw(w*10+9, k*10, "hhhh..hhhh");
    attroff(COLOR_PAIR(1));
}

void template9(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhh..hhhh");
    mvprintw(w*10+1, k*10, "h........h");
    mvprintw(w*10+2, k*10, "h.h....h.h");
    mvprintw(w*10+3, k*10, "h.h....h.h");
    mvprintw(w*10+4, k*10, "..h....h..");
    mvprintw(w*10+5, k*10, "..h....h..");
    mvprintw(w*10+6, k*10, "h.h....h.h");
    mvprintw(w*10+7, k*10, "h.h....h.h");
    mvprintw(w*10+8, k*10, "h........h");
    mvprintw(w*10+9, k*10, "hhhh..hhhh");
    attroff(COLOR_PAIR(1));
}

void template10(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhhhhhhhh");
    mvprintw(w*10+1, k*10, "hhhhhhhhhh");
    mvprintw(w*10+2, k*10, "hhhhhhhhhh");
    mvprintw(w*10+3, k*10, "hhhhhhhhhh");
    mvprintw(w*10+4, k*10, "hhhhhhhhhh");
    mvprintw(w*10+5, k*10, "hhhhhhhhhh");
    mvprintw(w*10+6, k*10, "hhhhhhhhhh");
    mvprintw(w*10+7, k*10, "hhhhhhhhhh");
    mvprintw(w*10+8, k*10, "hhhhhhhhhh");
    mvprintw(w*10+9, k*10, "hhhhhhhhhh");
    attroff(COLOR_PAIR(1));
}

void template11(int w, int k) {
    
    attron(COLOR_PAIR(1));
    mvprintw(w*10, k*10,   "hhhh..hhhh");
    mvprintw(w*10+1, k*10, "h........h");
    mvprintw(w*10+2, k*10, "h........h");
    mvprintw(w*10+3, k*10, "h........h");
    mvprintw(w*10+4, k*10, "....ss....");
    mvprintw(w*10+5, k*10, "....ss....");
    mvprintw(w*10+6, k*10, "h........h");
    mvprintw(w*10+7, k*10, "h........h");
    mvprintw(w*10+8, k*10, "h........h");
    mvprintw(w*10+9, k*10, "hhhh..hhhh");
    attroff(COLOR_PAIR(1));
}

  // Restrem a criação de novas salas para o mapa ser compativel
int correct_template(int pt) {
    
    int c;
    
    if (pt == 1 || pt == 4 || pt == 5) {
        c = (rand() % ((8-1) + 1)) + 1;
        if (c != 1 && c != 2) c++;
        return c;
    }
    else{
        if (pt == 7 || pt == 8) {
            c = (rand() % ((7-1) + 1)) + 1;
            if (c != 1) c += 3;
            return c;
        }
        else {
           if (pt == 10) {
              c = (rand() % 2) + 2;  // Generate random number between 2 and 3
             }
            else {
                c = (rand() % ((10-1) + 1)) + 1;
                return c;
            }
        }
    }
    return 2;
}

  // Cria a matriz com os numeros aleatorios que representam salas
void generate_template(int templateRows, int templateCols, int templateMap[templateRows][templateCols]) {

    int i,j;
    memset(templateMap, 0, templateRows * templateCols * sizeof(int));
    
    i = rand() % (templateRows/10);
    j = rand() % (templateCols/10-1)+1;
    templateMap[i][j] = 11;
    for (i=0; i<templateRows; i++) {
        for (j=0; j<templateCols; j++) {
        if (i==0 && j==0) templateMap[i][j] = 2;  // cria a primeira sala para ser sempre compativel
        else if (i>0 && j==0) templateMap[i][j] = correct_template(templateMap[i-1][0]);  // restrem a criação da primeira coluna
        else {
            if (templateMap[i][j] == 0){
            templateMap[i][j] = correct_template(templateMap[i][j-1]);  // cria aleatoriamente tendo em consideração a sala anterior
        }
    }
}
}
}

// apaga o mada no ecrã quando um novo é criado
void reset_map(int templateRows,int templateCols) {
 for (int i = 0; i < templateRows; i++) {
  for (int j = 0; j < templateCols; j++) {
    attron(COLOR_PAIR(1));
    mvaddch(i,j,' ');
    attroff(COLOR_PAIR(1));
  }
 }
}

  // Cria e desenhas o mapa
void generate_map(int templateRows, int templateCols) {
    
    int i, j, n;
    int templateMap[templateRows][templateCols];  // matriz dos números que correspondem a salas
    int x=(templateRows)/10;  // como cada sala tem um tamanho predefinido
    int y=(templateCols)/10;  // criamos novos máximos com isso em consideração
    
    generate_template(templateRows, templateCols, templateMap);
 
 for (i=0; i<x;i++) {
  for (j=0; j<y; j++) {
  n = templateMap[i][j];  // desenha as salas
  switch(n) {
        case 1: 
            template1(i,j); 
            break;
        case 2: 
            template2(i,j); 
            break;
        case 3: 
            template3(i,j); 
            break;
        case 4: 
            template4(i,j); 
            break;
        case 5: 
            template5(i,j); 
            break;
        case 6: 
            template6(i,j); 
            break;
        case 7: 
            template7(i,j); 
            break;
        case 8: 
            template8(i,j); 
            break;
        case 9: 
            template9(i,j); 
            break;
        case 10: 
            template10(i,j); 
            break;
        case 11: 
            template11(i,j); 
            break;
        }
    }
}

}

  // Verifica se a entidade pode fazer um certo movimento
int mapa_pode_andar (int x, int y) {
    char c = mvinch(x,y);
    
    if (c != 'H' && c != 'h' && c != '+' && c != 'M' && c != 'L' && c != '&' && c != '~' && c != 'W' && c != 'B' && c != 'T') return 1;
    return 0;
}

  // Transforma blocos com luz em blocos sem luz
void eraseaux(char c, int j, int i){

if (c==' ') {  // modifica o chão iluminado
    attron(COLOR_PAIR(4));
    mvaddch(j,i,'-');
    attroff(COLOR_PAIR(4)); 
}
else {
if (c=='H') {  // modifica as paredes iluminadas
    attron(COLOR_PAIR(5));
    mvaddch(j,i,'+');
    attroff(COLOR_PAIR(5)); 
}
else {
if (c=='L') {
    attron(COLOR_PAIR(6));
    mvaddch(j,i,'L');
    attroff(COLOR_PAIR(6));
}
else {
 if(c=='!'||c=='|'||c=='D'||c=='I'||c=='F'||c=='*'||c=='G'||c=='A'||c=='C' ||c=='%' ||c=='#') {
    attron(COLOR_PAIR(4));
    mvaddch(j,i,c);
    attroff(COLOR_PAIR(4));
   }
  }
}
}
}
 
  // Transforma blocos sem luz em bloco com luz
void lightaux(char c, int j, int i) {

if (c=='.' || c=='-' || c==' ') {  // transforma o chão não iluminado
    attron(COLOR_PAIR(2));
    mvaddch(j,i,' ');
    attroff(COLOR_PAIR(2)); 
}
else {
if (c=='h' || c=='+' || c=='H') {  // transforma as paredes não iluminadas
    attron(COLOR_PAIR(3));
    mvaddch(j,i,'H');
    attroff(COLOR_PAIR(3)); 
}
else {
if (c=='s' || c=='S') {  // transforma as escadas não iluminadas
    attron(COLOR_PAIR(COLOR_WHITE));
    mvaddch(j,i,'S');
    attroff(COLOR_PAIR(COLOR_WHITE));
}
else {
if (c=='L') {
    attron(COLOR_PAIR(6));
    mvaddch(j,i,'L');
    attroff(COLOR_PAIR(6));
}
else {
    attron(COLOR_PAIR(COLOR_WHITE));
    mvaddch(j,i,c);
    attroff(COLOR_PAIR(COLOR_WHITE));
}
}
}
}
}

  // Função que simula luz
void drawlight(STATE *st, int r, int co) {
    
    int x = st->playerX; int y = st->playerY;
    int a, i;
    double dx, dy, rx, ry;
    char c;

    for (a=0; a<360; a++) {  // Vai por os angulos de 0 a 360
    dx = cos(a*M_PI/180);  // cria o vetor de direção
    dy = sin(a*M_PI/180);
    rx = x + dx; ry = y + dy;  // atualiza os "raios"
    i=0;
    while (rx >= 0 && rx < r && ry >= 0 && ry < co && ((rx-x)*(rx-x) + (ry-y)*(ry-y)) <= 49) { // restrem dentro das paredes do mapa total e a uma distancia 7 do player
        c = mvinch((int) rx, (int) ry);
        if (((rx-x)*(rx-x) + (ry-y)*(ry-y)) <= 36) {  // Ilumina os blocos dentro de um raio de 6
        if (i == 0) {  // quando está atrás da primeira parede
            lightaux(c,(int)rx,(int)ry);
            rx +=dx; ry +=dy;
        }
        else {  // quando passou a primeira parede
            eraseaux(c,(int) rx, (int) ry);
            rx +=dx; ry +=dy;
        }
        if (c == 'H' || c == 'h' || c == '+') {  // deteta se chegou a uma parede
            i=1;
        }
    }
    else {  // apaga blocos iluminados depois do player mover
        eraseaux(c,(int) rx, (int) ry);
        rx +=dx; ry +=dy;     
    }
}
}
}

  // Função que transforma blocos iluminados em não iluminados depois do player passar de um lado do mapa para outro
void erase_light(int x, int y, int d, int rows, int cols){
    
    int i,j;
    char c;
    
    if (d==1) {  // no caso de o player ter movido da parede superior
    for (i=x+11; i>=x; i--){  // as necessárias rows para serem modificadas
    for (j=y-6; j<=y+6; j++){  // as necessárias cols para serem modificadas
        c = mvinch (i,j);
        eraseaux(c,i,j);
    }
}
}
 if (d==2) {  // no caso de o player ter movido da parede inferior
  for (i=x-11; i<=x && i<rows; i++){
    for (j=y-6; j<=y+6 && j<cols; j++){
        c = mvinch (i,j);
        eraseaux(c,i,j);
    }
   }
  }
  if (d==3) {  // no caso de o player ter movido da parede esquerda
    for (i=x-6; i<=x+6 && i<rows; i++){
        for (j=y+11; j>=y; j--){
            c = mvinch (i,j);
            eraseaux(c,i,j);
        }
    }
}
if (d==4) {  // no caso de o player ter movido da parede direita
    for (i=x-6; i<=x+6 && i<rows; i++){
        for (j=y; j>=y-11; j--){
            c = mvinch (i,j);
            eraseaux(c,i,j);
        }
    }
  }
}


  // Verifica se é possivel o player ir de uma parede do mapa para a oposta e se sim move o player
void endmap(STATE *st, int i, int rows, int cols) {
    
    int x = st->playerX;
    int y = st->playerY;
    
    if (i == 1) {  // no caso de estar na parede superior
        if (x == 0) {
            if (mapa_pode_andar (rows-1, y)) {
                st->playerX=rows;
                erase_light(x,y,1,rows,cols);
            }
            else st->playerX++;  // mantem o player na mesma coordenada se não poder mover
        }
    }
    if (i == 2) {  // no caso de estar na parede inferior
        if (x == rows-1) {
            if (mapa_pode_andar (0, y)) {
                st->playerX=0;
                erase_light(x,y,2,rows,cols);
            }
            else st->playerX--;
        }
    }
    if (i == 3) {  // no caso de estar na parede esquerda
        if (y == 0) {
            if (mapa_pode_andar (x, cols-1)) {
                st->playerY=cols;
                erase_light(x,y,3,rows,cols);
            }
            else st->playerY++;
        }
    }
    if (i == 4) {  // no caso de estar na parede direita
        if (y == cols-1) {
            if (mapa_pode_andar (x, 0)) {
                st->playerY=0;
                erase_light(x,y,4,rows,cols);
            }
            else st->playerY--;
        }
    }
}

  // Função que Ilumina o espaço à volta de tochas
void lights(int rows, int cols) {
 for (int i = 0; i<rows; i++) {  // encontra as tochas no mapa
  for (int j = 0; j<cols; j++) {
  char c = mvinch(i,j);
   if (c == 'L') {  // se for tocha ilumina o quadrado 10 por 10 com centro na tocha
    int x, y;
    for (x=i-5; x<i+5; x++) {
     for (y=j-5; y<j+5; y++) {
      char b = mvinch(x,y);
      lightaux(b,x,y);  // usa a função previamente definida
     }
    }
   }
  }
 }
}



void update_boss_state(STATE *st, MOB *boss, int rows, int cols, MessageWindow* msg_window) { // A93617 Pedro Martins "Implementação das mecânicas do boss"

    if (boss->hp > 0) {
        // Verifica se o boss está adjacente ao jogador
        if (is_enemy_adjacent_to_player(boss, st->playerX, st->playerY)) {
            player_attack(st, boss, msg_window);
        }
        else if ((abs(boss->x - st->playerX) <= 5 && abs(boss->y - st->playerY) <= 5)) {
            if (abs(boss->x - st->playerX) < 5 && abs(boss->y - st->playerY) < 5) {
                int dx = rand() % 3 - 1;
                int dy = rand() % 3 - 1;
                int new_x = boss->x + dx;
                int new_y = boss->y + dy;

                if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
                    if (mapa_pode_andar(new_x, new_y)) {
                        boss->x = new_x;
                        boss->y = new_y;
                    }
                }
            }

            draw_mob(*boss, st->playerX, st->playerY);

            if (abs(boss->x - st->playerX) <= 3 && abs(boss->y - st->playerY) <= 3 && rand() % 100 < 20) {
                player_attack(st, boss, msg_window);

                snprintf(message, sizeof(message), "O boss atirou um feitiço");
                add_message(msg_window, message);
            }

            if (boss->hp <= 0) bossDefeat();
        }
    }
}




void bossLevel(STATE *st, int rows,int cols, MOB *mobs, int num_mobs, MessageWindow* msg_window) { // A93617 Pedro Martins "Criação da sala do boss e implementação do monstro"

  reset_map(rows, cols);

  // Esvaziar o array de mobs
  memset(mobs, 0, sizeof(MOB) * num_mobs);

  // Configurar os dados do boss
  MOB boss;
  strncpy(boss.name, "Senhor das Trevas", sizeof(boss.name) - 1);
  boss.name[sizeof(boss.name) - 1] = '\0';
  boss.x = rows/2;
  boss.y = cols/2+1;
  boss.hp = 100;
  boss.atk = 30;
  boss.def = 20;
  boss.symbol = 'B';
  boss.seen = 0;

  num_mobs= 1; 

  mobs[num_mobs] = boss;

  update_boss_state(st, &boss, rows, cols, msg_window);

  // criação da sala final

   // cria as paredes à volta do mapa
  for (int i=0; i<rows; i++) {
   for (int j=0; j<cols; j++) {
    if (i != 0 && i != rows-1) {
     attron(COLOR_PAIR(3));
     mvaddch(i,0,'H');
     mvaddch(i,cols-1,'H');
     attroff(COLOR_PAIR(3));
    }
    else {
     attron(COLOR_PAIR(3));
     mvaddch(i,j,'H');
     attroff(COLOR_PAIR(3));
    }
   }
  }
   // cria as tochas distanciadas por 10 blocos pelo mapa
  for (int i=5; i<rows; i+=10) {
   for (int j=5; j<cols; j+=10) {
     attron(COLOR_PAIR(6));
     mvaddch(i,j,'L');
     attroff(COLOR_PAIR(6));
   }
  }
  lights(rows, cols); // ilumina as tochas
}



  // Cria um novo nivel
void nextlevel(STATE *st, int i, int rows, int cols, MessageWindow* msg_window, MOB *mobs, int num_mobs) {
    
    int x = st->playerX;
    int y = st->playerY;
    char c;
    char message[100];



    if (i == 1) {  // no caso de andar para cima
        c = mvinch(x-1,y);
        if (c == 'S') {
           if (st->level < 5) {  // verifica se chegou a sala do Boss
            gerarMundo(rows, cols, mobs, num_mobs, st);  // Senão chegou cria um novo mapa
            st->playerX=6; st->playerY=5;  // reseta o player para a primeira sala
            st->level++;  // aumenta o nivel
           }
          else {  // Chegou à sala do Boss
            bossLevel(st,rows, cols, mobs, num_mobs, msg_window);
            st->playerX=6; st->playerY=5;
            st->level++;            
          }
        snprintf(message, sizeof(message), "Subiu para o nivel %d \n          ", st->level);  // Indica que aumentou de nível
        add_message(msg_window, message);            
        }
    }
    if (i == 2) {  // no caso de andar para baixo
        c = mvinch(x+1,y);
        if (c == 'S') {
          if (st->level < 5) {
            gerarMundo(rows, cols, mobs, num_mobs, st);
            st->playerX=4; st->playerY=5;
            st->level++;
           }
          else {
            bossLevel(st,rows, cols, mobs, num_mobs, msg_window);
            st->playerX=6; st->playerY=5;
            st->level++; 
           } 
        // Adicione uma mensagem à janela de mensagens
        snprintf(message, sizeof(message), "Subiu para o nivel %d \n            ", st->level);
        add_message(msg_window, message);            
        }
    }
    if (i == 3) {  // no caso de andar para a esquerda
        c = mvinch(x,y-1);
        if (c == 'S') {
          if (st->level < 5) {
            gerarMundo(rows, cols, mobs, num_mobs, st);
            st->playerX=5; st->playerY=6;
            st->level++;
           }
          else {
            bossLevel(st,rows, cols, mobs, num_mobs, msg_window);
            st->playerX=6; st->playerY=5;
            st->level++; 
           } 
        // Adicione uma mensagem à janela de mensagens
        snprintf(message, sizeof(message), "Subiu para o nivel %d", st->level);
        add_message(msg_window, message);            
        }
    }
    if (i == 4) {  // no caso de andar para a direita
        c = mvinch(x,y+1);
        if (c == 'S') {
          if (st->level < 5) {
            gerarMundo(rows, cols, mobs, num_mobs, st);
            st->playerX=5; st->playerY=4;
            st->level++;
           }
          else {
            bossLevel(st,rows, cols, mobs, num_mobs, msg_window);
            st->playerX=6; st->playerY=5;
            st->level++; 
           } 
        // Adicione uma mensagem à janela de mensagens
        const char* message = "Subiu de nível!           "; 
        add_message(msg_window, message);            
        }
    }
}

Item items[10] = {{"Faca", 1, 2, '!',2,1,0},
                 {"Espada", 3, 4, '|',5,2,0},
                 {"Clava", 5, 6, '%',3,3,0},
                 {"Bomba Defensiva", 7,8, 'D',0, 4,1},
                 {"Bomba Incendiária", 9, 10, 'I',0, 5,1},
                 {"Flashbang", 11, 12, 'F',0, 6,1},
                 {"Poção de cura", 13, 14, '*',25, 7,1},
                 {"Bomba de fumo", 15,16, '#',0, 8,1},
                 {"Escudo", 17, 18, 'A',3,9,0},
                 {"Colar", 19, 20, 'C',20, 10,0} 
             };



void gerar_Random_item(int templateRows, int templateCols) {  // cria aleatóriamente as coordenadas e tipo do item
    
    int x, y, r;
    Item item;
    
        x = (rand() % (((templateRows)-1)+1)) + 1;
        y = (rand() % (((templateCols)-1)+1)) + 1;
        r = rand() % 10;

        item = items[r];
        while (mapa_pode_andar(x, y) != 1 && mvinch(x,y)!='S') {
         x = (rand() % (((templateRows)-1)+1)) + 1;
         y = (rand() % (((templateCols)-1)+1)) + 1;        
        }
       attron(COLOR_PAIR(1));
       mvaddch(x, y, item.symbol);
       attron(COLOR_PAIR(1));
       refresh();
}

int typecheck(int t, int it) {  // verifica se os items são do mesmo tipo
 if (t == it) return 1;
 return 0;
}

int exists(Item it, int len, Item inv[len]) {  // verifica se um item stackable já existe e devole a sua posição
int i;
 for (i=0; i<len; i++) {
  if (typecheck(inv[i].type, it.type)) {
   return i;
  }
 }
 return 0;
}

Item createItem(Item i, int l) {  // cria um item depois de ser apanhado, mudando o nome e stats
    int j;
    double probabilities[] = {0.5, 0.25, 0.15, 0.075, 0.025};  // cria probabilidades para os items
    double rn = (double) rand() / RAND_MAX;
    double cn = 0.0;
    for (j = 0; j < 5; j++) {  // seleciona o numero
        cn += probabilities[j];
        if (rn <= cn) {
            break;
        }
    }
  switch (j) {
   case 0: 
       strcat(i.name," de ferro");
       i.stat += 1*l;
       return i;
   case 1: 
       strcat(i.name," de Diamante");
       i.stat += 2*l;
       return i;
   case 2: 
       strcat(i.name," de Mitril");
       i.stat += 3*l;
       return i;
   case 3: 
       strcat(i.name," Divino");
       i.stat += 4*l;
       return i;
   case 4: 
       strcat(i.name," das Trevas");
       i.stat += 5*l; 
       return i;  
  }
  return i;
}

void itemUpdate(STATE *st, char c, MessageWindow* msg_window) {  // Adiciona items ao inventário e modifica os stats do player
int i=0;
char message[100];
char name[100];
  if ( c != 'H' && c != ' ' && c != '-' && c != '+' && c != '.' && c != 'h' && c != 'M' && c != 'L' && c != '&' && c != '~' && c != 'W' && c != 'T') {
    switch(c) {
    case '!': 
        st->inv[st->len]=createItem(items[0], st->level); // adiciona o item ao inventário
        strcpy(name,st->inv[st->len].name);
        st->len++; 
        break;
    case '|': 
        st->inv[st->len]=createItem(items[1], st->level); 
        strcpy(name,st->inv[st->len].name);
        st->len++; 
        break;
    case 'D':  
        i = exists(items[3], st->len, st->inv);  // devolve a posição do item
        if (i != 0) {  // verifica se o item já existe
        strcpy(name,st->inv[i].name);
        st->inv[i].quantity++;  // aumenta a quantidade do item
        }
        else {
        st->inv[st->len]=items[3];
        strcpy(name,st->inv[st->len].name);
        st->len++;
        } 
        break;
    case 'I': 
        i = exists(items[4], st->len, st->inv);
        if (i != 0) {
        strcpy(name,st->inv[i].name);
        st->inv[i].quantity++;
        }
        else {
        st->inv[st->len]=items[4];
        strcpy(name,st->inv[st->len].name);
        st->len++;
        } 
        break;
    case 'F':  
        i = exists(items[5], st->len, st->inv);
        if (i != 0) {
        strcpy(name,st->inv[i].name);
        st->inv[i].quantity++;
        }
        else {
        st->inv[st->len]=items[5];
        strcpy(name,st->inv[st->len].name);
        st->len++;
        }  
        break;
    case '*': 
        i = exists(items[6], st->len, st->inv);
        if (i != 0) {
        strcpy(name,st->inv[i].name);
        st->inv[i].quantity++;
        }
        else {
        st->inv[st->len]=items[6];
        strcpy(name,st->inv[st->len].name);
        st->len++;
        }   
        break;
    case '#': 
        i = exists(items[7], st->len, st->inv);
        if (i != 0) {
        strcpy(name,st->inv[i].name);
        st->inv[i].quantity++;
        }
        else {
        st->inv[st->len]=items[7];
        strcpy(name,st->inv[st->len].name);
        st->len++;
        } 
        break;
    case '%':
        st->inv[st->len]=createItem(items[2], st->level);
        strcpy(name,st->inv[st->len].name);  
        st->len++; 
        break;
    case 'A':  
        st->inv[st->len]=createItem(items[8], st->level); 
        strcpy(name,st->inv[st->len].name);
        st->len++; 
        break;
    case 'C': 
        st->inv[st->len]=createItem(items[9], st->level); 
        strcpy(name,st->inv[st->len].name);
        st->len++; 
        break;
    }
   // Adicione uma mensagem à janela de mensagens
   snprintf(message, sizeof(message), "%s apanhado.\n", name); 
   add_message(msg_window, message);
   }
}



void itemPickUp(STATE *st, int i, MessageWindow* msg_window) {
    
    int x = st->playerX;
    int y = st->playerY;
    char c;

    if (i == 1) {  // no caso de andar para cima
        c = mvinch(x-1,y);
        itemUpdate(st, c, msg_window);
    }
    if (i == 2) {  // no caso de andar para baixo
        c = mvinch(x+1,y);
        itemUpdate(st, c,msg_window);      
    }
    if (i == 3) {  // no caso de andar para a esquerda
        c = mvinch(x,y-1);
        itemUpdate(st, c, msg_window);       
    }
    if (i == 4) {  // no caso de andar para a direita
        c = mvinch(x,y+1);
        itemUpdate(st, c, msg_window);      
    }
}

  // função principal da criação de mapas
void gerarMundo(int templateRows, int templateCols, MOB *mobs, int num_mobs, STATE *st) {
    
    int i;
    
    reset_map(templateRows, templateCols);
    generate_map(templateRows, templateCols);
    for (i=0; i < N_MAXIMO_ITEMS; i++) {  // cria um certo número de items
    gerar_Random_item(templateRows, templateCols); // funções para adicionar itens
        }
    	    // Inicializar mobs
    for (int i = 0; i < num_mobs; i++) {
        COORD coords = generateRandomCoords(templateRows, templateCols);
        int probability = rand() % 100;  // Gera uma probabilidade entre 0 e 99

        if (probability < 50) {
            mobs[i] = (MOB){"Stupid zombie",coords.x, coords.y, 12+2*st->level, 12+2*st->level, 12+2*st->level, '&', false, true};  // STUPID
        } else if (probability < 80) {
            mobs[i] = (MOB){"Coward snake",coords.x, coords.y, 10+2*st->level, 10+2*st->level, 8+2*st->level, '~', false, true};   // COWARD
        } else {
            mobs[i] = (MOB){"Wizard",coords.x, coords.y, 12+2*st->level, 14+2*st->level, 10+2*st->level, 'W', false, true};     // SMART
        }
    }

}

