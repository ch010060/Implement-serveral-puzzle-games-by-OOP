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

	cout<<"���a�m�W:"<<data::playername<<endl;
	cout<<"��������:"<<money<<" �٥�"<<endl;
	cout<<"����I��:"<<ap<<" �I"<<endl;
	cout<<"�b��l�B:"<<savingac<<" �٥�"<<endl;
	system("pause");

}
	