#ifndef DATA_H
#define DATA_H
#include<string>


class data
{
	friend class code;
	friend class Bingo;
	friend class Landmine;
	friend class matrix;
	friend class maze;
	friend class Sudoku;
	friend class shop;
	friend class status;
	friend class Save;
	friend class Load;
	friend class bank;
	friend class menu;
public:
	data();
    ~data();
	void setplayername(char *str);
	char *getplayername();

	void print();

private:
	static char *playername; //���a�m�W
    static long double money; //��
	static int ap; //����I��
	static long double savingac;

};

#endif