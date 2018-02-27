/*##########�o�O���G###########*/
#include <iostream>
#include <ctime>
#include "Bingo.h"
#include "Abstract.h"
#include "data.h"
using namespace std;


Bingo::Bingo()
{}

Bingo::~Bingo()
{}

void Bingo::play()
{


	print_rules();                 //�L�X�C�������P�W�h
    print_initial_cells();         //�L�X��J���Ǫ���l
    initial_cells(p_cells);        //�N��l���Ȫ�l��
    srand((unsigned int)time(NULL));             //�üƺؤl
    fill_player_cells(p_cells);    //�񺡪��a����l�]�H���Φۤv��J�^
 
    random_fill_cells(c_cells);    //�񺡹q������l�]�H���^
    initial_level_array(l_array);  //�u�����Ű}�C��l��
    assign_cells_p(p_cells, p_cells_p);  //�Np_cells_p���V�������Ʀr�Ҧb��l
    assign_cells_p(c_cells, c_cells_p);  //�Nc_cells_p���V�������Ʀr�Ҧb��l
	over=0;






	while(over==0){
        // ���a�����Ʀr
        p_choose_number = player_enter_number(p_cells, p_cells_p);
		if(p_choose_number==-1)
		{
			system("cls");
			print_computer_cells(c_cells);
			cout<<"���q��";
			print_now(p_cells);
			continue;
		}
        // �D�X���a�������Ʀr�������q����l
        p_choose_c_cells_index = find_computer_index(c_cells, p_choose_number);
        // ��q�������a�������Ʀr�]����
        clear_number(c_cells_p, p_choose_number);
        // ����p_choose_c_cells_index��
        filter_level_array(l_array, p_choose_c_cells_index);
        // ���ܪ��a�������Ʀr�������u������
        level_array_add(l_array, p_choose_c_cells_index);

        system("cls");

        // �L�X�ثe���a�P�q���U���X���s�u
        over = print_lines(p_cells, c_cells);
        // �L�X�ثe�q��������
        print_computer_cells(c_cells);
		cout<<"���q��";
        // �L�X�ثe���a����l
        print_now(p_cells);
		// �L�X���a�������Ʀr
		cout<<"�z�����F"<<p_choose_number + 1<<endl;
		system("pause");

        if (over!=0)
           break;

		system("cls");
        // �q���۰ʿ�ܼƦr
        c_choose_number = c_cells[choose_computer_number(c_cells, l_array)] - 25;
        //�۰ʱN���a���q���ҿ�ܤ��Ʀr�]����
        clear_number(p_cells_p, c_choose_number);

        // �L�X�ثe���a�P�q���U���X���s�u
        over = print_lines(p_cells, c_cells);
        // �L�X�ثe�q��������
        print_computer_cells(c_cells);
		cout<<"���q��";
        // �L�X�ثe���a����l
        print_now(p_cells);
		// �L�X�q����������l
        cout<<"�q�������F"<<c_choose_number + 1<<endl;
		system("pause");
    }

    print_over_information(over);
}

void Bingo::print_rules(void) {
     cout<<"-----* ���G�C��*-----\n"
			<<"1. �Ы��ӤU�C��l����(�����k�A���U)��J�z�n���Ʀr\n"
			<<"   �i�@����J�@�ơA�C�ӼƦr���Ϊťչj�}\n"
			<<"   ��J���@�ӼƦr�δX�ӼƦr���Enter�A�N�|�L�X�̷s���A\n"
			<<"2. �Ʀr�d��1~25\n"
			<<"3. ��J������A�{���|���ܱz����J�n�������Ʀr\n"
			<<"   �п�J�z�n�������Ʀr���Enter\n"
			<<"   �{���|���K�N�q�����︹�������C\n"
			<<"4. �C���p�P�@�뻫�G�C���A���������s�u�̬�Ĺ�C\n";
}

// �L�X��J���Ǫ���l
void Bingo::print_initial_cells(void) {
     int i;
     cout<<"\n�z�ССССССССТ{\n";
     for (i = 1; i <= 25; i++) {
         if (i % 5 == 1)
            cout<<"�U"; 
         printf("%2d�U", i);						//���F�ƪ����Y�ӥ�printf
         if (i % 5 == 0 && i != 25)
            cout<<"\n�u�СϡСϡСϡСϡТt\n";
     }
     cout<<"\n�|�ССССССССТ}\n";
}

// �N��l���Ȫ�l�Ƭ�-1
void Bingo::initial_cells(int cells[]) {
     int i;
     for (i = 0; i < 25; i++)
         cells[i] = -1;
}

// �񺡪��a����l�]�H���Φۤv��J�^
void Bingo::fill_player_cells(int cells[]) {
     int sum = 0, enter_num;
     do {
         cout<<"�п�J�n��J���Ʀr�]�ο�J0�ѹq���H����J�Ʀr�^>> ";
		 fflush(stdin);
         cin>>enter_num;
         if (enter_num == 0) {
            random_fill_cells(cells);
            sum = 25;
         } else if (!error(cells, enter_num)) {
                   enter_num--;
                   cells[sum] = enter_num;
                   sum++;
         }
		 system("cls");
		 print_rules();
		 print_now(cells);
     } while (sum < 25);
	 
}

