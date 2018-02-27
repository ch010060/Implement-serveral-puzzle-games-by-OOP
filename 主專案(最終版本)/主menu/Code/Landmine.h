#ifndef LAND_H
#define LAND_H
#define MAPSIZE 10
#define BOOM 10
#include "data.h"
#include"Abstract.h"

using namespace std;


class Landmine : public data,public Abstract
{
public:
        Landmine();
		~Landmine();
		void play_a()  //override
		{
			if(ap>=10)
	{
		cout<<"歡迎來到北韓，相信踩地雷能讓你有個美好的回憶!\n";
		cout<<"< 輸入格式:位置(空格)位置 (x-y座標系統) >\n\n";
		system("pause");
		system("cls");
	playLandmine();
	showMap_();
    gameStart();
	ap = ap-10;
	}
	else
	{
		cout<<"行動點數不足!!請回活力餐廳進行補給~\n";
		system("pause");
	}

		}
		void playLandmine();
        void setBoom();
        void showMap_();
        void showMap();
        void gameStart();
        void open(int ,int );
private:
        char map[MAPSIZE][MAPSIZE];
        int mapMask[MAPSIZE][MAPSIZE];
};

#endif