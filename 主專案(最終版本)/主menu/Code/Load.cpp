#include<iostream>
#include<cstdlib>
#include<fstream>
#include"data.h"
#include"Load.h"
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

Load::Load()
{}


Load::~Load()
{}


void Load::L_oad()
{

	char filename[]="Save.txt";
	fstream file;

	long double strMY,strSVAC;
	int strAP;
	int s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
	char *strName = new char [10];

        file.open((char*) filename, ios::in);        //�N�ɮ׶}�Ҭ���J���A

        if(!file)     //�ˬd�ɮ׬O�_���\�}��

        {

                cerr << "Can't open file!\n";

                exit(1);     //�b�����`���ΤU�A���_�{��������

        }

		while(file >> strName >> strMY >> strAP >> strSVAC >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9 >> s10)     //Ū���O���A�YŪ�����ɮ׵����h�Ǧ^0
		{
			*data::playername = *strName;
                 money = strMY;
		         ap = strAP;
				 strSVAC = savingac;
				 k1=s1;
				 k2=s2;
				 k3=s3;
				 k4=s4;
				 k5=s5;
				 k6=s6;
				 k7=s8;
				 k9=s9;
				 k10=s10;
		}

		file.close();

}


