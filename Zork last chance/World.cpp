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
	Room1.push_back(new Room("Start\n", "You see a big sign which says WELCOME to the COWARD CITY!Where all cowards come to hide from the rest of the world!\n"));
	//Road 1
	Room1.push_back(new Room("Road\n", "You find yourself in the middle of a dirty old road.\n"));
	//Warehouse 2
	Room1.push_back(new Room("Warehouse\n", "You are in a warehouse, in front of you there is a table with a few bills.\n"));
	//Sewers 3
	Room1.push_back(new Room("Sewers\n", "This place stinks! I guess that's because this are the sewers.\n"));
	//Purifying Plant 4
	Room1.push_back(new Room("Purifying Plant\n", "You are in a purifying plant.\n"));
	//Gym 5
	Room1.push_back(new Room("Gym\n", "An old gym with a small boxing ring in the middle.\n"));
	//Frost House 6
	Room1.push_back(new Room("Frost House\n", "If you were wondering why the main door was frost as hell now you know the reason, this house is a freezer!\n"));
	//Maze 7
	Room1.push_back(new Room("Maze\n", "What first seemed like a garden it looks now like an immense maze. Becare where you go or you might get lost.\n"));
	//Jail 8
	Room1.push_back(new Room("Jail\n", "It seems this building was a jail once, now its nothing but some old empty cells.\n"));
	//Old Mansion 9
	Room1.push_back(new Room("Old Mansion\n", "After going across that ugly golden door, you find yourself in the living room of a dusty big old mansion.\n"));
	//Road 2 10
	Room1.push_back(new Room("Road\n", "Moving a little forward you start discerning more buildings around you.\n"));
	//Road 3 11
	Room1.push_back(new Room("Road\n", "You are still on the same road surrounded by some buildings, ah..this road seems endless.\n"));
	//Road 4 12
	Room1.push_back(new Room("Road\n", "This is the end of the road, in front of you shows up a small building with a strange frost door.\n"));
	//Inside the Maze 13
	Room1.push_back(new Room("Inside the Maze\n", "Suddenly you find yourself lost deep into the maze.\n"));

	/* Exits */

	//0
	Exit1.push_back(new Exit("Road1 to Road2", "The path continues", Room1[1], Room1[10], false, south)); //0
	// 1
	Exit1.push_back(new Exit("Road2 to Road1", "The path continues", Room1[10], Room1[1], false, north));
	// 2
	Exit1.push_back(new Exit("Road2 to Road3", "The path continues", Room1[10], Room1[11], false, south));
	// 3
	Exit1.push_back(new Exit("Road3 to Road2", "The path continues", Room1[11], Room1[10], false, north));
	// 4
	Exit1.push_back(new Exit("Road3 to Road4", "The path continues", Room1[11], Room1[12], false, south));
	// 5
	Exit1.push_back(new Exit("Road4 to Road3", "The path continues", Room1[12], Room1[11], false, north));
	// 6
	Exit1.push_back(new Exit("Start to Road1", "You see a small path which seems to lead into the town", Room1[0], Room1[1], false, east)); 
	// 7
	Exit1.push_back(new Exit("Road1 to Start", "That big sign you saw now seems to be smaller from the distance", Room1[1], Room1[0], false, west));
	// 8
	Exit1.push_back(new Exit("Warehouse to Road1", "There is a door which leads back to the road", Room1[2], Room1[1], true, south)); 
	// 9
	Exit1.push_back(new Exit("Road1 to Warehouse", "A small building appears in front of you, it look like an old warehouse", Room1[1], Room1[2], true, north)); 
	// 10
	Exit1.push_back(new Exit("Road1 to Old Mansion", "An old Mansion rises before you", Room1[1], Room1[9], false, east)); 
	// 11
	Exit1.push_back(new Exit("Old Mansion to Road1", "You see the golden door which leads back to the road", Room1[9], Room1[1], false, west)); 
	// 12
	Exit1.push_back(new Exit("Road2 to Jail", "There is a locked door which leads to the jail", Room1[10], Room1[8], false, east)); 
	// 13
	Exit1.push_back(new Exit("Jail to Road2", "There is an armored door which leads back to the road", Room1[8], Room1[10], false, west)); 
	// 14
	Exit1.push_back(new Exit("Sewers to Road2", "There is a door which leads back to the road", Room1[3], Room1[10], false, east)); 
	// 15
	Exit1.push_back(new Exit("Road2 to Sewers", "There is a door which leads into the sewers", Room1[10], Room1[3], false, west)); 
	// 16
	Exit1.push_back(new Exit("Road3 to Gym", "There is a door which leads to the gym", Room1[11], Room1[5], false, east)); 
	// 17
	Exit1.push_back(new Exit("Gym to Road3", "There is a door which leads back to the road", Room1[5], Room1[11], false, west));
	// 18
	Exit1.push_back(new Exit("Purifying Plant to Road3", "There is a big iron door which leads back to the road", Room1[4], Room1[11], false, east));
	// 19
	Exit1.push_back(new Exit("Road3 to Purifying Plant", "There is a door which leads to the Purifying Plant", Room1[11], Room1[4], true, west)); 
	// 20
	Exit1.push_back(new Exit("Road4 to Maze", "You are inside the maze", Room1[12], Room1[7], false, east));
	// 21
	Exit1.push_back(new Exit("Maze to Inside the Maze", "You are inside the maze", Room1[7], Room1[13], false, north));
	// 22
	Exit1.push_back(new Exit("Maze to Inside the Maze", "You are inside the maze", Room1[7], Room1[13], false, south)); 
	// 23
	Exit1.push_back(new Exit("Maze to Inside the Maze", "You are inside the maze", Room1[7], Room1[13], false, east));
	// 24
	Exit1.push_back(new Exit("Maze to Inside the Maze", "You are inside the maze", Room1[7], Room1[13], false, west));
	// 25
	Exit1.push_back(new Exit("Road4 to Frost House", "There is an icy door", Room1[12], Room1[6], false, south)); 
	// 26
	Exit1.push_back(new Exit("Frost House to Road4", "You see the icy door which leads back to the road", Room1[6], Room1[12], false, north)); 
	// 27
	Exit1.push_back(new Exit("Purifyong Plant to Sewers", "Entrance to the Sewers", Room1[4], Room1[3], false, north));
	// 28
	Exit1.push_back(new Exit("Sewers to Purifying Plant", "Entrance to the Purifying Plant", Room1[3], Room1[4], false, south)); 

	/* Items */

	//Cash
	Item1.push_back(new Item("cash", "A hundred bucks", Room1[2], false, false));
	//Key
	Item1.push_back(new Item("key", "An old rusty key", Room1[13], false, false));
	//Gloves
	Item1.push_back(new Item("mail Gloves", "A Heavy rough pair of mail guantlets", Room1[4], false, false));
	//Bag
	Item1.push_back(new Item("bag", "A small bag, usefull to carry some objects", Room1[0], true, false));

	player->Pos = Room1[0];
}

//destructor
World::~World()
{
	delete player;
}