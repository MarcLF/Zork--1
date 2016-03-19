#include <iostream>
#include "World.h"

//Movement functions
void World::GoNorth()
{
	if (openDoor == true && p1->posX == 1)
	{
		p1->posX = 2;
		if (CashLeft->Cash2 == 1)
		{
			puts(Room1[p1->posX].name);
			puts(Room1[p1->posX].desc);
		}
		else
		{
			puts(Room1[p1->posX].name);
			printf("You are in a warehouse, in front of you there the table where you took the money");
		}
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
	else if (p1->posX == 7) //Maze
	{
		p1->posX = 13;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
	}
	else if (p1->posX == 1 && openDoor == false)// If the door is closed
	{
		printf("Door is closed\n");
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
	else if (p1->posX == 7) //Maze
	{
		p1->posX = 13;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
	}
	else if (p1->posX == 2 && openDoor == true)// If the door is open
	{
		p1->posX = 1;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 2 && openDoor == false)// If the door is closed
	{
		printf("Door is closed\n");
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
	else if (p1->posX == 7) //Maze
	{
		p1->posX = 13;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
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
	else if (p1->posX == 1)
	{
		p1->posX = 0;
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
	else if (p1->posX == 5)
	{
		p1->posX = 11;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 7) //Maze
	{
		p1->posX = 13;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
	}
	else if (p1->posX == 11 && BribeGuards == true) // If you have bribed the guards
	{
		p1->posX = 4;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 11 && BribeGuards == false) //If you don't have bribed the guards
	{
		printf("There are two guards blocking the entrance\n");
	}
	else
	{
		printf("You can't go to that direction!!!\n");
	}
}