// �H����J�Ʀr
void Bingo::random_fill_cells(int cells[]) {
     int i, a, b, temp;
     for (i = 0; i < 25; i++) {
         cells[i] = i;
     }
     for (i = 0; i < 25; i++) {
         a = rand() % 25;
         b = rand() % 25;
         temp = cells[a];
         cells[a] = cells[b];
         cells[b] = temp;
     }
}

// ���տ�J�Ʀr�O�_�ŦX�d��έ���
int  Bingo::error(int cells[], int enter_number) {
     int err = 0, i;

	for (i = 0; i < 25 && err!=1; i++)
	{
         if (enter_number == cells[i]+1) {
            err = 1;
            cout<<enter_number<<"���п�J�A�п�J��L��"<<endl;
			system("pause");
			break;
		}//end if
	}//end for
	if (enter_number < 1 || enter_number > 25)
	{
		err = 1;
		cout<<enter_number<<"�W�X�d��A�п�J��L��"<<endl;
		system("pause");
     }//end if
	return (err);
}//end Bingo::error

// �L�X�ثe��l���Ʀr�γQ�������a��
void Bingo::print_now(int cells[]) {
     int i;
     cout<<"\n�СССССССССС�\n";
     for (i = 0; i < 25; i++) {
         if (i % 5 == 0)
            cout<<"�U"; 
         if (cells[i] >= 25)
            cout<<"���U"; 
         else
             printf("%2d�U", cells[i] + 1);			//�]���ƪ����Y�ӥ�printf
         if (i % 5 == 4 && i != 25 - 1)
            cout<<"\n�ССϡСϡСϡСϡС�\n";
     }
     cout<<"\n�СССССССССС�\n";
}

// �L�X�ثe�q��������
void Bingo::print_computer_cells(int computer_cells[]) {
     int i;
     cout<<"\n�СССССССССС�\n";
     for (i = 0; i < 25; i++) {
         if (i % 5 == 0)
            cout<<"�U"; 
         if (computer_cells[i] >= 25)
            cout<<"���U"; 
         else
             cout<<"���U"; 
         if (i % 5 == 4 && i != 25 - 1)
            cout<<"\n�ССϡСϡСϡСϡС�\n";
     }
     cout<<"\n�СССССССССС�\n";
}

/*����1
// �u�����Ű}�C��l��
void Bingo::initial_level_array(int level_array[]) {
     int i;
     for (i = 0; i < 25; i++) {
	 if (i % 4 == 0 || i % 6 == 0)
	    level_array[i] = 3;
         else
             level_array[i] = 2;
     }
     level_array[12]++;
     
}
*/


//����2
//�u�����Ű}�C��l��   
void Bingo::initial_level_array(int level_array[]) {
     int i;
     for (i = 0; i < 25; i++) {
	 if (i==12)
	    level_array[i] = 5;
	 else if( (i % 4 == 0 || i % 6 == 0) && i!=12)
		level_array[i] = 4;
	 else if(i==7 || i==11 || i==13 || i==17)
	    level_array[i] = 3;
     else
        level_array[i] = 2;
     }
     level_array[12]++;
     
}


// ���V�������Ʀr�Ҧb��l
void Bingo::assign_cells_p(int cells[], int *cells_p[]) {
     int i;
     for (i = 0; i < 25; i++)
         cells_p[cells[i]] = &cells[i];
}

// ���a��J�n�������Ʀr
int  Bingo::player_enter_number(int player_cells[], int *player_cells_p[]) {
     int clear_n;
     cout<<"�п�J�n�������Ʀr>> ";
     cin>>clear_n;
     clear_n--;
     if (clear_n > 24 || clear_n < 0 || *player_cells_p[clear_n] >= 25) 
	 {
        cout<<"�W�X�d��άO�w�����A�Э��s��J�C\n";
		system("pause");
		return -1;
     }
	 else {
          clear_number(player_cells_p, clear_n);
          return(clear_n);
     }
}

// ���ܪ��a��J���Ʀr�������u������
void Bingo::filter_level_array(int level_array[], int computer_index) {
     level_array[computer_index] = 0;
}

// ��X���a��J���Ʀr�������q����l
int  Bingo::find_computer_index(int computer_cells[], int p_choose_number) {
     int i;
     for (i = 0; i < 25; i++) {
         if (computer_cells[i] == p_choose_number)
            break;
     }
     return(i);
}

// �N��ܪ��Ʀr�]����
void Bingo::clear_number(int *cells_p[], int enter_num) {
     *cells_p[enter_num] += 25;
}

