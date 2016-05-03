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

	Item(const char*, const char*, Room* room, bool, bool);
	~Item();
};

#endif