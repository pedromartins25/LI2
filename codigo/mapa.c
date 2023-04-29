#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"
#include "mapa.h"

void template1(int w, int k) {
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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
    init_color(COLOR_BLACK, 0, 0, 0);
    init_pair(1,COLOR_BLACK, COLOR_BLACK);
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

void generate_template(int templateRows, int templateCols, int templateMap[templateRows][templateCols]) {
int i,j;
 for (i=0; i<templateRows; i++) {
  for (j=0; j<templateCols; j++) {
   if (i==0 && j==0) templateMap[i][j] = 2;
   else if (i>0 && j==0) templateMap[i][j] = correct_template(templateMap[i-1][0]);
        else templateMap[i][j] = correct_template(templateMap[i][j-1]);
  }
 }
}

void generate_map(int templateRows, int templateCols) {
int i, j, n;
int templateMap[templateRows][templateCols];
int x=(templateRows)/10;
int y=(templateCols)/10;
 generate_template(templateRows, templateCols, templateMap);
 for (i=0; i<x;i++) {
  for (j=0; j<y; j++) {
  n = templateMap[i][j];
  switch(n) {
        case 1: template1(i,j); break;
        case 2: template2(i,j); break;
        case 3: template3(i,j); break;
        case 4: template4(i,j); break;
        case 5: template5(i,j); break;
        case 6: template6(i,j); break;
        case 7: template7(i,j); break;
        case 8: template8(i,j); break;
        case 9: template9(i,j); break;
        case 10: template10(i,j); break;
  }
  }
 }
}

void gerarMundo(STATE *s, int templateRows, int templateCols) {
	s->playerX = 5;
	s->playerY = 5;
	s->playerHp = 100;
	s->playerAtk = 10;
	s->playerDef = 10;
	generate_map(templateRows, templateCols);
}

int mapa_pode_andar (int x, int y) {
char c = mvinch(x,y);
if (c != 'H' && c != 'h' && c != '+') return 1;
return 0;
}

void eraseaux(char c, int j, int i){
  init_color(COLOR_RED, 250, 250, 250);
  init_pair(4,COLOR_RED, COLOR_RED);
  init_color(COLOR_CYAN, 100, 100, 100);
  init_pair(5,COLOR_WHITE, COLOR_CYAN);
     if (c==' ') {
     attron(COLOR_PAIR(4));
     mvaddch(j,i,'-');
     attroff(COLOR_PAIR(4)); 
    }
    else {
     if (c=='H') {
     attron(COLOR_PAIR(5));
     mvaddch(j,i,'+');
     attroff(COLOR_PAIR(5)); 
  }
 }
}


void drawlight(STATE *st, int r, int co) {
int i,j;
int x = st->playerX; int y = st->playerY;
char c;
  init_color(COLOR_GREEN, 500, 500, 500);
  init_pair(2,COLOR_GREEN, COLOR_GREEN);
  init_color(COLOR_WHITE, 200, 200, 200);
  init_color(COLOR_BLACK, 0, 0, 0);
  init_pair(3,COLOR_BLACK, COLOR_WHITE);
  init_color(COLOR_RED, 250, 250, 250);
  init_pair(4,COLOR_RED, COLOR_RED);
  init_color(COLOR_CYAN, 100, 100, 100);
  init_pair(5,COLOR_WHITE, COLOR_CYAN);
 for (j=x-6; j<x+7 && j<=r-1; j++) {
  for (i=y-6; i<y+7 && i<=co-1; i++) {
   if ((j-x)*(j-x)+(i-y)*(i-y)<36) {
    c = mvinch(j,i);
    if (c=='.' || c=='-') {
     attron(COLOR_PAIR(2));
     mvaddch(j,i,' ');
     attroff(COLOR_PAIR(2)); 
    }
    else {
     if (c=='h' || c=='+') {
     attron(COLOR_PAIR(3));
     mvaddch(j,i,'H');
     attroff(COLOR_PAIR(3)); 
     }
    }
   }
   else {
    c = mvinch (j,i);
    eraseaux(c,j,i);
   }
  }
 }
}

void erase_light(int x, int y, int d, int rows, int cols){
int i,j;
char c;
 if (d==1) {
  for (i=x-6; i<=x+6 && i<=rows; i++){
   for (j=y-1; j>=y-11; j--){
        c = mvinch (i,j);
        eraseaux(c,i,j);
    }
   }
  }
 if (d==2) {
  for (i=x-6; i<=x+6 && i<=rows; i++){
   for (j=y+11; j>=y; j--){
        c = mvinch (i,j);
        eraseaux(c,i,j);
    }
   }
  }
 if (d==3) {
  for (i=x+11; i>=x; i--){
   for (j=y-6; j<=y+6; j++){
        c = mvinch (i,j);
        eraseaux(c,i,j);
    }
   }
  }
 if (d==4) {
  for (i=x-11; i<=x && i<=rows; i++){
   for (j=y-6; j<=y+6 && j<=cols; j++){
        c = mvinch (i,j);
        eraseaux(c,i,j);
    }
   }
  }
}

void endmap(STATE *st, int i, int rows, int cols) {
int x = st->playerX;
int y = st->playerY;
if (i == 1) {
 if (x == 0) {
  if (mapa_pode_andar (rows-1, y)) {
   st->playerX=rows;
   erase_light(x,y,3,rows,cols);
 }
 else st->playerX++;
 }
}
if (i == 2) {
 if (x == rows-1) {
  if (mapa_pode_andar (0, y)) {
   st->playerX=0;
   erase_light(x,y,4,rows,cols);
 }
 else st->playerX--;
 }
}
if (i == 3) {
 if (y == 0) {
  if (mapa_pode_andar (x, cols-1)) {
   st->playerY=cols;
   erase_light(x,y,2,rows,cols);
 }
 else st->playerY++;
 }
}
if (i == 4) {
 if (y == cols-1) {
  if (mapa_pode_andar (x, 0)) {
   st->playerY=0;
   erase_light(x,y,1,rows,cols);
 }
 else st->playerY--;
 }
}
}

