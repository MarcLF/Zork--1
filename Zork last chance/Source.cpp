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
Room::Room()
{
}
Exit::Exit()
{
}

void World::CreateWorld()
{
	char* RoomNames[10] = { "Road", "Start", "Warehouse", "Sewers", "Purifying Plant", "Gym", "Frost House", "Maze", "Jail", "Old Mansion" }; // Room Names
	for (int j = 0; j < 10; j++)
	{
		strcpy_s((Room1 + j)-> name, RoomNames[j]); //Here we are assignint each name a room
	}
	//Room descriptions
	char* RoomsInfo[] = 
	{
		"You find  yourself in the middle of a dirty old road",
		"You see a big sign which says WELCOME to the COWARD CITY! Where all cowards come to hide from the world!/",
		"Warehouse DESCRIPTION //PLACEHOLDER//",
		"Sewers DESCRIPTION //PLACEHOLDER//",
		"Purifying Plant DESCRIPTION //PLACEHOLDER//",
		"Gym DESCRIPTION //PLACEHOLDER//",
		"Frost House DESCRIPTION //PLACEHOLDER//",
		"Maze DESCRIPTION //PLACEHOLDER//",
		"Jail DESCRIPTION //PLACEHOLDER//",
		"Old Mansion DESCRIPTION //PLACEHOLDER//",
	};
	for (int j = 0; j < 10; j++)
	{
		strcpy_s((Room1 + j)-> desc, RoomsInfo[j]); //Here we are assignint each description a room
	}
}

//destructors
World::~World()
{
	delete[] Room1;
	delete p1;
	delete[]E1;
}
Room::~Room()
{
}
Exit::~Exit()
{
}

void World::Input()// Here we recieve the Input from the player and execute his/her order
{
	char Input[10];
	scanf_s("%c", &Input);

	if (strcmp("exit", Input) == EQUAL || strcmp("quit", Input) == EQUAL)//strcmp returns 0 if both strings are the same
	{
		exit(0);
	}
	if (strcmp("help", Input) == EQUAL || strcmp("Help", Input) == EQUAL)
	{
		printf("Move options -> To go north: go north | go n | n\nTo go south: go south | go s | s\nTo go east: go east | go e | e\nTo go west: go west | go e | e\nIf you want to get information about the room you are in type 'Look'\n or if you prefer to know about the exits you can take type: look [direction] | look [n/s/e/w]\Type 'exit' or 'quit' to leave");
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
	if ((strcmp("look north", Input) == EQUAL) || (strcmp("look n", Input) == EQUAL || (strcmp("l n", Input) == EQUAL)))
	{
		LookNorth();
	}
	if ((strcmp("look south", Input) == EQUAL) || (strcmp("look s", Input) == EQUAL || (strcmp("l s", Input) == EQUAL)))
	{
		LookSouth();
	}
	if ((strcmp("look east", Input) == EQUAL) || (strcmp("look e", Input) == EQUAL || (strcmp("l e", Input) == EQUAL)))
	{
		LookEast();
	}
	if ((strcmp("look west", Input) == EQUAL) || (strcmp("look w", Input) == EQUAL || (strcmp("l w", Input) == EQUAL)))
	{
		LookWest();
	}
	else
	{
		printf("I didn't understand your order, please try another one or type 'help' to see more info");
	}
}

void World::Exits() const //Here we are giving every exit a description
{
	strcpy_s(E1[0].name, "Start");
	strcpy_s(E1[0].desE, "You see a small path which seems to lead into the town");

	strcpy_s(E1[1].name, "Road");
	strcpy_s(E1[1].desE, "The road continues");

	strcpy_s(E1[1].name, "Road");
	strcpy_s(E1[1].desN, "In the distance you observe a small warehouse");

	strcpy_s(E1[2].name, "Warehouse");
	strcpy_s(E1[2].desS, "There is a door which leads back to the road");

	strcpy_s(E1[4].name, "Road");
	strcpy_s(E1[4].desS, "There is a small entrance which leads into the sewers");
}

//Movement
void World::GoNorth()
{
	if (p1[0].pos == 0)
	{
		puts(Room1[p1[0].pos].name);
	}

}

void World::GoSouth()
{
	if (p1[0].pos == 0)
	{
		puts(Room1[p1[0].pos].name);
	}

}

void World::GoEast()
{
	if (p1[0].pos == 0)
	{
		puts(Room1[p1[0].pos].name);
	}

}

void World::GoWest()
{
	if (p1[0].pos == 0)
	{
		puts(Room1[p1[0].pos].name);
	}

}

void World::LookNorth()
{
	if (p1[0].pos == 0){
		printf("\n%s\n", E1[p1[0].pos].desN);
	}
}

void World::LookSouth()
{
	if (p1[0].pos == 0){
		printf("\n%s\n", E1[p1[0].pos].desN);
	}
}

void World::LookEast()
{
	if (p1[0].pos == 0){
		printf("\n%s\n", E1[p1[0].pos].desN);
	}
}

void World::LookWest()
{
	if (p1[0].pos == 0){
		printf("\n%s\n", E1[p1[0].pos].desN);
	}
}

int main()
{
	World scenary;

	scenary.CreateWorld();
	scenary.Exits();

	printf("Welcome");
	printf("\t%s\n", scenary.Room1[0].name);
	printf("\n%s\n", scenary.Room1[0].desc);

	while (1){
		scenary.Input();
	}

	system("pause");
	return 0;
}