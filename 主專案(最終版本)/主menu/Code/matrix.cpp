/*##########�o�O�Ʀr���###########*/
#include <iostream>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include"matrix.h"
#include "data.h"
#include"Abstract.h"
using namespace std;

int success2; //���۰}100�B���q��: ������ 
int success3; //���۰}5���Ѥ��X: ����o�|���|��

matrix::matrix()
{}

matrix::~matrix()
{}


void matrix::Play()
{

	srand((unsigned int)time(NULL));
char a[9]={0,0,0,0,0,0,0,0,0};
int b,c,temp,times=0;
do{
for(b='8';b>='0';b--) 
a[(c=rand()%9)]==0?a[c]=b:b++;    //�Y�O0�h�t�Ʀr�A�Y���O�h��b�[�^�A�Y���t
a[c]=' ';                         //�̫�@�ӨS�t�쪺��m�t�Ů�



}while((a[0]=='1' && a[1]=='2' && a[2]=='3' && a[3]=='4' && a[4]=='5' && a[5]=='6' &&  a[6]=='7' && a[7]=='8') || 
	   (a[0]=='1' && a[1]=='4' && a[2]=='7' && a[3]=='2' && a[4]=='5' && a[5]=='8' &&  a[6]=='3' && a[7]=='6') );

/* �Ĥ@����ܪ��� (���p)
for(b=0;b<9;b++)
cout<<setw(3)<<(char)a[b]<<setw(3)<<(b%3==2?'\n':' ');
*/
/* ���k2
cout<<"�C������:\n�u�n�L�������H�U����Y�i�q��\n1.�P��[�_�Ӭ�3������\n2.�P�C�[�_�Ӭ�3������\n3.����﨤�u�W�[�_�Ӭ�3������\n";
*/

if(ap>=3){

ap = ap-3; //����I��-3
cout<<"�w��A�Ө�^�ꥨ�۰}\n�ǻD���j���W��8�ӯ��������ۡA�u�n�⥦�̷̨ӯS�w���W�h�ƦC\n�N�i�H��o���æb��񤤪��K�_\n\n";
system("pause");
system("cls");
cout<<"�i�̪�!�[�o�a!\n\n";
system("pause");
system("cls");
cout<<"��������:\n�u�n�L�������H�U����Y�i�q��\n1.�k��Ʀr����Ʀr�j\n2.�U���Ʀr��W���Ʀr�j\n3.�P��[�_�Ӭ�3������\n4.�P�C�[�_�Ӭ�3������\n5.�k�U�����Ů�\n";

system("pause");
system("cls");  //���
cout<<"��l�L��\n\n";


	cout<<setw(10)<<(char)a[0]<<setw(10)<<(char)a[1]<<setw(10)<<(char)a[2];
    cout<<"\n\n\n\n";
	cout<<setw(10)<<(char)a[3]<<setw(10)<<(char)a[4]<<setw(10)<<(char)a[5];
	cout<<"\n\n\n\n";
	cout<<setw(10)<<(char)a[6]<<setw(10)<<(char)a[7]<<setw(10)<<(char)a[8];
	cout<<"\n\n\n\n";

char key;

while(!((a[0]=='1' && a[1]=='2' && a[2]=='3' && a[3]=='4' && a[4]=='5' && a[5]=='6' &&  a[6]=='7' && a[7]=='8') || 
	  (a[0]=='1' && a[1]=='4' && a[2]=='7' && a[3]=='2' && a[4]=='5' && a[5]=='8' &&  a[6]=='3' && a[7]=='6') || times>=500) )                                                      
{                                                                                      

/* ���k2
while(!((a[0]+a[1]+a[2])%3==0 && (a[3]+a[4]+a[5])%3==0 && (a[6]+a[7]+a[8])%3==0 &&
      (a[0]+a[3]+a[6])%3==0 && (a[1]+a[4]+a[7])%3==0 && (a[2]+a[5]+a[8])%3==0 &&
	  (a[0]+a[4]+a[8])%3==0 && (a[2]+a[4]+a[6])%3==0 ))                                                          
{ 
*/
fflush(stdin); //�M�Žw�İ�
key=getch();
switch(key)
{
case 80:if(c>2)temp=a[c],a[c]=a[c-3],a[c=c-3]=temp,times++;break;              //down  �p�G�O��2 3��
case 72:if(c<6)temp=a[c],a[c]=a[c+3],a[c=c+3]=temp,times++;break;              //up    �p�G�O��1 2��
case 77:if(c!=0&&c!=3&&c!=6)temp=a[c],a[c]=a[c-1],a[c=c-1]=temp,times++;break; //right �p�G���O�̥���
case 75:if(c!=2&&c!=5&&c!=8)temp=a[c],a[c]=a[c+1],a[c=c+1]=temp,times++;break; //left  �p�G���O�̥k��
case 'g':case 'G':  cout<<"\n\n�ѵ�1:\n1 2 3\n4 5 6\n7 8\n\n�ѵ�2:\n1 4 7\n2 5 8\n3 6  \n"<<endl; system("pause"); break;
}
system("cls");  //���

   
    cout<<"\n\n";
	cout<<setw(10)<<(char)a[0]<<setw(10)<<(char)a[1]<<setw(10)<<(char)a[2];
    cout<<"\n\n\n\n";
	cout<<setw(10)<<(char)a[3]<<setw(10)<<(char)a[4]<<setw(10)<<(char)a[5];
	cout<<"\n\n\n\n";
	cout<<setw(10)<<(char)a[6]<<setw(10)<<(char)a[7]<<setw(10)<<(char)a[8];
	cout<<"\n\n\n\n";


cout<<"��"<<times<<"�B";



}





if(times<100)
{
	money = money + 100000;
	cout<<"\r�@��F"<<times<<"�B����\n\n";
	cout<<"�A�ڥ��N�O����A�s�A�����j�j!\n\n";

	system("pause");
	system("cls");
	success2++;
	cout<<"�t�δ���:\n\t\t\t";
	cout<<"��o���y10�U�٥�!!\n";
}
else if(times>=100 && times<150)
{
	money = money + 80000;
	cout<<"\r�@��F"<<times<<"�B����\n\n";
	cout<<"�A�ڥ��N�O�����F�H�A�����!\n";

	system("pause");
	system("cls");
	cout<<"�t�δ���:\n\t\t\t";
	cout<<"��o���y8�U�٥�!!\n";
}

else if(times>=150 && times<300)
{
	money = money + 50000;
	cout<<"\r�@��F"<<times<<"�B����\n\n";
	cout<<"�޿��ү�O��j����!\n";


	system("pause");
	system("cls");
	cout<<"�t�δ���:\n\t\t\t";
	cout<<"��o���y5�U�٥�!!\n";
}
else if(times>=300 && times<500)
{
	money = money + 30000;
	cout<<"\r�@��F"<<times<<"�B����\n\n";
	cout<<"���߸������\�A���L�٦��i�B�Ŷ���!\n";

	system("pause");
	system("cls");
	cout<<"�t�δ���:\n\t\t\t";
	cout<<"��o���y3�U�٥�!!\n";
}
else 
{
	cout<<"\n\n�i���W�L�B�ƭ����o�A�Э��s�ӹL�A���A�y�a!!!\n";
	success3++;

}


}

else if(ap<3)
{
	cout<<"����I�Ƥ���!!�Ц^���O�\�U�i��ɵ�~\n";
	system("pause");
}



system("pause");               

}

/*
void matrix::play_a()
{
	Play();
                    
} 
*/