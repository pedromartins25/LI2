#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"
#include "mapa.h"

#define MAX_MOBS 10
#define TEMPLATE_SIZE 10


void update_stats_window(WINDOW *stats_window, STATE *st) {
    wclear(stats_window); // limpa a janela antes de atualizar

    // adiciona os stats do player à janela
    mvwprintw(stats_window, 1, 1, "HP: %d", st->playerHp);
    mvwprintw(stats_window, 2, 1, "ATK: %d", st->playerAtk);
    mvwprintw(stats_window, 3, 1, "DEF: %d", st->playerDef);

    wrefresh(stats_window); // atualiza a janela na tela
}





int main() {
	STATE st = {20,20,100,10,10};

	MOB mob = {15,15,10,10,10};
	int num_mobs = 10;

	WINDOW *wnd = initscr(); // inicializa a tela
	int ncols, nrows, templateRows, templateCols;
	getmaxyx(wnd,nrows,ncols); // número maximo de linhas e colunas que a janela pode conter
	templateRows = nrows - (nrows%TEMPLATE_SIZE); templateCols = ncols - (ncols%TEMPLATE_SIZE);

	srandom(time(NULL));
	start_color(); // Inicializa a biblioteca de cores do ncurses

	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, false);
	keypad(stdscr, true);

	init_pair(COLOR_WHITE, COLOR_WHITE, COLOR_BLACK);
        init_pair(COLOR_YELLOW, COLOR_YELLOW, COLOR_BLACK);
        init_pair(COLOR_BLUE, COLOR_BLUE, COLOR_BLACK);

	gerarMundo(&st, templateRows, templateCols);
	drawlight(&st, templateRows, templateCols);

	    // inicializa a tela do ncurses

    // cria a janela de stats
    int stats_height = 5;
    int stats_width = 20;
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
		attron(COLOR_PAIR(COLOR_BLUE));
		printw("(%d, %d) %d %d", st.playerX, st.playerY, ncols, nrows);
		attroff(COLOR_PAIR(COLOR_BLUE));
		attron(COLOR_PAIR(COLOR_WHITE));
		mvaddch(st.playerX, st.playerY, '@' | A_BOLD);
		attroff(COLOR_PAIR(COLOR_WHITE));
		move(st.playerX, st.playerY);
		update(&st, &mob, num_mobs, templateRows, templateCols);
		        // atualiza a janela de stats
        update_stats_window(stats_window, &st);
	}


	    // limpa a janela de stats e encerra o ncurses
    delwin(stats_window);
    endwin();

	return 0;
}
