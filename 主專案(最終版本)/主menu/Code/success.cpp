#include<iostream>
#include"success.h"
using namespace std;


extern int k1;
extern int k2;
extern int k3;
extern int k4;
extern int k5;
extern int k6;
extern int k7;
extern int k8;
extern int k9;
extern int k10;


success::success()
{}


success::~success()
{}


//success 1 踩地雷過關3次: 地雷王
//success 2 巨石陣100步內通關: 神之手 
//success 3 巨石陣3次解不出: 打醬油會的會長
//success 4 存錢次數達5次: 守財奴
//success 5 麥噹噹點餐次數5次: 麥噹噹屁孩
//success 6 持有錢達80萬: 好野人 
//success 7 存款達80萬: 大富豪
//success 8 AP數值到達1000點: 行動魔人
//success 9 成就1+成就2皆達成: 神一般的存在
//success10 全成就達成(1~9): 至尊

void success::sprint()
{

	cout<<"成就稱號列表:\n\n";
	cout<<"稱號1:";
	if(k1>0)
	{
		cout<<"地雷王\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號2:";
	if(k2>0)
	{
		cout<<"神之手\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號3:";
	if(k3>0)
	{
		cout<<"打醬油會的會長\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號4:";
	if(k4>0)
	{
		cout<<"守財奴\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號5:";
	if(k5>0)
	{
		cout<<"麥噹噹屁孩\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號6:";
	if(k6>0)
	{
		cout<<"好野人\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號7:";
	if(k7>0)
	{
		cout<<"大富豪\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號8:";
	if(k8>0)
	{
		cout<<"行動魔人\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號9:";
	if(k9>0)
	{
		cout<<"神一般的存在\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	cout<<"稱號10:";
	if(k10>0)
	{
		cout<<"至尊\n";
	}
	else
	{
		cout<<"<待解出>\n";
	}

	system("pause");


}








	

