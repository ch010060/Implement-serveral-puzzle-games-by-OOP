#ifndef MENUG_H
#define MENUG_H
#include"menu_game.h"
#include"Landmine.h"
#include"matrix.h"
#include"data.h"
#include"Sudoku.h"
#include"Abstract.h"
#include"Bingo.h"
#include"code.h"
#include "maze.h"


class menu_game : public Abstract
{
public:
	menu_game();
	~menu_game();

	void gamemenu();
	

};

#endif

