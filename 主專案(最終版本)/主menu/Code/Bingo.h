#ifndef BINGO_H
#define BINGO_H
#include "Abstract.h"
#include "data.h"
using namespace std;

class Bingo : public data,public Abstract
{
public:
	Bingo();
	~Bingo();
	
	void play_a()  //override
	{
	  if(ap>=6)
	  {

		  cout<<"�w��Ө��u��������\n";
          cout<<"�g�~���ȫȥi�H�b�o�p�͡B�M�w�{�ͻ��P�����@�����G\n";
          cout<<"�۫H�M�w�{�ͬ۳B��A�L�R���J�N�����ܷ|���ާA��V\n\n";
		  system("pause");
		  system("cls");


		play();
		ap = ap-6;
	  }
	  else
	  {
		  cout<<"����I�Ƥ���!!�Ц^���O�\�U�i��ɵ�~\n";
		  system("pause");
	  }
	}
	void print_rules(void);	// �L�X�C�������P�W�h
	void print_initial_cells(void);		// �L�X��J���Ǫ���l
	void initial_cells(int cells[]);		// �N��l���Ȫ�l�Ƭ�-1
	void fill_player_cells(int cells[]);		// �񺡪��a����l�]�H���Φۤv��J�^
	void random_fill_cells(int cells[]);		// �H����J�Ʀr
	void print_now(int cells[]);		// �L�X�ثe��l���Ʀr�γQ�������a��
	void print_computer_cells(int computer_cells[]);		// �L�X�ثe�q��������
	void initial_level_array(int level_array[]);		// �u�����Ű}�C��l��
	void assign_cells_p(int cells[], int *cells_p[]);		// ���V�������Ʀr�Ҧb��l
	void filter_level_array(int level_array[], int computer_index);		// ���ܪ��a��J���Ʀr�������u������
	void clear_number(int *cells_p[], int enter_num);		// �N��ܪ��Ʀr�]����
	void level_array_add(int level_array[], int choose_cell);		// �N��ܫ᪺�Ƭ����s�u�u������+1
	void print_over_information(int result);		// �L�X�C�����G�A�C�������C

	int  error(int cells[], int enter_number);		// ���տ�J�Ʀr�O�_�ŦX�d��έ���
	int  determine_line_vertical(int cells[]);		// �p��ثe�������X���u
	int  determine_line_horizontal(int cells[]);		// �p��ثe����X���u
	int  determine_line_cross(int cells[]);		// �p��ثe��e�����X���u
	int  determine_line_total(int cells[]);		// �p��ثe�`�@���X���u
	int  print_lines(int player_cells[], int computer_cells[]);		// �L�X�ثe���a��q���U���X���u�A�öǦ^�C���O�_����
	int  choose_computer_number(int computer_cells[], int level_array[]);		// �q���۰ʿ�ܭn�������Ʀr
	int  find_max(int level_array[]);		// ��X�Ĥ@���u�����ų̰�����l
	int  find_computer_index(int computer_cells[], int p_choose_number);		// ��X���a��J���Ʀr�������q����l
	int  player_enter_number(int player_cells[], int *player_cells_p[]);		// ���a��J�n�������Ʀr

	void play();

private:
	 int  p_cells[25],        //���a�b��l�̨̧Ƕ�g���Ʀr
        *p_cells_p[25],      //���V���a�Ʀr�Ҧb����l
         c_cells[25],        //�q���b��l�̨̧Ƕ񺡪��Ʀr
        *c_cells_p[25],      //���V�q���Ʀr�Ҧb����l
         l_array[25],        //�q���s��︹�u�����Ū��}�C
         over,                     //�C���O�_�����G���|�������A>0������
         p_choose_number,          //���a��ܪ����X
         p_choose_c_cells_index,   //���a��ܪ����X������q������l
         c_choose_number;          //�q����ܪ����X
    char pause;                    //�Ȱ�����
};

#endif