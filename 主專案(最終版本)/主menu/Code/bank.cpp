#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<windows.h>
#include"bank.h"
#include"data.h"

using namespace std;

int success4=0; //�s�����ƹF5��: �u�]��



bank::bank()
{}

bank::~bank()
{}


void bank::DW()
{

	srand((unsigned)time(NULL));
	double rate = (rand()%5)+1;
	char choice; //�~�ȿ��
	double num; //��J���B
	int out=0;    //�P�_���}���ܼ�
/*
	cout<<"�w��Ө즳���Ȧ�\n";
	cout<<"�ЮھڧA���ݨD��ܥH�U�~��\n";
	cout<<"<���ڶ�����O1000�٥�>";
	cout<<"<�����e�B�ʧQ�v:"<<rate<<"%";
	cout<<"\n\n";

	cout<<"<A>�d�ݱb��\n";
	cout<<"<S>�s��\n";
	cout<<"<W>���\n";
	cout<<"<Q>���}�Ȧ�\n\n";
	*/



do{

	system("cls");
	cout<<"�w��Ө즳���Ȧ�\n";
	cout<<"�ЮھڧA���ݨD��ܥH�U�~��\n";
	cout<<"<���ڶ��I����O10%>\n";
	cout<<"<�����e�B�ʧQ�v:"<<rate<<"%>";
	cout<<"\n\n";

	cout<<"<A>�d�ݱb��\n";
	cout<<"<S>�s��\n";
	cout<<"<W>���\n";
	cout<<"<Q>���}�Ȧ�\n\n";
	fflush(stdin);
	cin>>choice;


	if(choice=='S' || choice=='s')
	{
		cout<<"\n\n�п�J�A�n�s�i�����B:";
		cin>>num;
    do{
		if(num <= money && num>=0)
		{
			money = money - num;
			savingac = savingac + num + num*(rate/100);
			out++;
			success4++;
			cout<<"\n���Y����:"<<money<<endl;
	        cout<<"�b��l�B:"<<savingac<<endl;
			system("pause");
		}
		else if(num > money || num<0)
		{
		  while(num > money || num<0)
		  {
			  if(num>money){
			cout<<"\n���~!���B�W�L���Y����!"<<endl;
			cout<<"�Э��s��J���s�i�����B:";
			cin>>num;
			  }
			  else
			  {
			cout<<"\n���~!���B��J���X�k!"<<endl;
			cout<<"�Э��s��J���s�i�����B:";
			cin>>num;

			  }
		  } 
		}

	  }while(out==0);

	}
	else if(choice=='W' || choice=='w')
	{
		cout<<"�п�J�A�n���������B:";
		cin>>num;
    do{
		if(num <= savingac && num>=0)
		{
			money = money + num*0.9;
			savingac = savingac - num;
			out++;
			cout<<"\n���Y����:"<<money<<endl;
	        cout<<"�b��l�B:"<<savingac<<endl;
			system("pause");
		}
		else if(num > savingac || num<0)
		{
		  while(num > savingac || num<0)
		  {
			  if(num > savingac)
			  {
			cout<<"\n���~!���B�W�L�b��l�B!"<<endl;
			cout<<"�Э��s��J�����������B:";
			cin>>num;
			  }
			  else
			  {
			cout<<"\n���~!���B��J���X�k!"<<endl;
			cout<<"�Э��s��J�����������B:";
			cin>>num;
			  }

		  } 
		}

	  }while(out==0);

	}
	else if(choice=='A' || choice=='a')
	{
			cout<<"\n���Y����:"<<money<<endl;
	        cout<<"�b��l�B:"<<savingac<<endl;
			system("pause");

	}
	
}while(choice!='Q' && choice!='q');

	

}


		


