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
	cout<<"�w��Ө�@�ɮȹC�j�@��!!\n";
	cout<<"�п�J�A���j�W:";
	cin>>Name;
	setdata.setplayername(Name);

do{
	menu *start;
	QB *qb;

	start->mainmenu();

	
	do{

		
	system("cls");
	cout<<"�t�δ���:\t\t\t\n";
	cout<<"���a�w���`!!\n\n";
	qb->printQB();
	cout<<"\n<�i�~�Ӫ��a���`�e����ơA�������P�b��l�B��b>\n�а�"<<Name<<"�j�j�A�A�nñ���A���@����?(Y/N)\n";
	cin>>choice;
	
		
	}while(choice!='Y' && choice!='y' && choice!='N' && choice!='n');

	

}while(choice!='N' && choice!='n');
	

	system("pause");
	return 0;
}