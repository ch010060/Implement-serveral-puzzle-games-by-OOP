#include<iostream>
#include<cstdlib>
#include<fstream>
#include"Save.h"
#include"data.h"
#include"bank.h"

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

Save::Save()
{}

Save::~Save()
{}


void Save::S_ave()
{

	  char filename[]="Save.txt";
	  fstream file;


       

        file.open((char*) filename, ios::out);      //�}���ɮ�

        if(!file)     //�ˬd�ɮ׬O�_���\�}��

        {

                cerr << "Can't open file!\n";

                exit(1);     //�b�����`���ΤU�A���_�{��������

        }

		else
		{

        
			file <<data::playername<<" "<< money << " " << ap <<" "<<savingac<<" "<<k1<<" "<<k2<<" "<<k3<<" "<<k4<<" "<<k5<<" "<<k6<<" "<<k7<<" "<<k8<<" "<<k9<<" "<<k10<<"\n";   //�N��ƿ�X���ɮ�

		}

		file.close();





}

