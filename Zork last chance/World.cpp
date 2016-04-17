#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "World.h"

//constructor
World::World()
{
	player = new Player; //player = Player
	Exit1 = new Exit[20]; //Exit1 = Exits
	CashLeft = new Items; //Cash left in the map
	CashInv = new Items; //Cash inventory
}

void World::CreateWorld()
{
	Room1.push_back(new Room("Start\n", "You see a big sign which says WELCOME to the COWARD CITY!Where all cowards come to hide from the rest of the world!\n"));
	Room1.push_back(new Room("Road\n", "You find yourself in the middle of a dirty old road.\n"));
	Room1.push_back(new Room("Warehouse\n", "You are in a warehouse, in front of you there is a table with a few bills.\n"));
	Room1.push_back(new Room("Sewers\n", "This place stinks! I guess that's because this are the sewers.\n"));
	Room1.push_back(new Room("Purifying Plant\n", "You are in a purifying plant.\n"));
	Room1.push_back(new Room("Gym\n", "An old gym with a small boxing ring in the middle.\n"));
	Room1.push_back(new Room("Frost House\n", "If you were wondering why the main door was frost as hell now you know the reason, this house is a freezer!\n"));
	Room1.push_back(new Room("Maze\n", "What first seemed like a garden it looks now like an immense maze. Becare where you go or you might get lost.\n"));
	Room1.push_back(new Room("Jail\n", "It seems this building was a jail once, now its nothing but some old empty cells.\n"));
	Room1.push_back(new Room("Old Mansion\n", "After going across that ugly golden door, you find yourself in the living room of a dusty big old mansion.\n"));
	Room1.push_back(new Room("Road\n", "Moving a little forward you start discerning more buildings around you.\n"));
	Room1.push_back(new Room("Road\n", "You are still on the same road surrounded by some buildings, ah..this road seems endless.\n"));
	Room1.push_back(new Room("Road\n", "This is the end of the road, in front of you shows up a small building with a strange frost door.\n"));
	Room1.push_back(new Room("Inside the Maze\n", "Suddenly you find yourself lost deep into the maze.\n"));
}

//destructor
World::~World()
{
	delete player;
	delete[]Exit1;
	delete CashLeft;
	delete CashInv;
}