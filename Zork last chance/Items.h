#ifndef _Item_
#define _Item_

#include "Entity.h"
#include "Room.h"

class Item: public Entity
{
public:
	Room* place;

	bool taken = false;
	bool CanStore = false;
	bool IsStored = false;
	int MaxStorage;

	Item(const char*, const char*, Room* room, bool, bool, int);
	~Item();
};

#endif