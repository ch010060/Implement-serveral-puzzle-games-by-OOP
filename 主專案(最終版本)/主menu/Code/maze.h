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

		  cout<<"���F�{���J�θt�a���u�@�̡A�A���i�F���r�𪺦a�U�g�c�C\n";
          cout<<"���M�o�̥R���F���ت����Ȱ]�_�A���A�o�S���ɶ��r�d�C\n";
          cout<<"�d�ߧA���C�ӨB��A�_�h�����t���k�ѥH���s�������N�|�d���C\n\n";
		  system("pause");
		  system("cls");



		play( );
		ap = ap-10;
	  }
	  else
	  {
		  cout<<"����I�Ƥ���!!�Ц^���O�\�U�i��ɵ�~\n";
		  system("pause");
	  }
	}

	void printxy( int x, int y, char *word );
	void play( );
	int random( int );
	void randomize();


};

#endif