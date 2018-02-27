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

	void InitBoard();  //設定board
	int Stuff(const int &,const int &);  //填入
	void FullSudoku();	//產生完整數獨盤面
	bool CheckEnd(int *);	

	int SolveSudoku(int *);	//解數獨
	int DigSudoku();	//挖洞出題法

	bool play();
	void show(int *)const;
	void equivalent();
	void play_a()    //override
	{
		if(ap>=5)
{

	cout<<"這裡是熱情的拉丁美洲\n";
cout<<"旅人啊!歡迎你來解讀我們神秘又複雜的拉丁文字!\n\n";

cout<<"解題說明:\n";
cout<<"1.每行數字1~9各有一個，不得重複\n";
cout<<"2.每列數字1~9各有一個，不得重複\n";
cout<<"3.每個九宮格內數字1~9各有一個，不得重複\n";
cout<<"4.輸入格式: 列(x) 空格 行(y) 數值(1~9)\n\n";
system("pause");


	while(!play())
  {
	
  }

	ap = ap-5;
}

else
{
	  cout<<"行動點數不足!!請回活力餐廳進行補給~\n";
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