#ifndef _World_
#define _World_

#include"Vector.h"
#include"String.h"
#include"Entity.h"
#include"Room.h"
#include"Player.h"
#include"Exits.h"
#include"Items.h"

#define NUM_ROOMS 47
#define NUM_EXITS 47
#define NUM_ITEMS 47

class World
{
public:
	World(); //Constructor

	Player* player = nullptr; //Player name

	Vector<Entity*> entity;

	void CreateWorld();
	void Input(MyString&input);
	void Items();

	//Take / Drop / Put
	void TakeObject(MyString&input);
	void DropObject(MyString&input);
	void PutObject(MyString&input);

	//Inventory
	void Inventory();

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

	//Other actions
	void Maze(); //When the player enters the room Inside the Maze it will automatically call this function

	//Items pictures
	void Pictures(MyString&input) const;

	~World(); //Destructor
};

#endif