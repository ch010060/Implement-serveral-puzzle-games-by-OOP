/*##########這是賓果###########*/
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


	print_rules();                 //印出遊戲說明與規則
    print_initial_cells();         //印出輸入順序的格子
    initial_cells(p_cells);        //將格子的值初始化
    srand((unsigned int)time(NULL));             //亂數種子
    fill_player_cells(p_cells);    //填滿玩家的格子（隨機或自己輸入）
 
    random_fill_cells(c_cells);    //填滿電腦的格子（隨機）
    initial_level_array(l_array);  //優先等級陣列初始化
    assign_cells_p(p_cells, p_cells_p);  //將p_cells_p指向對應的數字所在格子
    assign_cells_p(c_cells, c_cells_p);  //將c_cells_p指向對應的數字所在格子
	over=0;






	while(over==0){
        // 玩家劃掉數字
        p_choose_number = player_enter_number(p_cells, p_cells_p);
		if(p_choose_number==-1)
		{
			system("cls");
			print_computer_cells(c_cells);
			cout<<"↑電腦";
			print_now(p_cells);
			continue;
		}
        // 求出玩家劃掉之數字對應的電腦格子
        p_choose_c_cells_index = find_computer_index(c_cells, p_choose_number);
        // 把電腦的玩家劃掉之數字也劃掉
        clear_number(c_cells_p, p_choose_number);
        // 改變p_choose_c_cells_index為
        filter_level_array(l_array, p_choose_c_cells_index);
        // 改變玩家劃掉之數字相關的優先等級
        level_array_add(l_array, p_choose_c_cells_index);

        system("cls");

        // 印出目前玩家與電腦各有幾條連線
        over = print_lines(p_cells, c_cells);
        // 印出目前電腦的情形
        print_computer_cells(c_cells);
		cout<<"↑電腦";
        // 印出目前玩家的格子
        print_now(p_cells);
		// 印出玩家劃掉的數字
		cout<<"您劃掉了"<<p_choose_number + 1<<endl;
		system("pause");

        if (over!=0)
           break;

		system("cls");
        // 電腦自動選擇數字
        c_choose_number = c_cells[choose_computer_number(c_cells, l_array)] - 25;
        //自動將玩家的電腦所選擇之數字也劃掉
        clear_number(p_cells_p, c_choose_number);

        // 印出目前玩家與電腦各有幾條連線
        over = print_lines(p_cells, c_cells);
        // 印出目前電腦的情形
        print_computer_cells(c_cells);
		cout<<"↑電腦";
        // 印出目前玩家的格子
        print_now(p_cells);
		// 印出電腦劃掉的格子
        cout<<"電腦劃掉了"<<c_choose_number + 1<<endl;
		system("pause");
    }

    print_over_information(over);
}

void Bingo::print_rules(void) {
     cout<<"-----* 賓果遊戲*-----\n"
			<<"1. 請按照下列格子順序(先往右再往下)輸入您要的數字\n"
			<<"   可一次輸入一排，每個數字間用空白隔開\n"
			<<"   輸入完一個數字或幾個數字後按Enter，將會印出最新狀態\n"
			<<"2. 數字範圍為1~25\n"
			<<"3. 輸入完畢後，程式會指示您先輸入要劃掉的數字\n"
			<<"   請輸入您要劃掉的數字後按Enter\n"
			<<"   程式會順便將電腦的選號給劃掉。\n"
			<<"4. 遊戲如同一般賓果遊戲，先有五條連線者為贏。\n";
}

// 印出輸入順序的格子
void Bingo::print_initial_cells(void) {
     int i;
     cout<<"\n┌－－－－－－－－－┐\n";
     for (i = 1; i <= 25; i++) {
         if (i % 5 == 1)
            cout<<"｜"; 
         printf("%2d｜", i);						//為了排版關係而用printf
         if (i % 5 == 0 && i != 25)
            cout<<"\n├－＋－＋－＋－＋－┤\n";
     }
     cout<<"\n└－－－－－－－－－┘\n";
}

// 將格子的值初始化為-1
void Bingo::initial_cells(int cells[]) {
     int i;
     for (i = 0; i < 25; i++)
         cells[i] = -1;
}

