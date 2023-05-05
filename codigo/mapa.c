#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <math.h>

#include "state.h"
#include "mapa.h"


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
    mvprintw(w*10+4, k*10, "..........");
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
                c = (rand() % ((3-2) + 2)) + 2;
                if (c != 2) c = 10;
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
    
    i = (rand() % (((templateRows/10-1)-1)+1)) + 1;
    j = (rand() % (((templateCols/10-1)-1)+1)) + 1; 
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

void reset_map(int templateRows,int templateCols) {
 for (int i = 0; i <= templateRows; i++) {
  for (int j = 0; j <= templateCols; j++) {
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

for (i=0; i<x;i++) {
    for (j=0; j<y; j++) {
        templateMap[i][j] = 0;
    }
}
}

  // Verifica se a entidade pode fazer um certo movimento
int mapa_pode_andar (int x, int y) {
    char c = mvinch(x,y);
    
    if (c != 'H' && c != 'h' && c != '+') return 1;
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
 if(c=='!'||c=='|'||c=='d'||c=='i'||c=='f'||c=='*'||c=='G') {
    attron(COLOR_PAIR(4));
    mvaddch(j,i,c);
    attroff(COLOR_PAIR(4));
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
    attron(COLOR_PAIR(COLOR_WHITE));
    mvaddch(j,i,c);
    attroff(COLOR_PAIR(COLOR_WHITE));
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

void nextlevel(STATE *st, int i, int rows, int cols) {
    
    int x = st->playerX;
    int y = st->playerY;
    char c;

    if (i == 1) {  // no caso de andar para cima
        c = mvinch(x-1,y);
        if (c == 'S') {
            gerarMundo(rows, cols);
            st->playerX=6; st->playerY=5;
        }
    }
    if (i == 2) {  // no caso de andar para baixo
        c = mvinch(x+1,y);
        if (c == 'S') {
            gerarMundo(rows, cols);
            st->playerX=4; st->playerY=5;
        }
    }
    if (i == 3) {  // no caso de andar para a esquerda
        c = mvinch(x,y-1);
        if (c == 'S') {
            gerarMundo(rows, cols);
            st->playerX=5; st->playerY=6;
        }
    }
    if (i == 4) {  // no caso de andar para a direita
        c = mvinch(x,y+1);
        if (c == 'S') {
            gerarMundo(rows, cols);
            st->playerX=5; st->playerY=4;
        }
    }
}

Item items[8] = {{"Faca", 1, 2, '!',1,0},
                 {"Espada", 3, 4, '|',2,0},
                 {"Clava", 5, 6, '%',3,0},
                 {"Bomba Defensiva", 7,8, 'D',4,1},
                 {"Bomba Incendiária", 9, 10, 'I',5,1},
                 {"Flashbang", 11, 12, 'F', 6,1},
                 {"Nightstick", 13, 14, '*', 7,0},
                 {"Bomba de fumo", 15,16, '#', 8,1}
             };



void gerar_Random_item(int templateRows, int templateCols) {  // cria aleatóriamente as coordenadas e tipo do item
    
    int x, y, r;
    Item item;
    
        x = (rand() % (((templateRows)-1)+1)) + 1;
        y = (rand() % (((templateCols)-1)+1)) + 1;
        r = rand() % 8;

        item = items[r];
        while (mapa_pode_andar(x, y) != 1) {
         x = (rand() % (((templateRows)-1)+1)) + 1;
         y = (rand() % (((templateCols)-1)+1)) + 1;        
        }
       attron(COLOR_PAIR(1));
       mvaddch(x, y, item.symbol);
       attron(COLOR_PAIR(1));
       refresh();
}

int typecheck(int t, int it) {
 if (t == it) return 1;
 return 0;
}

int exists(Item it, int len, Item inv[len]) {
int i;
 for (i=0; i<len; i++) {
  if (typecheck(inv[i].type, it.type)) {
   return 1;
  }
 }
 return 0;
}

void itemUpdate(STATE *st, char c) {  // Adiciona items ao inventário e modifica os stats do player
    
    switch(c) {
    case '!': 
        st->playerAtk += 2; 
        st->inv[st->len]=items[0]; 
        st->len++; 
        break;
    case '|': 
        st->playerAtk += 5; 
        st->inv[st->len]=items[1]; 
        st->len++; 
        break;
    case 'D':  
        if (exists(items[3], st->len, st->inv)) {
        st->inv[st->len].quantity++;
        }
        else {
        st->inv[st->len]=items[3];
        st->len++;
        } 
        break;
    case 'I': 
        if (exists(items[4], st->len, st->inv)) {
        st->inv[st->len].quantity++;
        }
        else {
        st->inv[st->len]=items[4];
        st->len++;
        } 
        break;
    case 'F': 
        st->playerDef += 2; 
        if (exists(items[5], st->len, st->inv)) {
        st->inv[st->len].quantity++;
        }
        else {
        st->inv[st->len]=items[5];
        st->len++;
        }  
        break;
    case '*': 
        st->inv[st->len]=items[6]; 
        st->len++; 
        break;
    case '#': 
        if (exists(items[7], st->len, st->inv)) {
        st->inv[st->len].quantity++;
        }
        else {
        st->inv[st->len]=items[7];
        st->len++;
        } 
        break;
    case '%':
        st->playerAtk += 3; 
        st->inv[st->len]=items[2]; 
        st->len++; 
        break;
    }
}



void itemPickUp(STATE *st, int i) {
    
    int x = st->playerX;
    int y = st->playerY;
    char c;

    if (i == 1) {  // no caso de andar para cima
        c = mvinch(x-1,y);
        itemUpdate(st, c);
    }
    if (i == 2) {  // no caso de andar para baixo
        c = mvinch(x+1,y);
        itemUpdate(st, c);
    }
    if (i == 3) {  // no caso de andar para a esquerda
        c = mvinch(x,y-1);
        itemUpdate(st, c);
    }
    if (i == 4) {  // no caso de andar para a direita
        c = mvinch(x,y+1);
        itemUpdate(st, c);
    }
}

  // função principal da criação de mapas
void gerarMundo(int templateRows, int templateCols) {
    
    int i;

    generate_map(templateRows, templateCols);
    for (i=0; i < N_MAXIMO_ITEMS; i++) {  // cria um certo número de items
    gerar_Random_item(templateRows, templateCols); // funções para adicionar itens
        }
}

