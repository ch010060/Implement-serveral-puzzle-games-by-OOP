#include<iostream>
#include<conio.h>
#include<cstdio>
#include<cstdlib>
#include"data.h"
#include"shop.h"

using namespace std;

int success5=0; //�������I�\����5��: ����������


shop::shop()
{}

shop::~shop()
{}


void shop::shopmenu()
{


	int num,k=0; //�ʶR�ƶq,�j��P�w�Ѽ�
	char choice;
	cout<<"                       �^�_AP��   �ӶO����\n";
	cout<<"<A>�W�Ż��خM�\        10AP       10000�٥�\n\n";
	cout<<"<B>���q�g�ٮM�\        5AP        5000 �٥�\n\n";
	cout<<"<C>�������ൣ�M�\      3AP        3000 �٥�\n\n";
	cout<<"<Q>���}�ө�\n\n";

	cout<<"�п�J�A�n���\�I���N��:";
	cin>>choice;
	cout<<"\n\n";

do{
	if(choice=='A' || choice=='a')
	{
		cout<<"�п�J�A�n���\�I����:";
		cin>>num;

	  while(k==0)
	  {

		if(num*10000<=money)
		{
			money = money - num*10000;
			ap = ap + num*10;
			k++;


cout<<"\n\n";
cout<<"�{�b�֦�������:"<<money<<" �٥�"<<endl;
cout<<"�{�b������I��:"<<ap<<" �I"<<"\n\n";
system("pause");
			
		}
		else
		{
			while(num*10000>money)
			{
				cout<<"\n�A�����B����!!\n�Э��s��J�һݼƶq:";
				num=0;
				cin>>num;
			}
		}
	  }
	}


	if(choice=='B' || choice=='b')
	{
		cout<<"�п�J�A�n���\�I����:";
		cin>>num;

	  while(k==0)
	  {

		if(num*5000<=money)
		{
			money = money - num*5000;
			ap = ap + num*5;
			k++;


cout<<"\n\n";
cout<<"�{�b�֦�������:"<<money<<" �٥�"<<endl;
cout<<"�{�b������I��:"<<ap<<" �I"<<"\n\n";
system("pause");
			
		}
		else
		{
			while(num*5000>money)
			{
				cout<<"\n�A�����B����!!\n�Э��s��J�һݼƶq:";
				num=0;
				cin>>num;
			}
		}
	  }
	}



	if(choice=='C' || choice=='c')
	{
		cout<<"�п�J�A�n���\�I����:";
		cin>>num;

	  while(k==0)
	  {

		if(num*3000<=money)
		{
			money = money - num*3000;
			ap = ap + num*3;
			k++;


cout<<"\n\n";
cout<<"�{�b�֦�������:"<<money<<" �٥�"<<endl;
cout<<"�{�b������I��:"<<ap<<" �I"<<"\n\n";
success5 = success5 + num;
system("pause");

			
		}
		else
		{
			while(num*3000>money)
			{
				cout<<"\n�A�����B����!!\n�Э��s��J�һݼƶq:";
				num=0;
				cin>>num;
			}
		}
	  }
	}



}while(choice!='Q' && choice!='q' && k==0);





}









	
