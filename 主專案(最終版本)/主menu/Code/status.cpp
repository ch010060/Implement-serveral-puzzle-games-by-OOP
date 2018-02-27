#include<iostream>
#include"status.h"
#include"data.h"
#include"bank.h"

using namespace std;

status::status()
{}

status::~status()
{}


void status::printstatus()
{

	cout<<"玩家姓名:"<<data::playername<<endl;
	cout<<"持有金錢:"<<money<<" 戒尼"<<endl;
	cout<<"行動點數:"<<ap<<" 點"<<endl;
	cout<<"帳戶餘額:"<<savingac<<" 戒尼"<<endl;
	system("pause");

}
	