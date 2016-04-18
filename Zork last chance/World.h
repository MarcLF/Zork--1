#ifndef _World_
#define _World_

#include"Room.h"
#include"Player.h"
#include"Exits.h"
#include"Items.h"
#include"Vector.h"
#include"String.h"

class World
{
public:

	World(); //Constructor

	Player* player = nullptr; //Player name
	Items* CashInv = nullptr;//Cash you have in the inventory
	Items* CashLeft = nullptr;//Cash left in the map

	Vector<Room*>Room1;//Rooms
	Vector<Exit*>Exit1;//Exits

	void CreateWorld();
	void Input(); //Read the input from the player
	void GetInput(MyString&input);
	void Exits();

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

	~World(); //Destructor
};

#endif