#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include "state.h"
#include "mapa.h" 



int main() {
	STATE st = {5,5,100,10,10,{{"Tocha", 0, 0, 'T',0,0,0}},{{"Espada Quebrada",0,0, 'E',0,1,0},{"Armadura Velha",0,0, 'E',0,9,0},{"Colar de fio",0,0, 'E',0,10,0}},0,8,3,1, 0, 1};

    MOB mobs[MAX_MOBS];
    mobs[0] = (MOB){"Stupid zombie",15, 15, 12, 12, 12, '&', false, true}; //name, posx, posy, hp, atk, def, symbol, seen; STUPID 
    mobs[1] = (MOB){"Coward snake", 20, 20, 10, 10, 8, '~', false, true};   // COWARD
    mobs[2] = (MOB){"Wizard", 10, 10, 12, 14, 10, 'W', false, true};     // SMART  
    int num_mobs = 10;

	WINDOW *wnd = initscr(); // inicializa a tela
	int ncols, nrows, templateRows, templateCols;
	getmaxyx(wnd,nrows,ncols); // número maximo de linhas e colunas que a janela pode conter
	templateRows = nrows - (nrows%TEMPLATE_SIZE) - TEMPLATE_SIZE; templateCols = ncols - (ncols%TEMPLATE_SIZE) - TEMPLATE_SIZE; // número de linhas e colunas do mapa

	srand(time(NULL));
	start_color(); // Inicializa a biblioteca de cores do ncurse
	curs_set(0);
	halfdelay(5);
	noecho();
	nonl();
	intrflush(stdscr, false);
	keypad(stdscr, true);
	
 	if (nrows>=32 && ncols >=111) {
           // inicialização das cores e os pairs necessários
        init_color(STATS, 100,200,700);
        init_color(DARKFLOOR,250,250,250);
        init_color(DARKWALL,100,100,100);
        init_color(WALL,200,200,200);
        init_color(FLOOR,500,500,500);
        init_color(55,500,250,0);
	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BLUE, COLOR_BLUE, 14);
        init_pair(STATS,COLOR_BLACK,STATS);
        init_pair(1, COLOR_BLACK, COLOR_BLACK);
        init_pair(2, FLOOR, FLOOR);
        init_pair(3, COLOR_BLACK, WALL);
        init_pair(4, DARKFLOOR, DARKFLOOR);
        init_pair(5, WALL, DARKWALL);
        init_pair(6, 55, 55);
        init_pair(15,COLOR_BLUE, COLOR_BLACK);
        init_pair(16,COLOR_BLACK, COLOR_RED);
        init_pair(17,COLOR_BLUE, FLOOR); // player color
        init_pair(18, COLOR_BLACK, FLOOR); // player color
        init_pair(19, COLOR_RED, COLOR_BLACK); // MENSAGENS A VERMELHO

	gerarMundo(templateRows, templateCols, mobs, num_mobs, &st);
	drawlight(&st, templateRows, templateCols);

	    // inicializa a tela do ncurses

    // cria a janela de stats
    int stats_height = 5;
    int stats_width = 10;
    int stats_y = 0;
    int stats_x = ncols - stats_width;
    WINDOW *stats_window = newwin(stats_height, stats_width, stats_y, stats_x);



    // cria a janela de mensagens
    WINDOW* msg_wnd = newwin(10, ncols/3-2, templateRows+1 , 5);  // Define as dimensões da janela de mensagens
    MessageWindow msg_window;
    init_message_window(&msg_window);

  
  
   // Adicione uma mensagem à janela de mensagens
   const char* message1 = "Mover: use as setas/numpad";
   add_message(&msg_window, message1);
   const char* message2 = "Inventário: M             ";
   add_message(&msg_window, message2);
   const char* message3 = "Setas para scroll         ";
   add_message(&msg_window, message3);
   const char* message4 = "Equipar: E                ";
   add_message(&msg_window, message4);
   const char* message5 = "Dano: mover contra mobs   ";
   add_message(&msg_window, message5);
   const char* message6 = "Regeneração:r             ";
   add_message(&msg_window, message6);
   const char* message7 = "Tente chegar ao Boss      ";                        
   add_message(&msg_window, message7);




	while(1) {
		move(nrows - 1, 0);
		attron(COLOR_PAIR(15));
		printw("(%d, %d) %d %d", st.playerX, st.playerY, ncols, nrows);
		attroff(COLOR_PAIR(15));
		attron(COLOR_PAIR(17));
		mvaddch(st.playerX, st.playerY, '@' | A_BOLD);
		attroff(COLOR_PAIR(17));
		move(st.playerX, st.playerY);
		update(&st, mobs, num_mobs, templateRows, templateCols, stats_window, &msg_window, ncols);
		draw_message_window(msg_wnd, &msg_window, 0, 0);
        lights(templateRows, templateCols);
        update_stats_window(stats_window, &st); // atualiza a janela de stats
        if (st.playerHp <=0) gameOver();
	}
    // limpa a janela de stats e encerra o ncurses
     delwin(stats_window);
     delwin(msg_wnd);
     endwin();
   }
   else {
   	endwin(); 
   	printf("%s\n","Aumente a janela");
   }

   return 0;
}
