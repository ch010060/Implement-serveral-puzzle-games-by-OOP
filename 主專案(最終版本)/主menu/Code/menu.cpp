#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include <windows.h>
#include <mmsystem.h>
#include"data.h"
#include"menu.h"
#include"menu_game.h"
#include"status.h"
#include"shop.h"
#include"picture.h"
#include"Save.h"
#include"Load.h"
#include"bank.h"
#include"success.h"
#include"Abstract.h"


#pragma comment(lib,"winmm.lib")

extern int life;  //0:生 1:死


//成就系統
extern int success1; //踩地雷過關3次: 地雷王
extern int success2; //巨石陣100步內通關: 神之手 
extern int success3; //巨石陣5次解不出: 打醬油會的會長
extern int success4; //存錢次數達5次: 守財奴
extern int success5; //麥噹噹點餐次數5次: 麥噹噹屁孩
//success 6 持有錢達80萬: 好野人 
//success 7 存款達80萬: 大富豪
//success 8 AP數值到達1000點: 行動魔人
//success 9 成就1+成就2皆達成: 神一般的存在
//success10 全成就達成(1~9): 至尊

int k1=0,k2=0,k3=0,k4=0,k5=0,k6=0,k7=0,k8=0,k9=0,k10=0; //1.確認成就提示只跑出一次 2.給成就清單檢驗參數





using namespace std;


menu::menu()
{}

menu::~menu()
{}


void menu::mainmenu()
{

char key;


system("color 07");



do{
system("cls");
cout<<"<Z>開始遊戲\n\n";
cout<<"<S>儲存記錄\n\n";
cout<<"<L>讀取記錄\n\n";
cout<<"<A>活力餐廳\n\n";
cout<<"<B>有間銀行\n\n";
cout<<"<I>玩家狀態\n\n";
cout<<"<E>成就列表\n\n";
cout<<"<Q>離開遊戲\n\n";

fflush(stdin);  //清空緩衝區
key=getch();
switch(key)
{
case 'Z':
case 'z':
gamemenu();
break;

case 'S':
case 's':
	S_ave();
	system("cls");
	cout<<"已存檔囉!\n\a\a";
	system("pause");
break;

case 'L':
case 'l':
	L_oad();
	system("cls");
	cout<<"已載入記錄囉!\n\a\a";
	system("pause");
break;

case 'A':
case 'a':
system("cls");
shopmenu();
break;


case 'B':
case 'b':
system("cls");
DW();
break;

case 'I':
case 'i':
system("cls");
printstatus();
break;

case 'E':
case 'e':
system("cls");
sprint();
break;

default:
break;
}




//成就系統 1~5  class個別判斷   
//         6~10 menu內判斷

//success 1 踩地雷過關3次: 地雷王
if(success1>=3 && k1==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 地雷王\n";
	system("pause");
	k1++;
}

//success 2 巨石陣100步內通關: 神之手
if(success2>=1 && k2==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 神之手\n";
	system("pause");
	k2++;
}

//success 3 巨石陣3次解不出: 打醬油會的會長
if(success3>=3 && k3==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 打醬油會的會長\n";
	system("pause");
	k3++;
}

//success 4 存錢次數達5次: 守財奴
if(success4>=5 && k4==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 守財奴\n";
	system("pause");
	k4++;
}

//success 5 麥噹噹點餐次數5次: 麥噹噹屁孩
if(success5>=5 && k5==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 麥噹噹屁孩\n";
	system("pause");
	k5++;
}

//success 6 持有錢達80萬: 好野人
if(money>=800000 && k6==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 好野人\n";
	system("pause");
	k6++;
}

//success 7 存款達80萬: 大富豪
if(savingac>=800000 && k7==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 大富翁\n";
	system("pause");
	k7++;
}
//success 8 AP數值到達1000點: 行動魔人
if(ap>=1000 && k8==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 行動魔人\n";
	system("pause");
	k8++;
}

//success 9 成就1+成就2皆達成: 神一般的存在
if(k1>0 && k2>0 && k9==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 神一般的存在\n";
	system("pause");
	k9++;
}

//success10 全成就達成(1~9): 至尊
if(k1>0 && k2>0 && k3>0 && k4>0 && k5>0 && k6>0 && k7>0 && k8>0 && k9>0 && k10==0)
{
	system("cls");
	cout<<"系統提示:\n\t\t";
	cout<<"獲得稱號: 神一般的存在\n";
	system("pause");
	k10++;
}






if(k10>0 || life>0)
{
	key='Q';
}


}while(key!='Q' && key!='q' );


//破關  和  game over判斷
//破關條件版本1 if((money + savingac)>=1000000) → 所有錢>=1百萬
if(k10>0)  //破關條件版本2  →  全成就達成
{
system("cls");
pprint();
}


if(life==0)
	{
		exit(0);
	}


else if(life>0)  //game over
{
	system("cls");
	cout<<"系統提示:\t\t\t\n";
	cout<<"玩家已死亡!!\n\n";
	life=0;  //初始化生命參數
	money = money/2;
	savingac = savingac/2;
	
	
}



}

