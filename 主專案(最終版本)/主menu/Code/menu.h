#ifndef MENU_H
#define MENU_H

#include"menu_game.h"
#include"data.h"
#include"status.h"
#include"shop.h"
#include"picture.h"
#include"Save.h"
#include"Load.h"
#include"bank.h"
#include"success.h"
#include"QB.h"



class menu : public menu_game,public status,public shop,public picture,public Save,public Load,public bank,public success,public QB
{
public:
	menu();
	~menu();

	void mainmenu();


};

#endif
