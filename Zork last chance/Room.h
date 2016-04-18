#ifndef _Room_
#define _Room_

#include "Entity.h"
#include "String.h"

class Room: public Entity
{
public:
	Room(const char* name, const char* description);

};

#endif