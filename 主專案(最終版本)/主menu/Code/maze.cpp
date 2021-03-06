/*##########這是迷宮###########*/
#include <iostream>
#include <windows.h>
#include <Time.h>
#include <conio.h>
#include "maze.h"
#include "data.h"
#include"Abstract.h"
using namespace std;
#define MAP_StartX 16
#define MAP_StartY 1
#define StartX 1
#define StartY 1
#define SIZE 25
#define STEP 100

maze::maze()
{}


maze::~maze()
{}

 
BOOL gotoxy(int x, int y)
{
    HANDLE hOutput = GetStdHandle( STD_OUTPUT_HANDLE );    // 取得標準輸出的handle
    if( hOutput == INVALID_HANDLE_VALUE  ) return FALSE; // 無法取得. 
    COORD cc;
    cc.X = x;
    cc.Y = y;
    return SetConsoleCursorPosition( hOutput, cc ); // 設定cursor
}

int maze::random(int n) 
{
	return rand() % n; 
}
void maze::randomize() 
{
	srand ( (unsigned int)time(NULL) );
}
void maze::printxy( int x, int y, char *word )
{
   gotoxy( MAP_StartX + ( x * 2 ), MAP_StartY + y );
   cout << word;
   gotoxy( MAP_StartX + ( x * 2 ), MAP_StartY + y );
}


void maze::play( )
{	int MAP[SIZE][SIZE];
	int i, j;
										//initial

	for( i = 0; i < SIZE; i++ )
		for( j = 0; j < SIZE; j++ )
			MAP[i][j] = 0;
										//make border
	for( i = 0; i < SIZE; i++ )
	{
		MAP[0][i] = 1;
		MAP[SIZE-1][i] = 1;
		MAP[i][0] = 1;
		MAP[i][SIZE-1] = 1;
	}
	MAP[SIZE-2][SIZE-1] = 2;

	int xx, yy;       //random position
	int x_tmp, y_tmp; //backup position
	int dir;         //directory way
	int count;

	randomize();

	for( i = 0; i < 100; i++ )
	{
										//取偶數點
		xx = ( random( 12 ) + 1 ) * 2;
		yy = ( random( 12 ) + 1 ) * 2;
		x_tmp = xx;
		y_tmp = yy;

		if( MAP[xx][yy] == 0 )
		{
			do
			{
				count = 0;
				xx = x_tmp;
				yy = y_tmp;
				dir = random( 4 );
			   
				do
				{
					count = count + 1;
               
					switch ( dir )
					{
						case 0: 
							xx = xx - 1;
							break;
						case 1: 
							xx = xx + 1;
							break;
						case 2: 
							yy = yy + 1;
							break;
						case 3: 
							yy = yy - 1;
							break;
					}
				}
				while( MAP[xx][yy] != 1 ); // 確認是否已經碰到牆壁
			}
			while( count > SIZE ); //長度不能超過陣列-邊緣的長度否則會產生死路


			xx = x_tmp;
			yy = y_tmp;

			do
			{
				MAP[xx][yy] = 1;

				switch ( dir )
				{
					case 0: 
						xx = xx - 1;
						break;
					case 1: 
						xx = xx + 1;
						break;
					case 2: 
						yy = yy + 1;
						break;
					case 3: 
						yy = yy - 1;
						break;
				}
			}
			while( MAP[xx][yy] != 1 );
		}//if end
	}

	//============================================================================
	char key;
	int MAP_X, MAP_Y;
	int x, y;
	int times = 0;
	
	system("cls");
 
	for( MAP_Y = 0; MAP_Y < 25; MAP_Y++ ) 
	{
		for( MAP_X = 0; MAP_X < 25; MAP_X++ )
		{
			if( MAP[MAP_Y][MAP_X] == 1 )
			{
				gotoxy( MAP_StartX + MAP_X * 2, MAP_StartY + MAP_Y );
				cout << "■";
			}
		}
	}
	
	gotoxy(1,1);
	cout << "\n\n\n --逃出迷宮--\n\n 以方向鍵控制\n";

	gotoxy( MAP_StartX + ( StartX * 2 ), MAP_StartY + StartY );
	cout << "◎";
	gotoxy( MAP_StartX + ( StartX * 2 ), MAP_StartY + StartY );

	x = StartX;
	y = StartY;


	fflush(stdin); //清空緩衝區
    key=getch();

		
do
{
	fflush(stdin); //清空緩衝區
    key=getch();

			switch( key )
			{
			case 72: //上
				if(MAP[y-1][x]!=1)
				{
					printxy( x, y, "　" );
					y--;
					printxy( x, y, "◎" );
					times++;
				}
				break;
			
			case 80: //下
				if( MAP[y+1][x] != 1 )
				{
					printxy( x, y, "　" );
					y++;
					printxy( x, y, "◎" );
					times++;
				}
				break;
			
			case 75: //左
				if( MAP[y][x-1] != 1 )
				{
					printxy( x, y, "　" );
					x--;
					printxy( x, y, "◎" );
					times++;
				}
				break;
			
			case 77: //右
				if( MAP[y][x+1] != 1 )
				{
					printxy( x, y, "　" );
					x++;
					printxy( x, y, "◎" );
					times++;
				}
				break;
			
			default:
			break;
			}

if( key != EOF && MAP[y][x] != 2)
{
			if( times >=100)
			{
				gotoxy( 1, 1 );
				system("cls");
				cout<<"系統提示\n\t\t";
				cout << "超過步數限制，挑戰失敗!\n";
				system("pause");
				break;
			}
			else
			{
				gotoxy( 1, 1 );
				cout << "已走" << times << "步";
			}
}
else
{
	gotoxy( 1, 1 );
	        cout <<system("cls");
			cout << "\n 恭喜!逃出迷宮\n";
			system("pause");
			system("cls");
			cout<<"系統提示\n\t\t";
			cout<<"獲得20萬戒尼!!\n\n";
			money = money + 200000;
			system("pause");
			break;
}

}while(times<100);

}
	






