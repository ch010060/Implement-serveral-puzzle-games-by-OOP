#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include"data.h"
#include"shop.h"

using namespace std;

int success5=0; //麥噹噹點餐次數5次: 麥噹噹屁孩


shop::shop()
{}

shop::~shop()
{}


void shop::shopmenu()
{


	int num,k=0; //購買數量,迴圈判定參數
	char choice;
	cout<<"                       回復AP數   耗費金錢\n";
	cout<<"<A>超級豪華套餐        10AP       10000戒尼\n\n";
	cout<<"<B>普通經濟套餐        5AP        5000 戒尼\n\n";
	cout<<"<C>麥噹噹兒童套餐      3AP        3000 戒尼\n\n";
	cout<<"<Q>離開商店\n\n";

	cout<<"請輸入你要的餐點的代號:";
	cin>>choice;
	cout<<"\n\n";

do{
	if(choice=='A' || choice=='a')
	{
		cout<<"請輸入你要的餐點份數:";
		cin>>num;

	  while(k==0)
	  {

		if(num*10000<=money)
		{
			money = money - num*10000;
			ap = ap + num*10;
			k++;


cout<<"\n\n";
cout<<"現在擁有的金錢:"<<money<<" 戒尼"<<endl;
cout<<"現在的行動點數:"<<ap<<" 點"<<"\n\n";
system("pause");
			
		}
		else
		{
			while(num*10000>money)
			{
				cout<<"\n你的金額不足!!\n請重新輸入所需數量:";
				num=0;
				cin>>num;
			}
		}
	  }
	}


	if(choice=='B' || choice=='b')
	{
		cout<<"請輸入你要的餐點份數:";
		cin>>num;

	  while(k==0)
	  {

		if(num*5000<=money)
		{
			money = money - num*5000;
			ap = ap + num*5;
			k++;


cout<<"\n\n";
cout<<"現在擁有的金錢:"<<money<<" 戒尼"<<endl;
cout<<"現在的行動點數:"<<ap<<" 點"<<"\n\n";
system("pause");
			
		}
		else
		{
			while(num*5000>money)
			{
				cout<<"\n你的金額不足!!\n請重新輸入所需數量:";
				num=0;
				cin>>num;
			}
		}
	  }
	}



	if(choice=='C' || choice=='c')
	{
		cout<<"請輸入你要的餐點份數:";
		cin>>num;

	  while(k==0)
	  {

		if(num*3000<=money)
		{
			money = money - num*3000;
			ap = ap + num*3;
			k++;


cout<<"\n\n";
cout<<"現在擁有的金錢:"<<money<<" 戒尼"<<endl;
cout<<"現在的行動點數:"<<ap<<" 點"<<"\n\n";
success5 = success5 + num;
system("pause");

			
		}
		else
		{
			while(num*3000>money)
			{
				cout<<"\n你的金額不足!!\n請重新輸入所需數量:";
				num=0;
				cin>>num;
			}
		}
	  }
	}



}while(choice!='Q' && choice!='q' && k==0);





}









	
