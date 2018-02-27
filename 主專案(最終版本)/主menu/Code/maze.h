#ifndef MAZE_H
#define MAZE_H
#include"data.h"
#include"Abstract.h"
using namespace std;

class maze : public data,public Abstract
{
public:
	maze();
	~maze();

	void play_a()  //override
	{
	  if(ap>=10)
	  {

		  cout<<"為了閃躲埃及聖地的守護者，你闖進了金字塔的地下迷宮。\n";
          cout<<"雖然這裡充滿了炫目的金銀財寶，但你卻沒有時間逗留。\n";
          cout<<"留心你的每個步伐，否則的神聖的法老以及鱷魚神都將會甦醒。\n\n";
		  system("pause");
		  system("cls");



		play( );
		ap = ap-10;
	  }
	  else
	  {
		  cout<<"行動點數不足!!請回活力餐廳進行補給~\n";
		  system("pause");
	  }
	}

	void printxy( int x, int y, char *word );
	void play( );
	int random( int );
	void randomize();


};

#endif