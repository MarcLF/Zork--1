#ifndef _Exits_
#define _Exits_

#include "Entity.h"
#include "Room.h"

enum direction{ north, south, east, west, up, down };

class Exit: public Entity
{
public:
	MyString description2;

	Room* origin;
	Room* destination;

	bool door;

	direction direction1;

	Exit(const char* name, const char* description, Room*, Room*, bool, direction, Type);
	~Exit();

	int lockedDoor = 1;
};

#endif 