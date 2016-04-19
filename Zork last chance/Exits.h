#ifndef _Exits_
#define _Exits_

#include "Entity.h"

class Exit
{
public:
	MyString desN, desS, desE, desW;

	Exit(const char* desN, const char* desS, const char* desE, const char* desW);
	~Exit();

	int lockedDoor = 1;
};

#endif 