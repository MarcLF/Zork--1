#include <iostream>
#include "World.h"

void World::Exits() const //Here we are giving every exit a description
{
	//Start
	strcpy_s(Exit1[0].desN, "There is nothing relevant into that direction");

	strcpy_s(Exit1[0].desS, "There is nothing relevant into that direction");

	strcpy_s(Exit1[0].desE, "You see a small path which seems to lead into the town");

	strcpy_s(Exit1[0].desW, "There is nothing relevant into that direction");

	//Road
	strcpy_s(Exit1[1].desN, "A small building appears in front of you, it look like an old warehouse");

	strcpy_s(Exit1[1].desS, "The path continues");

	strcpy_s(Exit1[1].desE, "An old Mansion rises before you");

	strcpy_s(Exit1[1].desW, "That big sign you saw now seems to be smaller from the distance");

	//Warehouse
	strcpy_s(Exit1[2].desN, "There is nothing relevant into that direction");

	strcpy_s(Exit1[2].desS, "There is a door which leads back to the road");

	strcpy_s(Exit1[2].desE, "There is nothing relevant into that direction");

	strcpy_s(Exit1[2].desW, "There is nothing relevant into that direction");

	//Sewers
	strcpy_s(Exit1[3].desN, "There is nothing relevant into that direction");

	strcpy_s(Exit1[3].desS, "There is nothing relevant into that direction");

	strcpy_s(Exit1[3].desE, "There is a door which leads back to the road");

	strcpy_s(Exit1[3].desW, "There is nothing relevant into that direction");

	//Purifying plant
	strcpy_s(Exit1[4].desN, "There is a small rusty old door which seems to lead down into the sewers");

	strcpy_s(Exit1[4].desS, "There is nothing relevant into that direction");

	strcpy_s(Exit1[4].desE, "There is a big iron door which leads back to the road");

	strcpy_s(Exit1[4].desW, "There is nothing relevant into that direction");

	//Gym
	strcpy_s(Exit1[5].desN, "There is nothing relevant into that direction");

	strcpy_s(Exit1[5].desS, "There is nothing relevant into that direction");

	strcpy_s(Exit1[5].desW, "There is a door which leads back to the road");

	strcpy_s(Exit1[5].desE, "There is nothing relevant into that direction");

	//Frost house
	strcpy_s(Exit1[6].desN, "There is an icy door which leads back to the road");

	strcpy_s(Exit1[6].desS, "There is nothing relevant into that direction");

	strcpy_s(Exit1[6].desE, "There is nothing relevant into that direction");

	strcpy_s(Exit1[6].desW, "There is nothing relevant into that direction");

	//Maze
	strcpy_s(Exit1[7].desN, "There is nothing relevant into that direction");

	strcpy_s(Exit1[7].desS, "There is nothing relevant into that direction");

	strcpy_s(Exit1[7].desE, "There is a small path which leads back to the road");

	strcpy_s(Exit1[7].desW, "There is nothing relevant into that direction");

	//Jail
	strcpy_s(Exit1[8].desN, "There is nothing relevant into that direction");

	strcpy_s(Exit1[8].desS, "There is nothing relevant into that direction");

	strcpy_s(Exit1[8].desE, "There is nothing relevant into that direction");

	strcpy_s(Exit1[8].desW, "There is an armored door which leads back to the road");

	//Old mansion
	strcpy_s(Exit1[9].desN, "There is nothing relevant into that direction");

	strcpy_s(Exit1[9].desS, "There is nothing relevant into that direction");

	strcpy_s(Exit1[9].desE, "There is nothing relevant into that direction");

	strcpy_s(Exit1[9].desW, "You see a golden door which leads back to the road");

	//Road 2
	strcpy_s(Exit1[10].desN, "The path continues");

	strcpy_s(Exit1[10].desS, "The path continues");

	strcpy_s(Exit1[10].desE, "There is a locked door which leads to the jail");

	strcpy_s(Exit1[10].desW, "There is a door which leads to the sewers");

	//Road 3
	strcpy_s(Exit1[11].desN, "The path continues");

	strcpy_s(Exit1[11].desS, "The path continues");

	strcpy_s(Exit1[11].desE, "There is a door which leads to the gym");

	strcpy_s(Exit1[11].desW, "There is a door which leads to the purifying plant");

	//Road 4
	strcpy_s(Exit1[12].desN, "The path continues");

	strcpy_s(Exit1[12].desS, "There is an icy door");

	strcpy_s(Exit1[12].desE, "You see the entrance of a maze");

	strcpy_s(Exit1[12].desW, "There is nothing relevant into that direction");
}
