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

          cout<<"�n�䪺���z�u����A�@�N���ѧA�@�~�����K�O���z�I\n";
          cout<<"������O�A�����n�q���L�w���]�Q���Ʀr�C\n";
          cout<<"�u�z�p���K�����|�A�o�o�o�I\n";
          cout<<"                �ϥ��A�]�q����IXDD�v\n\n";
		  system("pause");
		  system("cls");


		play();
		ap = ap-3;
	  }
	  else
	  {
		  cout<<"����I�Ƥ���!!�Ц^���O�\�U�i��ɵ�~\n";
		  system("pause");
	  }
	}

	void play();

};

#endif