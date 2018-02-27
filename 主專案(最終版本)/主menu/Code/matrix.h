#ifndef MATRIX_H
#define MATRIX_H
#include "data.h"
#include"Abstract.h"

using namespace std;

class matrix : public data,public Abstract
{
public:
	matrix();
	~matrix();

	void Play();
	void play_a()  //override
	{
		if(ap>=6)
		{
		Play();
		ap = ap-6;
		}
		else
		{
			cout<<"行動點數不足!!請回活力餐廳進行補給~\n";
		    system("pause");
		}
	}

};


#endif