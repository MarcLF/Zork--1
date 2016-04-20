#ifndef _World_
#define _World_

#include"Vector.h"
#include"String.h"
#include"Entity.h"
#include"Room.h"
#include"Player.h"
#include"Exits.h"
#include"Items.h"

class World
{
public:
	World(); //Constructor

	Player* player = nullptr; //Player name

	Vector<Room*> Room1;//Rooms
	Vector<Exit*> Exit1;//Exits
	Vector<Item*> Item1;//Items

	void CreateWorld();
	void GetInput(MyString&input);
	void Exits();
	void Items();

	//Take / Drop
	void TakeObject(MyString&input);
	void DropObject(MyString&input);

	//Move functions
	void GoNorth();
	void GoSouth();
	void GoEast();
	void GoWest();

	//Look functions
	void Look() const;
	void LookNorth() const;
	void LookSouth() const;
	void LookWest() const;
	void LookEast() const;

	//Open/close door functions
	void closeDoor();
	bool openDoor = false;

	//Other actions
	bool BribeGuards = false;
	void Maze(); //When the player enters the room Inside the Maze it will automatically call this function

	//Cash image
	void CashImage() const;

	~World(); //Destructor
};

#endif