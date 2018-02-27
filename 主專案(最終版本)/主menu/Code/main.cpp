#include<iostream>
#include<cstring>
#include"matrix.h"
#include"menu.h"
#include"picture.h"
#include"data.h"
#include"Abstract.h"
#include"QB.h"

using namespace std;

extern int life;



int main()
{

	char choice;

	
	
	char *Name=new char [10];
	data setdata;
	system("cls");
	cout<<"歡迎來到世界旅遊大作戰!!\n";
	cout<<"請輸入你的大名:";
	cin>>Name;
	setdata.setplayername(Name);

do{
	menu *start;
	QB *qb;

	start->mainmenu();

	
	do{

		
	system("cls");
	cout<<"系統提示:\t\t\t\n";
	cout<<"玩家已死亡!!\n\n";
	qb->printQB();
	cout<<"\n<可繼承玩家死亡前的資料，但金錢與帳戶餘額減半>\n請問"<<Name<<"大大，你要簽約再玩一次嗎?(Y/N)\n";
	cin>>choice;
	
		
	}while(choice!='Y' && choice!='y' && choice!='N' && choice!='n');

	

}while(choice!='N' && choice!='n');
	

	system("pause");
	return 0;
}