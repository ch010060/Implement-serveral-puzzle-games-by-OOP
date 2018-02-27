#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include"menu_game.h"
#include"matrix.h"
#include"Landmine.h"
#include"data.h"
#include"Sudoku.h"
#include"Abstract.h"
#include"Bingo.h"
#include"code.h"
#include "maze.h"



using namespace std;


extern int life;


menu_game::menu_game()
{}


menu_game::~menu_game()
{}

void menu_game::gamemenu()
{


	
	
	char key;

	Landmine aobj;
    Abstract *aPtr = &aobj;
	matrix   bobj;
	Abstract *bPtr = &bobj;
	Sudoku   cobj;
	Abstract *cPtr = &cobj;
	Bingo    dobj;
	Abstract *dPtr = &dobj;
    code     eobj;
	Abstract *ePtr = &eobj;
	maze     fobj;
	Abstract *fPtr = &fobj;
	
	
/* ap消耗
Landmine -10
code -3
bingo -6
Sudoku -5
matrix -6
maze   -10
*/

do{
    system("cls");
	cout<<"<Z>北韓踩地雷        消耗10ap\n\n";
	cout<<"<X>英國神秘巨石陣    消耗6 ap\n\n";
	cout<<"<S>美國益智數獨      消耗5 ap\n\n";
	cout<<"<B>丹麥趣味賓果      消耗6 ap\n\n";
	cout<<"<C>台灣終極密碼      消耗3 ap\n\n";
	cout<<"<M>埃及金字塔迷宮    消耗10ap\n\n";

	
fflush(stdin);  //清空緩衝區
key=getch();

	switch(key)
	{
	case 'Z':
	case 'z':
		system("cls");
		aPtr->play_a();
		break;
	
	case 'X':
	case 'x':
		system("cls");
		bPtr->play_a();
		break;

	case 'S':
	case 's':
		system("cls");
		cPtr->play_a();
	    break;

	case 'B':
	case 'b':
		system("cls");
		dPtr->play_a();
		system("pause");
		break;

	case 'C':
	case 'c':
		system("cls");
		ePtr->play_a();
		system("pause");
		break;

	case 'M':
	case 'm':
		system("cls");
		fPtr->play_a();
		system("pause");
		break;

	default:
		break;
	}
	if(life>0)
{
	key=75;
}


}while(key!=75);

	



}