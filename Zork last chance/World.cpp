#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "World.h"

//constructor
World::World()
{
	Room1 = new Room[20]; //Room1 = Rooms
	player = new Player; //player = Player
	Exit1 = new Exit[20]; //Exit1 = Exits
	CashLeft = new Items; //Cash left in the map
	CashInv = new Items; //Cash inventory
}

void World::CreateWorld()
{
	char* RoomNames[14] = { "Start", "Road", "Warehouse", "Sewers", "Purifying Plant", "Gym", "Frost House", "Maze", "Jail", "Old Mansion", "Road", "Road", "Road", "Inside the Maze"}; // Room Names
	for (int j = 0; j < 14; j++)
	{
		strcpy_s((Room1 + j)->name, RoomNames[j]); //Here we are assignint each name a room
	}

	//Room descriptions
	char* RoomsInfo[14] =
	{
		"You see a big sign which says WELCOME to the COWARD CITY! Where all cowards come to hide from the rest of the world!",
		"You find yourself in the middle of a dirty old road.",
		"You are in a warehouse, in front of you there is a table with a few bills.",
		"This place stinks! I guess that's because this are the sewers.",
		"You are in a purifying plant.",
		"An old gym with a small boxing ring in the middle.",
		"If you were wondering why the main door was frost as hell now you know the reason, this house is a freezer!",
		"What first seemed like a garden it looks now like an immense maze. Becare where you go or you might get lost.",
		"It seems this building was a jail once, now its nothing but some old empty cells.",
		"After going across that ugly golden door, you find yourself in the living room of a dusty big old mansion.",
		"Moving a little forward you start discerning more buildings around you.",
		"You are still on the same road surrounded by some buildings, ah..this road seems endless.",
		"This is the end of the road, in front of you shows up a small building with a strange frost door.",
		"Suddenly you find yourself lost deep into the maze."
	};
	for (int j = 0; j < 14; j++)
	{
		strcpy_s((Room1 + j)->desc, RoomsInfo[j]); //Here we are assignint each description a room
	}
}

//destructor
World::~World()
{
	delete[] Room1;
	delete player;
	delete[]Exit1;
	delete CashLeft;
	delete CashInv;
}