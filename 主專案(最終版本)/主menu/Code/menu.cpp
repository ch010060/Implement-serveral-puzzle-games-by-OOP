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

extern int life;  //0:�� 1:��


//���N�t��
extern int success1; //��a�p�L��3��: �a�p��
extern int success2; //���۰}100�B���q��: ������ 
extern int success3; //���۰}5���Ѥ��X: ����o�|���|��
extern int success4; //�s�����ƹF5��: �u�]��
extern int success5; //�������I�\����5��: ����������
//success 6 �������F80�U: �n���H 
//success 7 �s�ڹF80�U: �j�I��
//success 8 AP�ƭȨ�F1000�I: ����]�H
//success 9 ���N1+���N2�ҹF��: ���@�몺�s�b
//success10 �����N�F��(1~9): �ܴL

int k1=0,k2=0,k3=0,k4=0,k5=0,k6=0,k7=0,k8=0,k9=0,k10=0; //1.�T�{���N���ܥu�]�X�@�� 2.�����N�M������Ѽ�





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
cout<<"<Z>�}�l�C��\n\n";
cout<<"<S>�x�s�O��\n\n";
cout<<"<L>Ū���O��\n\n";
cout<<"<A>���O�\�U\n\n";
cout<<"<B>�����Ȧ�\n\n";
cout<<"<I>���a���A\n\n";
cout<<"<E>���N�C��\n\n";
cout<<"<Q>���}�C��\n\n";

fflush(stdin);  //�M�Žw�İ�
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
	cout<<"�w�s���o!\n\a\a";
	system("pause");
break;

case 'L':
case 'l':
	L_oad();
	system("cls");
	cout<<"�w���J�O���o!\n\a\a";
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




//���N�t�� 1~5  class�ӧO�P�_   
//         6~10 menu���P�_

//success 1 ��a�p�L��3��: �a�p��
if(success1>=3 && k1==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: �a�p��\n";
	system("pause");
	k1++;
}

//success 2 ���۰}100�B���q��: ������
if(success2>=1 && k2==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: ������\n";
	system("pause");
	k2++;
}

//success 3 ���۰}3���Ѥ��X: ����o�|���|��
if(success3>=3 && k3==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: ����o�|���|��\n";
	system("pause");
	k3++;
}

//success 4 �s�����ƹF5��: �u�]��
if(success4>=5 && k4==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: �u�]��\n";
	system("pause");
	k4++;
}

//success 5 �������I�\����5��: ����������
if(success5>=5 && k5==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: ����������\n";
	system("pause");
	k5++;
}

//success 6 �������F80�U: �n���H
if(money>=800000 && k6==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: �n���H\n";
	system("pause");
	k6++;
}

//success 7 �s�ڹF80�U: �j�I��
if(savingac>=800000 && k7==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: �j�I��\n";
	system("pause");
	k7++;
}
//success 8 AP�ƭȨ�F1000�I: ����]�H
if(ap>=1000 && k8==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: ����]�H\n";
	system("pause");
	k8++;
}

//success 9 ���N1+���N2�ҹF��: ���@�몺�s�b
if(k1>0 && k2>0 && k9==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: ���@�몺�s�b\n";
	system("pause");
	k9++;
}

//success10 �����N�F��(1~9): �ܴL
if(k1>0 && k2>0 && k3>0 && k4>0 && k5>0 && k6>0 && k7>0 && k8>0 && k9>0 && k10==0)
{
	system("cls");
	cout<<"�t�δ���:\n\t\t";
	cout<<"��o�ٸ�: ���@�몺�s�b\n";
	system("pause");
	k10++;
}






if(k10>0 || life>0)
{
	key='Q';
}


}while(key!='Q' && key!='q' );


//�}��  �M  game over�P�_
//�}�����󪩥�1 if((money + savingac)>=1000000) �� �Ҧ���>=1�ʸU
if(k10>0)  //�}�����󪩥�2  ��  �����N�F��
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
	cout<<"�t�δ���:\t\t\t\n";
	cout<<"���a�w���`!!\n\n";
	life=0;  //��l�ƥͩR�Ѽ�
	money = money/2;
	savingac = savingac/2;
	
	
}



}

