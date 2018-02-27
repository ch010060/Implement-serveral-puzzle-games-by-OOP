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
	
	
/* ap����
Landmine -10
code -3
bingo -6
Sudoku -5
matrix -6
maze   -10
*/

do{
    system("cls");
	cout<<"<Z>�_����a�p        ����10ap\n\n";
	cout<<"<X>�^�꯫�����۰}    ����6 ap\n\n";
	cout<<"<S>����q���ƿW      ����5 ap\n\n";
	cout<<"<B>����������G      ����6 ap\n\n";
	cout<<"<C>�x�W�׷��K�X      ����3 ap\n\n";
	cout<<"<M>�J�Ϊ��r��g�c    ����10ap\n\n";

	
fflush(stdin);  //�M�Žw�İ�
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