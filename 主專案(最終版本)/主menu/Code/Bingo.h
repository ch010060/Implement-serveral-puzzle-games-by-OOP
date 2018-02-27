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

		  cout<<"歡迎來到優美的丹麥\n";
          cout<<"迷途的旅客可以在這小憩、和安徒生輕鬆的玩一場賓果\n";
          cout<<"相信和安徒生相處後，他充滿寓意的童話會指引你方向\n\n";
		  system("pause");
		  system("cls");


		play();
		ap = ap-6;
	  }
	  else
	  {
		  cout<<"行動點數不足!!請回活力餐廳進行補給~\n";
		  system("pause");
	  }
	}
	void print_rules(void);	// 印出遊戲說明與規則
	void print_initial_cells(void);		// 印出輸入順序的格子
	void initial_cells(int cells[]);		// 將格子的值初始化為-1
	void fill_player_cells(int cells[]);		// 填滿玩家的格子（隨機或自己輸入）
	void random_fill_cells(int cells[]);		// 隨機填入數字
	void print_now(int cells[]);		// 印出目前格子的數字或被劃掉的地方
	void print_computer_cells(int computer_cells[]);		// 印出目前電腦的情形
	void initial_level_array(int level_array[]);		// 優先等級陣列初始化
	void assign_cells_p(int cells[], int *cells_p[]);		// 指向對應的數字所在格子
	void filter_level_array(int level_array[], int computer_index);		// 改變玩家輸入之數字對應的優先等級
	void clear_number(int *cells_p[], int enter_num);		// 將選擇的數字也劃掉
	void level_array_add(int level_array[], int choose_cell);		// 將選擇後的數相關連線優先等級+1
	void print_over_information(int result);		// 印出遊戲結果，遊戲結束。

	int  error(int cells[], int enter_number);		// 測試輸入數字是否符合範圍或重複
	int  determine_line_vertical(int cells[]);		// 計算目前直的有幾條線
	int  determine_line_horizontal(int cells[]);		// 計算目前橫的有幾條線
	int  determine_line_cross(int cells[]);		// 計算目前交叉的有幾條線
	int  determine_line_total(int cells[]);		// 計算目前總共有幾條線
	int  print_lines(int player_cells[], int computer_cells[]);		// 印出目前玩家跟電腦各有幾條線，並傳回遊戲是否結束
	int  choose_computer_number(int computer_cells[], int level_array[]);		// 電腦自動選擇要劃掉的數字
	int  find_max(int level_array[]);		// 找出第一個優先等級最高的格子
	int  find_computer_index(int computer_cells[], int p_choose_number);		// 找出玩家輸入之數字對應的電腦格子
	int  player_enter_number(int player_cells[], int *player_cells_p[]);		// 玩家輸入要劃掉的數字

	void play();

private:
	 int  p_cells[25],        //玩家在格子裡依序填寫的數字
        *p_cells_p[25],      //指向玩家數字所在的格子
         c_cells[25],        //電腦在格子裡依序填滿的數字
        *c_cells_p[25],      //指向電腦數字所在的格子
         l_array[25],        //電腦存放選號優先等級的陣列
         over,                     //遊戲是否結束：為尚未結束，>0為結束
         p_choose_number,          //玩家選擇的號碼
         p_choose_c_cells_index,   //玩家選擇的號碼對應到電腦的格子
         c_choose_number;          //電腦選擇的號碼
    char pause;                    //暫停之用
};

#endif