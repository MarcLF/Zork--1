#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "World.h"

#define EQUAL 0

World::World() //constructor
{
	Room1 = new Room[18];
	p1 = new Player;
	E1 = new Exit[60];
}

void World::CreateWorld()
{
	char* RoomNames[10] = { "Road", "Start", "Warehouse", "Sewers", "Purifying Plant", "Gym", "Frost House", "Maze", "Jail", "Old Mansion" }; // Room Names
	for (int j = 0; j < 10; j++)
	{
		strcpy((Room1 + j)->Room::Room.name, RoomNames[j]); //Here we are assignint each name a room
	}
	char* RoomsInfo[] = //Room descriptions
	{
		"Road DESCRIPTION //PLACEHOLDER//"
		"Start DESCRIPTION //PLACEHOLDER//"
		"Warehouse DESCRIPTION //PLACEHOLDER//"
		"Sewers DESCRIPTION //PLACEHOLDER//"
		"Purifying Plant DESCRIPTION //PLACEHOLDER//"
		"Gym DESCRIPTION //PLACEHOLDER//"
		"Frost House DESCRIPTION //PLACEHOLDER//"
		"Maze DESCRIPTION //PLACEHOLDER//"
		"Jail DESCRIPTION //PLACEHOLDER//"
		"Old Mansion DESCRIPTION //PLACEHOLDER//"
	};
	for (int j = 0; j < 10; j++)
	{
		strcpy((Room1 + j)->Room::Room.desc, RoomsInfo[j]); //Here we are assignint each description a room
	}
}

World::~World()//destructor
{
	delete[] Room1;
	delete p1;
	delete[]E1;
}

void World::Input()// Here we recieve the Input from the player and execute his/her order
{
	char Input[10];
	scanf("%c", &Input);

	if (strcmp("exit", Input) == EQUAL)//strcmp returns 0 if both strings are the same
	{
		exit(0);
	}
	if ((strcmp("go north", Input) == EQUAL) || (strcmp("go n", Input) == EQUAL) || (strcmp("n", Input) == EQUAL))
	{
		GoNorth();
	}
	if ((strcmp("go south", Input) == EQUAL) || (strcmp("go s", Input) == EQUAL || (strcmp("s", Input) == EQUAL)))
	{
		GoSouth();
	}
	
	if ((strcmp("go east", Input) == EQUAL) || (strcmp("go e", Input) == EQUAL || (strcmp("e", Input) == EQUAL)))
	{
		GoEast();
	}
	if ((strcmp("go west", Input) == EQUAL) || (strcmp("go w", Input) == EQUAL || (strcmp("w", Input) == EQUAL)))
	{
		GoWest();
	}
}

int main()
{

	return 0;
}