// 填滿玩家的格子（隨機或自己輸入）
void Bingo::fill_player_cells(int cells[]) {
     int sum = 0, enter_num;
     do {
         cout<<"請輸入要填入的數字（或輸入0由電腦隨機填入數字）>> ";
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

// 隨機填入數字
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

// 測試輸入數字是否符合範圍或重複
int  Bingo::error(int cells[], int enter_number) {
     int err = 0, i;

	for (i = 0; i < 25 && err!=1; i++)
	{
         if (enter_number == cells[i]+1) {
            err = 1;
            cout<<enter_number<<"重覆輸入，請輸入其他數"<<endl;
			system("pause");
			break;
		}//end if
	}//end for
	if (enter_number < 1 || enter_number > 25)
	{
		err = 1;
		cout<<enter_number<<"超出範圍，請輸入其他數"<<endl;
		system("pause");
     }//end if
	return (err);
}//end Bingo::error

// 印出目前格子的數字或被劃掉的地方
void Bingo::print_now(int cells[]) {
     int i;
     cout<<"\n－－－－－－－－－－－\n";
     for (i = 0; i < 25; i++) {
         if (i % 5 == 0)
            cout<<"｜"; 
         if (cells[i] >= 25)
            cout<<"●｜"; 
         else
             printf("%2d｜", cells[i] + 1);			//因為排版關係而用printf
         if (i % 5 == 4 && i != 25 - 1)
            cout<<"\n－－＋－＋－＋－＋－－\n";
     }
     cout<<"\n－－－－－－－－－－－\n";
}

// 印出目前電腦的情形
void Bingo::print_computer_cells(int computer_cells[]) {
     int i;
     cout<<"\n－－－－－－－－－－－\n";
     for (i = 0; i < 25; i++) {
         if (i % 5 == 0)
            cout<<"｜"; 
         if (computer_cells[i] >= 25)
            cout<<"●｜"; 
         else
             cout<<"○｜"; 
         if (i % 5 == 4 && i != 25 - 1)
            cout<<"\n－－＋－＋－＋－＋－－\n";
     }
     cout<<"\n－－－－－－－－－－－\n";
}

/*版本1
// 優先等級陣列初始化
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


//版本2
//優先等級陣列初始化   
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


// 指向對應的數字所在格子
void Bingo::assign_cells_p(int cells[], int *cells_p[]) {
     int i;
     for (i = 0; i < 25; i++)
         cells_p[cells[i]] = &cells[i];
}

// 玩家輸入要劃掉的數字
int  Bingo::player_enter_number(int player_cells[], int *player_cells_p[]) {
     int clear_n;
     cout<<"請輸入要劃掉的數字>> ";
     cin>>clear_n;
     clear_n--;
     if (clear_n > 24 || clear_n < 0 || *player_cells_p[clear_n] >= 25) 
	 {
        cout<<"超出範圍或是已劃掉，請重新輸入。\n";
		system("pause");
		return -1;
     }
	 else {
          clear_number(player_cells_p, clear_n);
          return(clear_n);
     }
}

// 改變玩家輸入之數字對應的優先等級
void Bingo::filter_level_array(int level_array[], int computer_index) {
     level_array[computer_index] = 0;
}

// 找出玩家輸入之數字對應的電腦格子
int  Bingo::find_computer_index(int computer_cells[], int p_choose_number) {
     int i;
     for (i = 0; i < 25; i++) {
         if (computer_cells[i] == p_choose_number)
            break;
     }
     return(i);
}

// 將選擇的數字也劃掉
void Bingo::clear_number(int *cells_p[], int enter_num) {
     *cells_p[enter_num] += 25;
}

// 電腦自動選擇要劃掉的格子
int  Bingo::choose_computer_number(int computer_cells[], int level_array[]) {
     int max_index;
     max_index = find_max(level_array);
     computer_cells[max_index] += 25;
     level_array[max_index] = 0;
     level_array_add(level_array, max_index);
     return(max_index);
}

// 找出第一個優先等級最高的格子
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

// 將選擇後的數相關連線優先等級+1
void Bingo::level_array_add(int level_array[], int choose_cell) {
     int difference, i;
     difference = choose_cell % 5;

     // 橫+1
     for (i = choose_cell - difference; i < choose_cell; i++)
	 if (level_array[i] != 0)
	    level_array[i]++;
     for (i = choose_cell + 1; i < choose_cell + 5 - difference; i++)
         if (level_array[i] != 0)
            level_array[i]++;

     // 直+1
     for (i = choose_cell % 5; i < choose_cell; i += 5)
         if (level_array[i] != 0)
	    level_array[i]++;
     for (i = choose_cell + 5; i < 25; i += 5)
         if (level_array[i] != 0)
	    level_array[i]++;

     // 交叉+1
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

// 計算目前直的有幾條線
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

// 計算目前橫的有幾條線
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

// 計算目前交叉的有幾條線
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

// 計算目前總共有幾條線
int  Bingo::determine_line_total(int cells[]) {
     return (determine_line_vertical(cells) +
             determine_line_horizontal(cells) +
             determine_line_cross(cells));
}

// 印出目前玩家跟電腦各有幾條線，並傳回遊戲是否結束
int  Bingo::print_lines(int player_cells[], int computer_cells[]) {
     int player_lines, computer_lines;
     player_lines = determine_line_total(player_cells);
     computer_lines = determine_line_total(computer_cells);
     cout<<"您　目前有"<<player_lines<<"條連線"<<endl;
     cout<<"電腦目前有"<<computer_lines<<"條連線"<<endl;

     if (computer_lines >= 5 || player_lines >= 5)
        cout<<"★最終勝負>> （您）"<<player_lines<<" : （電腦）"<< computer_lines<<endl;

     if (player_lines >= 5 && computer_lines < 5)
		return(1);	  // 玩家贏
     else if (computer_lines >= 5 && player_lines < 5)
		return(2);   // 電腦贏
     else if (player_lines == 5 && computer_lines == 5)
		return(3);   // 平手
     else
		return(0);       // 遊戲尚未結束
}

void Bingo::print_over_information(int result) {
     if (result == 1)
	 {
        cout<<"\n恭喜你！贏了！\n";
		system("pause");
		system("cls");
		cout<<"系統提示\n\t\t";
		cout<<"獲得15萬戒尼!!\n\n";
		money = money + 150000;
		system("pause");
	 }
     else if (result == 2)
	 {
             cout<<"\n不好意思電腦贏了\n";
	 }
     else
	 {
         cout<<"\n平手！\n";
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