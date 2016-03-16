#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "World.h"

#define EQUAL 0

World::World() //constructor
{
	Room1 = new Room[20];
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
	char* RoomNames[13] = { "Start", "Road", "Warehouse", "Sewers", "Purifying Plant", "Gym", "Frost House", "Maze", "Jail", "Old Mansion", "Road2", "Road3", "Road4" }; // Room Names
	for (int j = 0; j < 13; j++)
	{
		strcpy_s((Room1 + j)-> name, RoomNames[j]); //Here we are assignint each name a room
	}
	//Room descriptions
	char* RoomsInfo[] = 
	{
		"You see a big sign which says WELCOME to the COWARD CITY! Where all cowards come to hide from the world!/",
		"You find yourself in the middle of a dirty old road",
		"Warehouse DESCRIPTION //PLACEHOLDER//",
		"Sewers DESCRIPTION //PLACEHOLDER//",
		"Purifying Plant DESCRIPTION //PLACEHOLDER//",
		"Gym DESCRIPTION //PLACEHOLDER//",
		"Frost House DESCRIPTION //PLACEHOLDER//",
		"Maze DESCRIPTION //PLACEHOLDER//",
		"Jail DESCRIPTION //PLACEHOLDER//",
		"Old Mansion DESCRIPTION //PLACEHOLDER//",
		"You find yourself in the middle of a dirty old road",
		"You find yourself in the middle of a dirty old road",
		"You find yourself in the middle of a dirty old road"
	};
	for (int j = 0; j < 13; j++)
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
	gets_s(Input);

	if (strcmp("exit", Input) == EQUAL || strcmp("quit", Input) == EQUAL)//strcmp returns 0 if both strings are the same
	{
		exit(0);
	}
	else if (strcmp("help", Input) == EQUAL || strcmp("Help", Input) == EQUAL)
	{
		printf("Move options -> To go north: go north | go n | n\nTo go south: go south | go s | s\nTo go east:  go east  | go e | e\nTo go west:  go west  | go e | e\nIf you want to get information about the room you are in type 'Look'\n or if you prefer to know about the exits you can take type: look [direction] | look [n/s/e/w]\Type 'exit' or 'quit' to leave");
	}
	else if((strcmp("go north", Input) == EQUAL) || (strcmp("go n", Input) == EQUAL) || (strcmp("n", Input) == EQUAL))
	{
		GoNorth();
	}
	else if((strcmp("go south", Input) == EQUAL) || (strcmp("go s", Input) == EQUAL) || (strcmp("s", Input) == EQUAL))
	{
		GoSouth();
	}
	else if((strcmp("go east", Input) == EQUAL) || (strcmp("go e", Input) == EQUAL) || (strcmp("e", Input) == EQUAL))
	{
		GoEast();
	}
	else if((strcmp("go west", Input) == EQUAL) || (strcmp("go w", Input) == EQUAL) || (strcmp("w", Input) == EQUAL))
	{
		GoWest();
	}
	else if((strcmp("look north", Input) == EQUAL) || (strcmp("look n", Input) == EQUAL) || (strcmp("l n", Input) == EQUAL))
	{
		LookNorth();
	}
	else if((strcmp("look south", Input) == EQUAL) || (strcmp("look s", Input) == EQUAL) || (strcmp("l s", Input) == EQUAL))
	{
		LookSouth();
	}
	else if((strcmp("look east", Input) == EQUAL) || (strcmp("look e", Input) == EQUAL) || (strcmp("l e", Input) == EQUAL))
	{
		LookEast();
	}
	else if((strcmp("look west", Input) == EQUAL) || (strcmp("look w", Input) == EQUAL) || (strcmp("l w", Input) == EQUAL))
	{
		LookWest();
	}
	else
	{
		printf("I didn't understand your order, please try another one or type 'help' to see more info\n");
	}
}

