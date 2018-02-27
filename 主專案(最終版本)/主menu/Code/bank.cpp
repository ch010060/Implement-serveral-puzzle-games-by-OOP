#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include"bank.h"
#include"data.h"

using namespace std;

int success4=0; //存錢次數達5次: 守財奴



bank::bank()
{}

bank::~bank()
{}


void bank::DW()
{

	srand((unsigned)time(NULL));
	double rate = (rand()%5)+1;
	char choice; //業務選擇
	double num; //輸入金額
	int out=0;    //判斷離開的變數
/*
	cout<<"歡迎來到有間銀行\n";
	cout<<"請根據你的需求選擇以下業務\n";
	cout<<"<取款須手續費1000戒尼>";
	cout<<"<本行當前浮動利率:"<<rate<<"%";
	cout<<"\n\n";

	cout<<"<A>查看帳戶\n";
	cout<<"<S>存錢\n";
	cout<<"<W>領錢\n";
	cout<<"<Q>離開銀行\n\n";
	*/



do{

	system("cls");
	cout<<"歡迎來到有間銀行\n";
	cout<<"請根據你的需求選擇以下業務\n";
	cout<<"<取款須付手續費10%>\n";
	cout<<"<本行當前浮動利率:"<<rate<<"%>";
	cout<<"\n\n";

	cout<<"<A>查看帳戶\n";
	cout<<"<S>存錢\n";
	cout<<"<W>領錢\n";
	cout<<"<Q>離開銀行\n\n";
	fflush(stdin);
	cin>>choice;


	if(choice=='S' || choice=='s')
	{
		cout<<"\n\n請輸入你要存進的金額:";
		cin>>num;
    do{
		if(num <= money && num>=0)
		{
			money = money - num;
			savingac = savingac + num + num*(rate/100);
			out++;
			success4++;
			cout<<"\n手頭金錢:"<<money<<endl;
	        cout<<"帳戶餘額:"<<savingac<<endl;
			system("pause");
		}
		else if(num > money || num<0)
		{
		  while(num > money || num<0)
		  {
			  if(num>money){
			cout<<"\n錯誤!金額超過手頭金錢!"<<endl;
			cout<<"請重新輸入欲存進的金額:";
			cin>>num;
			  }
			  else
			  {
			cout<<"\n錯誤!金額輸入不合法!"<<endl;
			cout<<"請重新輸入欲存進的金額:";
			cin>>num;

			  }
		  } 
		}

	  }while(out==0);

	}
	else if(choice=='W' || choice=='w')
	{
		cout<<"請輸入你要提取的金額:";
		cin>>num;
    do{
		if(num <= savingac && num>=0)
		{
			money = money + num*0.9;
			savingac = savingac - num;
			out++;
			cout<<"\n手頭金錢:"<<money<<endl;
	        cout<<"帳戶餘額:"<<savingac<<endl;
			system("pause");
		}
		else if(num > savingac || num<0)
		{
		  while(num > savingac || num<0)
		  {
			  if(num > savingac)
			  {
			cout<<"\n錯誤!金額超過帳戶餘額!"<<endl;
			cout<<"請重新輸入欲提取的金額:";
			cin>>num;
			  }
			  else
			  {
			cout<<"\n錯誤!金額輸入不合法!"<<endl;
			cout<<"請重新輸入欲提取的金額:";
			cin>>num;
			  }

		  } 
		}

	  }while(out==0);

	}
	else if(choice=='A' || choice=='a')
	{
			cout<<"\n手頭金錢:"<<money<<endl;
	        cout<<"帳戶餘額:"<<savingac<<endl;
			system("pause");

	}
	
}while(choice!='Q' && choice!='q');

	

}


		