// �q���۰ʿ�ܭn��������l
int  Bingo::choose_computer_number(int computer_cells[], int level_array[]) {
     int max_index;
     max_index = find_max(level_array);
     computer_cells[max_index] += 25;
     level_array[max_index] = 0;
     level_array_add(level_array, max_index);
     return(max_index);
}

// ��X�Ĥ@���u�����ų̰�����l
int  Bingo::find_max(int level_array[]) {
     int max_value = level_array[0], i, first_max_index = -1;
     for (i = 0; i < 25; i++)
         if (level_array[i] > max_value)
            max_value = level_array[i];

     for (i = 0; i < 25; i++) {
         if (level_array[i] == max_value) {
            first_max_index = i;
            break;
         }
     }
     return(first_max_index);
}

// �N��ܫ᪺�Ƭ����s�u�u������+1
void Bingo::level_array_add(int level_array[], int choose_cell) {
     int difference, i;
     difference = choose_cell % 5;

     // ��+1
     for (i = choose_cell - difference; i < choose_cell; i++)
	 if (level_array[i] != 0)
	    level_array[i]++;
     for (i = choose_cell + 1; i < choose_cell + 5 - difference; i++)
         if (level_array[i] != 0)
            level_array[i]++;

     // ��+1
     for (i = choose_cell % 5; i < choose_cell; i += 5)
         if (level_array[i] != 0)
	    level_array[i]++;
     for (i = choose_cell + 5; i < 25; i += 5)
         if (level_array[i] != 0)
	    level_array[i]++;

     // ��e+1
     if (choose_cell % 6 == 0)
        for (i = 0; i < 25; i += 6)
            if (level_array[i] != 0)
               level_array[i]++;
     else if (choose_cell % 4 == 0)
             for (i = 4; i <= 20; i += 4)
                 if (level_array[i] != 0)
                    level_array[i]++;

     if (choose_cell == 12) {
        level_array[4]++;
        level_array[8]++;
        level_array[16]++;
        level_array[20]++;
     }
}

// �p��ثe�������X���u
int  Bingo::determine_line_vertical(int cells[]) {
     int connect, sum = 0, i, j;
     for (i = 0; i < 5; i++) {
         connect = 1;
         for (j = 0; j < 5; j++) {
             if (cells[i + j * 5] < 25)
                connect = 0;
         }
         if (connect == 1)
            sum++;
     }
     return(sum);
}

// �p��ثe����X���u
int  Bingo::determine_line_horizontal(int cells[]) {
     int connect, sum = 0, i, j;
     for (i = 0; i < 5; i++) {
         connect = 1;
         for (j = 0; j < 5; j++)
             if (cells[i * 5 + j] < 25)
                connect = 0;
         if (connect == 1)
            sum++;
     }
     return(sum);
}

// �p��ثe��e�����X���u
int  Bingo::determine_line_cross(int cells[]) {
     int connect, sum = 0, i;
     connect = 1;
     for ( i = 0; i < 25; i += 6) 
         if (cells[i] < 25)
            connect = 0;
     if (connect == 1)
        sum++;

     connect = 1;
     for ( i = 4; i <= 20; i += 4)
         if (cells[i] < 25)
            connect = 0;
     if (connect == 1)
        sum++;
     return(sum);
}

// �p��ثe�`�@���X���u
int  Bingo::determine_line_total(int cells[]) {
     return (determine_line_vertical(cells) +
             determine_line_horizontal(cells) +
             determine_line_cross(cells));
}

// �L�X�ثe���a��q���U���X���u�A�öǦ^�C���O�_����
int  Bingo::print_lines(int player_cells[], int computer_cells[]) {
     int player_lines, computer_lines;
     player_lines = determine_line_total(player_cells);
     computer_lines = determine_line_total(computer_cells);
     cout<<"�z�@�ثe��"<<player_lines<<"���s�u"<<endl;
     cout<<"�q���ثe��"<<computer_lines<<"���s�u"<<endl;

     if (computer_lines >= 5 || player_lines >= 5)
        cout<<"���̲׳ӭt>> �]�z�^"<<player_lines<<" : �]�q���^"<< computer_lines<<endl;

     if (player_lines >= 5 && computer_lines < 5)
		return(1);	  // ���aĹ
     else if (computer_lines >= 5 && player_lines < 5)
		return(2);   // �q��Ĺ
     else if (player_lines == 5 && computer_lines == 5)
		return(3);   // ����
     else
		return(0);       // �C���|������
}

void Bingo::print_over_information(int result) {
     if (result == 1)
	 {
        cout<<"\n���ߧA�IĹ�F�I\n";
		system("pause");
		system("cls");
		cout<<"�t�δ���\n\t\t";
		cout<<"��o15�U�٥�!!\n\n";
		money = money + 150000;
		system("pause");
	 }
     else if (result == 2)
	 {
             cout<<"\n���n�N��q��Ĺ�F\n";
	 }
     else
	 {
         cout<<"\n����I\n";
	 }
     system("pause");
}

/*
int main()
{
	Bingo player;

	player.play();

	return 0;
}
*/