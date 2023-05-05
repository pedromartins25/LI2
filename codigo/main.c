#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"
#include "mapa.h"

int main() {
	STATE st = {5,5,100,10,10,{{"Tocha", 0, 0, 'T',0,0}},1};

	MOB mob = {15,15,10,10,10};
	int num_mobs = 10;

	WINDOW *wnd = initscr(); // inicializa a tela
	int ncols, nrows, templateRows, templateCols;
	getmaxyx(wnd,nrows,ncols); // número maximo de linhas e colunas que a janela pode conter
	templateRows = nrows - (nrows%TEMPLATE_SIZE) - TEMPLATE_SIZE; templateCols = ncols - (ncols%TEMPLATE_SIZE) - TEMPLATE_SIZE; // número de linhas e colunas do mapa

	srandom(time(NULL));
	start_color(); // Inicializa a biblioteca de cores do ncurse
	curs_set(0);
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, false);
	keypad(stdscr, true);
	
 	if (nrows>30 && ncols >30) {
           // inicialização das cores e os pairs necessários
        init_color(STATS, 100,200,700);
        init_color(DARKFLOOR,250,250,250);
        init_color(DARKWALL,100,100,100);
        init_color(WALL,200,200,200);
        init_color(FLOOR,500,500,500);
	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BLUE, COLOR_BLUE, 14);
        init_pair(STATS,COLOR_BLACK,STATS);
        init_pair(1, COLOR_BLACK, COLOR_BLACK);
        init_pair(2, FLOOR, FLOOR);
        init_pair(3, COLOR_BLACK, WALL);
        init_pair(4, DARKFLOOR, DARKFLOOR);
        init_pair(5, WALL, DARKWALL);
        init_pair(15,COLOR_BLUE, COLOR_BLACK);
        init_pair(16,COLOR_BLACK, COLOR_RED);
        init_pair(17,COLOR_BLUE, FLOOR); // player color

	gerarMundo(templateRows, templateCols);
	drawlight(&st, templateRows, templateCols);

	    // inicializa a tela do ncurses

    // cria a janela de stats
    int stats_height = 5;
    int stats_width = 10;
    int stats_y = 0;
    int stats_x = ncols - stats_width;
    WINDOW *stats_window = newwin(stats_height, stats_width, stats_y, stats_x);

	/**
	 * Este código está muito mal escrito!
	 * Deveria existir uma função chamada draw_player!
	 *
	 * Se estamos a desenhar uma luz à volta do jogador
	 * deveria existir uma função chamada draw_light!
	 *
	 */
	while(1) {
		move(nrows - 1, 0);
		attron(COLOR_PAIR(15));
		printw("(%d, %d) %d %d", st.playerX, st.playerY, ncols, nrows);
		attroff(COLOR_PAIR(15));
		attron(COLOR_PAIR(17));
		mvaddch(st.playerX, st.playerY, '@' | A_BOLD);
		attroff(COLOR_PAIR(17));
		move(st.playerX, st.playerY);
		update(&st, &mob, num_mobs, templateRows, templateCols);
		        // atualiza a janela de stats
        update_stats_window(stats_window, &st);
	}
    // limpa a janela de stats e encerra o ncurses
     delwin(stats_window);
     endwin();
   }
   else{endwin(); printf("%s\n","Aumente a janela");}

   return 0;
}
