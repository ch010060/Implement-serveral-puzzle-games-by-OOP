#ifndef CODE_H
#define CODE_H
#include<iostream>
#include "Abstract.h"
#include "data.h"
using namespace std;


class code : public data,public Abstract
{
public:
	code();
	~code();

	void play_a()  //override
	{
	  if(ap>=3)
	  {

          cout<<"好賭的香腸攤老闆，願意提供你一年份的免費香腸！\n";
          cout<<"但條件是，必須要猜中他預先設想的數字。\n";
          cout<<"「哇厚哩八次機會，發發發！\n";
          cout<<"                反正你也猜不到！XDD」\n\n";
		  system("pause");
		  system("cls");


		play();
		ap = ap-3;
	  }
	  else
	  {
		  cout<<"行動點數不足!!請回活力餐廳進行補給~\n";
		  system("pause");
	  }
	}

	void play();

};

#endif