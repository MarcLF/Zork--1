#ifndef _Room_
#define _Room_

#include "Entity.h"

class Room: public Entity
{
public:
	Room(const char* name, const char* description);
	~Room();

};

#endif