void World::Exits() const //Here we are giving every exit a description
{
	//Start
	strcpy_s(E1[0].desN, "There is nothing relevant into that direction");

	strcpy_s(E1[0].desS, "There is nothing relevant into that direction");
	
	strcpy_s(E1[0].desE, "You see a small path which seems to lead into the town");

	strcpy_s(E1[0].desW, "There is nothing relevant into that direction");

	//Road
	strcpy_s(E1[1].desN, "A small building appears in front of you, it look like an old warehouse");

	strcpy_s(E1[1].desS, "The path continues");

	strcpy_s(E1[1].desE, "An old Mansion rises before you");

	strcpy_s(E1[1].desW, "That big sign you saw now seems to be smaller from the distance");

	//Warehouse
	strcpy_s(E1[2].desN, "There is nothing relevant into that direction");

	strcpy_s(E1[2].desS, "There is a door which leads back to the road");

	strcpy_s(E1[2].desE, "There is nothing relevant into that direction");

	strcpy_s(E1[2].desW, "There is nothing relevant into that direction");

	//Sewers
	strcpy_s(E1[3].desN, "There is nothing relevant into that direction");

	strcpy_s(E1[3].desS, "There is nothing relevant into that direction");

	strcpy_s(E1[3].desE, "There is a door which leads back to the road");

	strcpy_s(E1[3].desW, "There is nothing relevant into that direction");

	//Purifying plant
	strcpy_s(E1[4].desN, "There is a small rusty old door which seems to lead down into the sewers");

	strcpy_s(E1[4].desS, "There is nothing relevant into that direction");

	strcpy_s(E1[4].desE, "There is a big iron door which leads back to the road");

	strcpy_s(E1[4].desW, "There is nothing relevant into that direction");

	//Gym
	strcpy_s(E1[5].desN, "There is nothing relevant into that direction");

	strcpy_s(E1[5].desS, "There is nothing relevant into that direction");

	strcpy_s(E1[5].desW, "There is a door which leads back to the road");

	strcpy_s(E1[5].desE, "There is nothing relevant into that direction");

	//Frost house
	strcpy_s(E1[6].desN, "There is an icy door which leads back to the road");

	strcpy_s(E1[6].desS, "There is nothing relevant into that direction");

	strcpy_s(E1[6].desE, "There is nothing relevant into that direction");

	strcpy_s(E1[6].desW, "There is nothing relevant into that direction");

	//Maze
	strcpy_s(E1[7].desN, "There is nothing relevant into that direction");

	strcpy_s(E1[7].desS, "There is nothing relevant into that direction");

	strcpy_s(E1[7].desE, "There is a small path which leads back to the road");

	strcpy_s(E1[7].desW, "There is nothing relevant into that direction");

	//Jail
	strcpy_s(E1[8].desN, "There is nothing relevant into that direction");

	strcpy_s(E1[8].desS, "There is nothing relevant into that direction");

	strcpy_s(E1[8].desE, "There is nothing relevant into that direction");

	strcpy_s(E1[8].desW, "There is an armored door which leads back to the road");

	//Old mansion
	strcpy_s(E1[9].desN, "There is nothing relevant into that direction");

	strcpy_s(E1[9].desS, "There is nothing relevant into that direction");

	strcpy_s(E1[9].desE, "There is nothing relevant into that direction");

	strcpy_s(E1[9].desW, "You see a golden door which leads back to the road");

	//Road 2
	strcpy_s(E1[10].desN, "The path continues");

	strcpy_s(E1[10].desS, "There is an icy door");

	strcpy_s(E1[10].desE, "There is a door which leads to the gym");

	strcpy_s(E1[10].desW, "There is a door which leads to the sewers");
}

//Movement
void World::GoNorth()
{
	if (p1->posX == 1)
	{
		p1->posX = 2;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 4)
	{
		p1->posX = 3;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 6)
	{
		p1->posX = 12;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 12)
	{
		p1->posX = 11;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 11)
	{
		p1->posX = 10;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 10)
	{
		p1->posX = 1;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else
	{
		printf("You can't go to that direction!!!\n");
	}
}

void World::GoSouth()
{
	if (p1->posX == 3)
	{
		p1->posX = 4;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 1)
	{
		p1->posX = 10;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 10)
	{
		p1->posX = 11;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 11)
	{
		p1->posX = 12;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 12)
	{
		p1->posX = 6;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 2)
	{
		p1->posX = 1;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else
	{
		printf("You can't go to that direction!!!\n");
	}
}

void World::GoEast()
{
	if (p1->posX == 0)
	{
		p1->posX = 1;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 1)
	{
		p1->posX = 9;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 10)
	{
		p1->posX = 8;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 11)
	{
		p1->posX = 5;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 12)
	{
		p1->posX = 7;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 3)
	{
		p1->posX = 10;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 4)
	{
		p1->posX = 11;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else
	{
		printf("You can't go to that direction!!!\n");
	}
}

void World::GoWest()
{
	if (p1->posX == 10)
	{
		p1->posX = 3;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 9)
	{
		p1->posX = 1;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 8)
	{
		p1->posX = 10;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 7)
	{
		p1->posX = 12;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 5)
	{
		p1->posX = 11;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else
	{
		printf("You can't go to that direction!!!\n");
	}
}

void World::LookNorth()
{
	if (p1->posX == 1)
	{
		printf("\n%s\n", E1[p1->posX].desN);
	}
}

void World::LookSouth()
{
	if (p1->posX == 2)
	{
		printf("\n%s\n", E1[p1->posX].desS);
	}
}

void World::LookEast()
{
	if (p1->posX == 1)
	{
		printf("\n%s\n", E1[p1->posX].desE);
	}
	if (p1->posX == 2)
	{
		printf("\n%s\n", E1[p1->posX].desE);
	}
}

void World::LookWest()
{
	if (p1->posX == 0)
	{
		printf("\n%s\n", E1[p1->posX].desN);
	}
}

int main()
{
	World scenary;

	scenary.CreateWorld();
	scenary.Exits();

	printf("Welcome\n\n");
	printf("%s\n", scenary.Room1[0].name);
	printf("\n%s\n", scenary.Room1[0].desc);

	while (1)
	{
		scenary.Input();
	}

	system("pause");
	return 0;
}