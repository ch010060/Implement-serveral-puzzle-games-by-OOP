/*##########�o�O�׷��K�X###########*/
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

	cout << "�w��D�Բ׷��K�X\n\n�K�X�d�򤶦b" << low << "��" << high;

		while( 1 )
		{
			if( time > 0 )cout << "	�ٳѤU" << time << "�����|\n�п�J�Ʀr\n";
			else 
			{
				cout << "	�D�ԥ���\n�׷��K�X�O" << ans << endl;
				break;
			}

			cin >> input;
			time--;
			
			if( low <= input && input <= high )
			{
				if( input < ans )
				{
					system("cls");
					cout << "\n�K�X�d�򤶦b" << input + 1 << "��" << high ;
					low = input + 1;
				}
				else if( ans < input )
				{
					system("cls");
					cout << "\n�K�X�d�򤶦b" << low << "��" << input - 1 ;
					high = input - 1;
				}
				else if( input == ans )
				{
					system("cls");
					cout << "�D�Ԧ��\\n�׷��K�X�O" << ans << endl;
					system("pause");
					system("cls");
					cout<<"�t�δ���\n\t\t";
					cout<<"��o10�U�٥�!!\n\n";
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
				cout <<"�W�X�d��\n\n"; 
				cout << "�K�X�d�򤶦b" << low << "��" << high;
				time++;
			}
		}

	
}