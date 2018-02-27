/*##########這是數字方塊###########*/
#include <iostream>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include"matrix.h"
#include "data.h"
#include"Abstract.h"
using namespace std;

int success2; //巨石陣100步內通關: 神之手 
int success3; //巨石陣5次解不出: 打醬油會的會長

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
a[(c=rand()%9)]==0?a[c]=b:b++;    //若是0則配數字，若不是則把b加回，即重配
a[c]=' ';                         //最後一個沒配到的位置配空格



}while((a[0]=='1' && a[1]=='2' && a[2]=='3' && a[3]=='4' && a[4]=='5' && a[5]=='6' &&  a[6]=='7' && a[7]=='8') || 
	   (a[0]=='1' && a[1]=='4' && a[2]=='7' && a[3]=='2' && a[4]=='5' && a[5]=='8' &&  a[6]=='3' && a[7]=='6') );

/* 第一種顯示版本 (偏小)
for(b=0;b<9;b++)
cout<<setw(3)<<(char)a[b]<<setw(3)<<(b%3==2?'\n':' ');
*/
/* 玩法2
cout<<"遊戲說明:\n只要盤面滿足以下條件即可通關\n1.同行加起來為3的倍數\n2.同列加起來為3的倍數\n3.單條對角線上加起來為3的倍數\n";
*/

if(ap>=3){

ap = ap-3; //行動點數-3
cout<<"歡迎你來到英國巨石陣\n傳聞中大草原上有8個神祕的巨石，只要把它們依照特定的規則排列\n就可以獲得隱藏在遺跡中的密寶\n\n";
system("pause");
system("cls");
cout<<"勇者阿!加油吧!\n\n";
system("pause");
system("cls");
cout<<"解謎說明:\n只要盤面滿足以下條件即可通關\n1.右邊數字比左邊數字大\n2.下面數字比上面數字大\n3.同行加起來為3的倍數\n4.同列加起來為3的倍數\n5.右下角為空格\n";

system("pause");
system("cls");  //刷屏
cout<<"初始盤面\n\n";


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

/* 玩法2
while(!((a[0]+a[1]+a[2])%3==0 && (a[3]+a[4]+a[5])%3==0 && (a[6]+a[7]+a[8])%3==0 &&
      (a[0]+a[3]+a[6])%3==0 && (a[1]+a[4]+a[7])%3==0 && (a[2]+a[5]+a[8])%3==0 &&
	  (a[0]+a[4]+a[8])%3==0 && (a[2]+a[4]+a[6])%3==0 ))                                                          
{ 
*/
fflush(stdin); //清空緩衝區
key=getch();
switch(key)
{
case 80:if(c>2)temp=a[c],a[c]=a[c-3],a[c=c-3]=temp,times++;break;              //down  如果是第2 3排
case 72:if(c<6)temp=a[c],a[c]=a[c+3],a[c=c+3]=temp,times++;break;              //up    如果是第1 2排
case 77:if(c!=0&&c!=3&&c!=6)temp=a[c],a[c]=a[c-1],a[c=c-1]=temp,times++;break; //right 如果不是最左排
case 75:if(c!=2&&c!=5&&c!=8)temp=a[c],a[c]=a[c+1],a[c=c+1]=temp,times++;break; //left  如果不是最右排
case 'g':case 'G':  cout<<"\n\n解答1:\n1 2 3\n4 5 6\n7 8\n\n解答2:\n1 4 7\n2 5 8\n3 6  \n"<<endl; system("pause"); break;
}
system("cls");  //刷屏

   
    cout<<"\n\n";
	cout<<setw(10)<<(char)a[0]<<setw(10)<<(char)a[1]<<setw(10)<<(char)a[2];
    cout<<"\n\n\n\n";
	cout<<setw(10)<<(char)a[3]<<setw(10)<<(char)a[4]<<setw(10)<<(char)a[5];
	cout<<"\n\n\n\n";
	cout<<setw(10)<<(char)a[6]<<setw(10)<<(char)a[7]<<setw(10)<<(char)a[8];
	cout<<"\n\n\n\n";


cout<<"第"<<times<<"步";



}





if(times<100)
{
	money = money + 100000;
	cout<<"\r共花了"<<times<<"步完成\n\n";
	cout<<"你根本就是神手，叫你解謎大大!\n\n";

	system("pause");
	system("cls");
	success2++;
	cout<<"系統提示:\n\t\t\t";
	cout<<"獲得獎勵10萬戒尼!!\n";
}
else if(times>=100 && times<150)
{
	money = money + 80000;
	cout<<"\r共花了"<<times<<"步完成\n\n";
	cout<<"你根本就是解謎達人，秋條喔!\n";

	system("pause");
	system("cls");
	cout<<"系統提示:\n\t\t\t";
	cout<<"獲得獎勵8萬戒尼!!\n";
}

else if(times>=150 && times<300)
{
	money = money + 50000;
	cout<<"\r共花了"<<times<<"步完成\n\n";
	cout<<"邏輯思考能力頗強的喔!\n";


	system("pause");
	system("cls");
	cout<<"系統提示:\n\t\t\t";
	cout<<"獲得獎勵5萬戒尼!!\n";
}
else if(times>=300 && times<500)
{
	money = money + 30000;
	cout<<"\r共花了"<<times<<"步完成\n\n";
	cout<<"恭喜解謎成功，不過還有進步空間喔!\n";

	system("pause");
	system("cls");
	cout<<"系統提示:\n\t\t\t";
	cout<<"獲得獎勵3萬戒尼!!\n";
}
else 
{
	cout<<"\n\n可惜超過步數限制囉，請重新來過再接再勵吧!!!\n";
	success3++;

}


}

else if(ap<3)
{
	cout<<"行動點數不足!!請回活力餐廳進行補給~\n";
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