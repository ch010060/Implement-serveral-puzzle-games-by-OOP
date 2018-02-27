/*##########這是終極密碼###########*/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctype.h>
#include "code.h"
#include "Abstract.h"
#include "data.h"
using namespace std;
#define HIGHT 1000
#define TIMES 8



code::code()
{}

code::~code()
{}


void code::play()
{
	srand(time(NULL));
	int input;
	int low = 1;
	int high = HIGHT;
	int time = TIMES;
	int ans = rand() % HIGHT + 1;

	cout << "歡迎挑戰終極密碼\n\n密碼範圍介在" << low << "到" << high;

		while( 1 )
		{
			if( time > 0 )cout << "	還剩下" << time << "次機會\n請輸入數字\n";
			else 
			{
				cout << "	挑戰失敗\n終極密碼是" << ans << endl;
				break;
			}

			cin >> input;
			time--;
			
			if( low <= input && input <= high )
			{
				if( input < ans )
				{
					system("cls");
					cout << "\n密碼範圍介在" << input + 1 << "到" << high ;
					low = input + 1;
				}
				else if( ans < input )
				{
					system("cls");
					cout << "\n密碼範圍介在" << low << "到" << input - 1 ;
					high = input - 1;
				}
				else if( input == ans )
				{
					system("cls");
					cout << "挑戰成功\n終極密碼是" << ans << endl;
					system("pause");
					system("cls");
					cout<<"系統提示\n\t\t";
					cout<<"獲得10萬戒尼!!\n\n";
					money = money + 100000;
					system("pause");
					break;
				}
			}
			
			
			else if( input == 3104)										//answer
			{
				cout << ">>" << ans;
				time++;
			}
			

			else 
			{
				cout <<"超出範圍\n\n"; 
				cout << "密碼範圍介在" << low << "到" << high;
				time++;
			}
		}

	
}