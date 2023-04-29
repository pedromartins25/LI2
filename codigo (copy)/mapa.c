#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

#include "state.h"
#include "mapa.h"


void gerar(STATE *s) {
	s->playerX = 10;
	s->playerY = 10;
	s->playerHP = 100;
	s->playerAtk = 10;
	s->playerDef = 10;
}
