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
			cout<<"����I�Ƥ���!!�Ц^���O�\�U�i��ɵ�~\n";
		    system("pause");
		}
	}

};


#endif