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

	//Start
	Room1.push_back(new Room("Start\n", "You see a big sign which says WELCOME to the COWARD CITY!Where all cowards come to hide from the rest of the world!\n"));
	//Road
	Room1.push_back(new Room("Road\n", "You find yourself in the middle of a dirty old road.\n"));
	//Warehouse
	Room1.push_back(new Room("Warehouse\n", "You are in a warehouse, in front of you there is a table with a few bills.\n"));
	//Sewers
	Room1.push_back(new Room("Sewers\n", "This place stinks! I guess that's because this are the sewers.\n"));
	//Purifying Plant
	Room1.push_back(new Room("Purifying Plant\n", "You are in a purifying plant.\n"));
	//Gym
	Room1.push_back(new Room("Gym\n", "An old gym with a small boxing ring in the middle.\n"));
	//Frost House
	Room1.push_back(new Room("Frost House\n", "If you were wondering why the main door was frost as hell now you know the reason, this house is a freezer!\n"));
	//Maze
	Room1.push_back(new Room("Maze\n", "What first seemed like a garden it looks now like an immense maze. Becare where you go or you might get lost.\n"));
	//Jail
	Room1.push_back(new Room("Jail\n", "It seems this building was a jail once, now its nothing but some old empty cells.\n"));
	//Old Manions
	Room1.push_back(new Room("Old Mansion\n", "After going across that ugly golden door, you find yourself in the living room of a dusty big old mansion.\n"));
	//Road 2
	Room1.push_back(new Room("Road\n", "Moving a little forward you start discerning more buildings around you.\n"));
	//Road 3
	Room1.push_back(new Room("Road\n", "You are still on the same road surrounded by some buildings, ah..this road seems endless.\n"));
	//Road 4
	Room1.push_back(new Room("Road\n", "This is the end of the road, in front of you shows up a small building with a strange frost door.\n"));
	//Inside the Maze
	Room1.push_back(new Room("Inside the Maze\n", "Suddenly you find yourself lost deep into the maze.\n"));

	/* Exits */

	//Start
	Exit1.push_back(new Exit("There is nothing relevant into that direction", "There is nothing relevant into that direction", "You see a small path which seems to lead into the town", "There is nothing relevant into that direction"));
	//Road
	Exit1.push_back(new Exit("A small building appears in front of you, it look like an old warehouse", "The path continues", "An old Mansion rises before you", "That big sign you saw now seems to be smaller from the distance"));
	//Warehouse
	Exit1.push_back(new Exit("There is nothing relevant into that direction", "There is a door which leads back to the road", "There is nothing relevant into that direction", "There is nothing relevant into that direction"));
	//Sewers
	Exit1.push_back(new Exit("There is nothing relevant into that direction", "There is nothing relevant into that direction", "There is a door which leads back to the road", "There is nothing relevant into that direction"));
	//Purifying plant
	Exit1.push_back(new Exit("There is a small rusty old door which seems to lead down into the sewers", "There is nothing relevant into that direction", "There is a big iron door which leads back to the road", "There is nothing relevant into that direction"));
	//Gym
	Exit1.push_back(new Exit("There is nothing relevant into that direction", "There is nothing relevant into that direction", "There is a door which leads back to the road", "There is nothing relevant into that direction"));
	//Frost house
	Exit1.push_back(new Exit("There is an icy door which leads back to the road", "There is nothing relevant into that direction", "There is nothing relevant into that direction", "There is nothing relevant into that direction"));
	//Maze
	Exit1.push_back(new Exit("There is nothing relevant into that direction", "There is nothing relevant into that direction", "There is a small path which leads back to the road", "There is nothing relevant into that direction"));
	//Jail
	Exit1.push_back(new Exit("There is nothing relevant into that direction", "There is nothing relevant into that direction", "There is nothing relevant into that direction", "There is an armored door which leads back to the road"));
	//Old mansion
	Exit1.push_back(new Exit("There is nothing relevant into that direction", "There is nothing relevant into that direction", "There is nothing relevant into that direction", "You see a golden door which leads back to the road"));
	//Road 2
	Exit1.push_back(new Exit("The path continues", "The path continues", "There is a locked door which leads to the jail", "There is a door which leads to the sewers"));
	//Road 3
	Exit1.push_back(new Exit("The path continues", "The path continues", "There is a door which leads to the gym", "There is a door which leads to the purifying plant"));
	//Road 4
	Exit1.push_back(new Exit("The path continues", "There is an icy door", "You see the entrance of a maze", "There is nothing relevant into that direction"));

	/* Items */

	//Cash
	Item1.push_back(new Item("Cash", "A hundred bucks", Room1[2]));
	//Key
	Item1.push_back(new Item("Key", "An old rusty key", Room1[13]));
	//Gloves
	Item1.push_back(new Item("Mail Gloves", "A Heavy rough pair of mail guantlets", Room1[4]));
}


void World::Exits() //Here we are giving every exit a descriptionription
{
	
}

//destructor
World::~World()
{
	delete player;
}