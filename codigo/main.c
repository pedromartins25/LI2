#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"
#include "mapa.h"

#define MAX_MOBS 10
#define TEMPLATE_SIZE 10
#define DARKFLOOR 8
#define FLOOR 11
#define WALL 10
#define DARKWALL 9
#define STATS 12


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





int main() {
	STATE st = {5,5,100,10,10,{0},0};

	MOB mob = {15,15,10,10,10};
	int num_mobs = 10;

	WINDOW *wnd = initscr(); // inicializa a tela
	int ncols, nrows, templateRows, templateCols;
	getmaxyx(wnd,nrows,ncols); // número maximo de linhas e colunas que a janela pode conter
	templateRows = nrows - (nrows%TEMPLATE_SIZE) - TEMPLATE_SIZE; templateCols = ncols - (ncols%TEMPLATE_SIZE) - TEMPLATE_SIZE; // número de linhas e colunas do mapa

	srandom(time(NULL));
	start_color(); // Inicializa a biblioteca de cores do ncurses

	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, false);
	keypad(stdscr, true);
 
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
