#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "World.h"

//constructor
World::World()
{
	player = new Player; //player = Player
}

void World::CreateWorld()
{
	/* Rooms */

	//Start 0
	entity.push_back(new Room("Start\n", "You see a big sign which says WELCOME to the COWARD CITY!Where all cowards come to hide from the rest of the world! There is a bag on the floor\n", ROOM));
	//Road 1
	entity.push_back(new Room("Road\n", "You find yourself in the middle of a dirty old road.\n", ROOM));
	//Warehouse 2
	entity.push_back(new Room("Warehouse\n", "You are in a warehouse, in front of you there is a table with a few bills.\n", ROOM));
	//Sewers 3
	entity.push_back(new Room("Sewers\n", "This place stinks! I guess that's because this are the sewers.\n", ROOM));
	//Purifying Plant 4
	entity.push_back(new Room("Purifying Plant\n", "You are in a purifying plant.\n", ROOM));
	//Gym 5
	entity.push_back(new Room("Gym\n", "An old gym with a small boxing ring in the middle.\n", ROOM));
	//Frost House 6
	entity.push_back(new Room("Frost House\n", "If you were wondering why the main door was frost as hell now you know the reason, this house is a freezer!\n", ROOM));
	//Maze 7
	entity.push_back(new Room("Maze\n", "What first seemed like a garden it looks now like an immense maze. Becare where you go or you might get lost.\n", ROOM));
	//Jail 8
	entity.push_back(new Room("Jail\n", "It seems this building was a jail once, now its nothing but some old empty cells.\n", ROOM));
	//Old Mansion 9
	entity.push_back(new Room("Old Mansion\n", "After going across that ugly golden door, you find yourself in the living room of a dusty big old mansion.\n", ROOM));
	//Road 2 10
	entity.push_back(new Room("Road\n", "Moving a little forward you start discerning more buildings around you.\n", ROOM));
	//Road 3 11
	entity.push_back(new Room("Road\n", "You are still on the same road surrounded by some buildings, ah..this road seems endless.\n", ROOM));
	//Road 4 12
	entity.push_back(new Room("Road\n", "This is the end of the road, in front of you shows up a small building with a strange frost door.\n", ROOM));
	//Inside the Maze 13
	entity.push_back(new Room("Inside the Maze\n", "Suddenly you find yourself lost deep into the maze. While you are trapped here you won't be able to take/drop any object or put them into another one.\n", ROOM));

	/* Exits */

	//0
	entity.push_back(new Exit("Road1 to Road2", "The path continues", (Room*)entity[1], (Room*)entity[10], false, south, EXIT)); //0
	// 1
	entity.push_back(new Exit("Road2 to Road1", "The path continues", (Room*)entity[10], (Room*)entity[1], false, north, EXIT));
	// 2
	entity.push_back(new Exit("Road2 to Road3", "The path continues.", (Room*)entity[10], (Room*)entity[11], false, south, EXIT));
	// 3
	entity.push_back(new Exit("Road3 to Road2", "The path continues.", (Room*)entity[11], (Room*)entity[10], false, north, EXIT));
	// 4
	entity.push_back(new Exit("Road3 to Road4", "The path continues.", (Room*)entity[11], (Room*)entity[12], false, south, EXIT));
	// 5
	entity.push_back(new Exit("Road4 to Road3", "The path continues.", (Room*)entity[12], (Room*)entity[11], false, north, EXIT));
	// 6
	entity.push_back(new Exit("Start to Road1", "You see a small path which seems to lead into the town.", (Room*)entity[0], (Room*)entity[1], false, east, EXIT));
	// 7
	entity.push_back(new Exit("Road1 to Start", "That big sign you saw now seems to be smaller from the distance.", (Room*)entity[1], (Room*)entity[0], false, west, EXIT));
	// 8
	entity.push_back(new Exit("Warehouse to Road1", "There is a door which leads back to the road.", (Room*)entity[2], (Room*)entity[1], true, south, EXIT));
	// 9
	entity.push_back(new Exit("Road1 to Warehouse", "A small building appears in front of you, it look like an old warehouse.", (Room*)entity[1], (Room*)entity[2], true, north, EXIT));
	// 10
	entity.push_back(new Exit("Road1 to Old Mansion", "An old Mansion rises before you.", (Room*)entity[1], (Room*)entity[9], false, east, EXIT));
	// 11
	entity.push_back(new Exit("Old Mansion to Road1", "You see the golden door which leads back to the road.", (Room*)entity[9], (Room*)entity[1], false, west, EXIT));
	// 12
	entity.push_back(new Exit("Road2 to Jail", "There is a locked door which leads to the jail.", (Room*)entity[10], (Room*)entity[8], false, east, EXIT));
	// 13
	entity.push_back(new Exit("Jail to Road2", "There is an armored door which leads back to the road.", (Room*)entity[8], (Room*)entity[10], false, west, EXIT));
	// 14
	entity.push_back(new Exit("Sewers to Road2", "There is a door which leads back to the road.", (Room*)entity[3], (Room*)entity[10], false, east, EXIT));
	// 15
	entity.push_back(new Exit("Road2 to Sewers", "There is a door which leads into the sewers.", (Room*)entity[10], (Room*)entity[3], false, west, EXIT));
	// 16
	entity.push_back(new Exit("Road3 to Gym", "There is a door which leads to the gym.", (Room*)entity[11], (Room*)entity[5], false, east, EXIT));
	// 17
	entity.push_back(new Exit("Gym to Road3", "There is a door which leads back to the road.", (Room*)entity[5], (Room*)entity[11], false, west, EXIT));
	// 18
	entity.push_back(new Exit("Purifying Plant to Road3", "There is a big iron door which leads back to the road.", (Room*)entity[4], (Room*)entity[11], false, east, EXIT));
	// 19
	entity.push_back(new Exit("Road3 to Purifying Plant", "There is a door which leads to the Purifying Plant.", (Room*)entity[11], (Room*)entity[4], true, west, EXIT));
	// 20
	entity.push_back(new Exit("Road4 to Maze", "You are inside the maze.", (Room*)entity[12], (Room*)entity[7], false, east, EXIT));
	// 21
	entity.push_back(new Exit("Maze to Inside the Maze", "You are inside the maze.", (Room*)entity[7], (Room*)entity[13], false, north, EXIT));
	// 22
	entity.push_back(new Exit("Maze to Inside the Maze", "You are inside the maze.", (Room*)entity[7], (Room*)entity[13], false, south, EXIT));
	// 23
	entity.push_back(new Exit("Maze to Inside the Maze", "You are inside the maze.", (Room*)entity[7], (Room*)entity[13], false, east, EXIT));
	// 24
	entity.push_back(new Exit("Maze to Inside the Maze", "You are inside the maze.", (Room*)entity[7], (Room*)entity[13], false, west, EXIT));
	// 25
	entity.push_back(new Exit("Road4 to Frost House", "There is an icy door.", (Room*)entity[12], (Room*)entity[6], false, south, EXIT));
	// 26
	entity.push_back(new Exit("Frost House to Road4", "You see the icy door which leads back to the road.", (Room*)entity[6], (Room*)entity[12], false, north, EXIT));
	// 27
	entity.push_back(new Exit("Purifyong Plant to Sewers", "Entrance to the Sewers.", (Room*)entity[4], (Room*)entity[3], false, north, EXIT));
	// 28
	entity.push_back(new Exit("Sewers to Purifying Plant", "Entrance to the Purifying Plant.", (Room*)entity[3], (Room*)entity[4], false, south, EXIT));

	/* Items */

	//Cash - 43
	entity.push_back(new Item("cash", "A hundred bucks.", (Room*)entity[2], false, false, 0, ITEM));
	//Key - 44
	entity.push_back(new Item("key", "An old rusty key.", (Room*)entity[13], false, false, 0, ITEM));
	//Gloves - 45
	entity.push_back(new Item("mail Gloves", "A Heavy rough pair of mail guantlets.", (Room*)entity[4], false, false, 0, ITEM));
	//Bag - 46
	entity.push_back(new Item("bag", "A small bag, usefull to carry some objects.", (Room*)entity[0], true, false, 5, ITEM));

	player->Pos = (Room*)entity[0];

	//TEST CODE
	//Item1[1]->taken = true;
	//Item1[0]->taken = true;
}

//destructor
World::~World()
{
	delete player;
}