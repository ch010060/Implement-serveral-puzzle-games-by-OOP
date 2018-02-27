#ifndef STATUS_H
#define STATUS_H
#include"data.h"
#include"bank.h"

class status : public data
{
public:
	status();
	~status();

	void printstatus();

};

#endif