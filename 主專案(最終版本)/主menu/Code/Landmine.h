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
		cout<<"�w��Ө�_���A�۫H��a�p�����A���Ӭ��n���^��!\n";
		cout<<"< ��J�榡:��m(�Ů�)��m (x-y�y�Шt��) >\n\n";
		system("pause");
		system("cls");
	playLandmine();
	showMap_();
    gameStart();
	ap = ap-10;
	}
	else
	{
		cout<<"����I�Ƥ���!!�Ц^���O�\�U�i��ɵ�~\n";
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