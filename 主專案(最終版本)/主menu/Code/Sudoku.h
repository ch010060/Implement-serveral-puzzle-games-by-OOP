#ifndef SUDOKU_H
#define SUDOKU_H
#include"data.h"
#include"Abstract.h"

using namespace std;

#define M_SIZE 9
#define M_MAX 9*9

class Sudoku : public data,public Abstract
{
public:
	Sudoku();
	~Sudoku();

	void InitBoard();  //�]�wboard
	int Stuff(const int &,const int &);  //��J
	void FullSudoku();	//���ͧ���ƿW�L��
	bool CheckEnd(int *);	

	int SolveSudoku(int *);	//�ѼƿW
	int DigSudoku();	//���}�X�D�k

	bool play();
	void show(int *)const;
	void equivalent();
	void play_a()    //override
	{
		if(ap>=5)
{

	cout<<"�o�̬O�������ԤB���w\n";
cout<<"�ȤH��!�w��A�Ӹ�Ū�ڭ̯����S�������ԤB��r!\n\n";

cout<<"���D����:\n";
cout<<"1.�C��Ʀr1~9�U���@�ӡA���o����\n";
cout<<"2.�C�C�Ʀr1~9�U���@�ӡA���o����\n";
cout<<"3.�C�ӤE�c�椺�Ʀr1~9�U���@�ӡA���o����\n";
cout<<"4.��J�榡: �C(x) �Ů� ��(y) �ƭ�(1~9)\n\n";
system("pause");


	while(!play())
  {
	
  }

	ap = ap-5;
}

else
{
	  cout<<"����I�Ƥ���!!�Ц^���O�\�U�i��ɵ�~\n";
	  system("pause");
}
	}

private:
	int m_mid;
	int m_col;
	int m_row;
	int m_ans;
	int same;

	int Board[M_MAX];
	int Solve[M_MAX];
	int Play[M_MAX];
};


#endif