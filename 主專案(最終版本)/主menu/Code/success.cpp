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


//success 1 ��a�p�L��3��: �a�p��
//success 2 ���۰}100�B���q��: ������ 
//success 3 ���۰}3���Ѥ��X: ����o�|���|��
//success 4 �s�����ƹF5��: �u�]��
//success 5 �������I�\����5��: ����������
//success 6 �������F80�U: �n���H 
//success 7 �s�ڹF80�U: �j�I��
//success 8 AP�ƭȨ�F1000�I: ����]�H
//success 9 ���N1+���N2�ҹF��: ���@�몺�s�b
//success10 �����N�F��(1~9): �ܴL

void success::sprint()
{

	cout<<"���N�ٸ��C��:\n\n";
	cout<<"�ٸ�1:";
	if(k1>0)
	{
		cout<<"�a�p��\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�2:";
	if(k2>0)
	{
		cout<<"������\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�3:";
	if(k3>0)
	{
		cout<<"����o�|���|��\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�4:";
	if(k4>0)
	{
		cout<<"�u�]��\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�5:";
	if(k5>0)
	{
		cout<<"����������\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�6:";
	if(k6>0)
	{
		cout<<"�n���H\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�7:";
	if(k7>0)
	{
		cout<<"�j�I��\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�8:";
	if(k8>0)
	{
		cout<<"����]�H\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�9:";
	if(k9>0)
	{
		cout<<"���@�몺�s�b\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	cout<<"�ٸ�10:";
	if(k10>0)
	{
		cout<<"�ܴL\n";
	}
	else
	{
		cout<<"<�ݸѥX>\n";
	}

	system("pause");


}








	

