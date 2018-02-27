#include<iostream>
#include<cstring>
#include<ctype.h>
#include"data.h"
using namespace std;


long double data::money = 50000;  //初始金額:5萬
int data::ap = 20;   //初始行動點數:20點
long double data::savingac = 0;
char *data::playername=new char [10];


data::data()
{


}

data::~data()
{}


void data::setplayername(char *str)
{
	playername=str;
}

char *data::getplayername()
{
	return playername;

}
	