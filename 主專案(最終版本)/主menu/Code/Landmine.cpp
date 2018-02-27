/*##########�o�O��a�p###########*/
#include<string>
#include<iostream>
#include<ctime>
#include<iomanip>
#include"Landmine.h"
#include "data.h"
#include"Abstract.h"
using namespace std;

int success1 = 0; //��a�p�L��3��: �a�p��

int life = 0;  //0:��  1:��


int out=0; //�P�_���}�P�_���Ѽ�

Landmine::Landmine()
{}

Landmine::~Landmine()
{}



//1
void Landmine::playLandmine()
{
	    
        int j,k,temp;
        setBoom();
        for(j = 0;j < MAPSIZE;j ++)
        {
                for(k = 0;k < MAPSIZE;k ++)
                {
                        temp = 0;
                        if(map[j][k] != 'b')
                        {
                                if(j > 0 && map[j - 1][k] == 'b') //�˴��W��
                                {
                                        temp ++;
                                }
                                if(j > 0 && k > 0 && map[j - 1][k - 1] == 'b') //�˴����W��
                                {
                                        temp ++;
                                }
                                if(k > 0 && map[j][k - 1] == 'b') //�˴�����
                                {
                                        temp ++;
                                }
                                if(j < MAPSIZE - 1 && k > 0 && map[j + 1][k - 1] == 'b') //�˴����U��
                                {
                                        temp ++;
                                }
                                if(j < MAPSIZE - 1 && map[j + 1][k] == 'b')  //�˴��U��
                                {
                                        temp ++;
                                }
                                if(j < MAPSIZE - 1 && k < MAPSIZE - 1 && map[j + 1][k + 1] == 'b') //�˴��k�U��
                                {
                                        temp ++;
                                }
                                if(k < MAPSIZE - 1 && map[j][k + 1] == 'b') //�˴��k��
                                {
                                        temp ++;
                                }
                                if(j > 0 && k < MAPSIZE - 1 && map[j - 1][k + 1] == 'b') //�˴��k�W��
                                {
                                        temp ++;
                                }
                                map[j][k] = temp + '0';
                        }
                }
        }
        memset(mapMask,0,sizeof(mapMask));
}



void Landmine::setBoom()
{
        int j,k,l;
        memset(map,0,sizeof(map));
        srand((unsigned int)time(NULL));
        for(j = 0;j < BOOM;j ++)
        {
                do
                {
                        k = rand() % MAPSIZE;
                        l = rand() % MAPSIZE;
                }while(map[k][l] != 0);
                map[k][l] = 'b';
        }
}
//2
void Landmine::showMap_()
{
	if(out==0)
	{
        int j,k;
        cout<<" ";
        for(j = 0; j < MAPSIZE;j ++)
                cout<<setw(5)<<(int)j;
        cout<<"\n";
        for(j = 0;j < MAPSIZE;j ++)
        {
                cout<<(int)j;
                for(k = 0;k < MAPSIZE;k ++)
                {
                        if(mapMask[j][k] == 0)
                                cout<<setw(5)<<"��";
                        else
                                cout<<setw(5)<<(char)map[j][k];

                }
                cout<<"\n\n";

        }

	}

	
	

}


void Landmine::showMap()
{
        int j,k;
        for(j = 0;j < MAPSIZE;j ++)
        {
			
                for(k = 0;k < MAPSIZE;k ++)
                {
                        cout<<(char)map[j][k];
                }
                cout<<"\n";
				
        }
		
}
//3
void Landmine::gameStart()
{
        int j,k,temp;

	
        while(out==0)
		{
			
			    
                cin>>k>>j;  //x-y�t��
				system("cls");
                if(j < 0 || j > MAPSIZE - 1 || k < 0 || k > MAPSIZE - 1)
                        continue;
                if(map[j][k] == 'b')
                {


				 cout<<" ";
                 for(j = 0; j < MAPSIZE;j ++)
                 cout<<setw(5)<<(int)j;
                 cout<<"\n";

			 for(j = 0;j < MAPSIZE;j ++)
            {
                cout<<(int)j;
                for(k = 0;k < MAPSIZE;k ++)
                {
                        if(map[j][k] == 'b')
                                cout<<setw(5)<<(char)15;
                        else
                                cout<<setw(5)<<(char)map[j][k];

                }
                cout<<"\n\n";

            }


					   
                       cout<<"\a\a\a���ߧA���a�p!!\n\n";
					   cout<<setw(7)<<"G"<<setw(7)<<"A"<<setw(7)<<"M"<<setw(7)<<"E"<<"\t"<<setw(7)
						   <<"O"<<setw(7)<<"V"<<setw(7)<<"E"<<setw(7)<<"R"<<setw(7)<<"!"<<"\n";

					   
					   out++;
					   life++;
                       
                }
                else
                {
                        open(j,k);
                }
                showMap_();
				
                temp = 0;
                for(j = 0;j < MAPSIZE;j ++)
                              for(k = 0;k < MAPSIZE;k ++)
                                     if(mapMask[j][k] == 1)
                                               temp ++;
                if(temp + BOOM == MAPSIZE * MAPSIZE)
                {
                               cout<<"you win...\n\n";
							   out++;

							   system("pause");
							   system("cls");
							   success1++; 
							   cout<<"�t�δ���:\n\t\t";
							   cout<<"��o40�U�٥�!!\n\n";
							   money = money + 400000;
							   system("pause");
						
                }

				

				
        }

		out=0; //�^�k��l�]�m
		system("pause");
}

void Landmine::open(int j,int k)
{
        if(mapMask[j][k] != 0)
                return;
        if(j >= 0 && k >= 0 && j < MAPSIZE && k < MAPSIZE)
                mapMask[j][k] = 1;
        if(map[j][k] == '0')
        {
                if(j > 0 && k > 0)
                        open(j - 1,k - 1);
                if(k > 0)
                                open(j,k - 1);
                if(j < MAPSIZE - 1 && k > 0)
                                open(j + 1,k - 1);
                if(j < MAPSIZE - 1)
                        open(j + 1,k);
                if(j < MAPSIZE - 1 && k < MAPSIZE - 1)
                        open(j + 1,k + 1);
                if(k < MAPSIZE - 1)
                        open(j,k + 1);
                if(j > 0 && k < MAPSIZE - 1)
                        open(j - 1,k + 1);
                if(j > 0)
                        open(j - 1,k);
        }
}


