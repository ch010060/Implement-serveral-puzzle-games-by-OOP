#include<iostream>
#include<cstring>
#include<ctype.h>
#include"data.h"
using namespace std;


long double data::money = 50000;  //��l���B:5�U
int data::ap = 20;   //��l����I��:20�I
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
	