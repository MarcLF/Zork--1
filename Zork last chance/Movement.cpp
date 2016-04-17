#include <iostream>
#include "World.h"

//Movement functions
void World::GoNorth()
{
	if (openDoor == true && player->posX == 1)
	{
		player->posX = 2;
		if (CashLeft->Cash2 == 1)
		{
			puts(Room1[player->posX].name);
			puts(Room1[player->posX].desc);
		}
		else
		{
			puts(Room1[player->posX].name);
			printf("You are in a warehouse, in front of you there the table where you took the money");
		}
	}
	else if (player->posX == 4)
	{
		player->posX = 3;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 6)
	{
		player->posX = 12;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 12)
	{
		player->posX = 11;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 11)
	{
		player->posX = 10;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 10)
	{
		player->posX = 1;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 7) //Maze
	{
		player->posX = 13;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
	}
	else if (player->posX == 1 && openDoor == false)// If the door is closed
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
	if (player->posX == 3)
	{
		player->posX = 4;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 1)
	{
		player->posX = 10;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 10)
	{
		player->posX = 11;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 11)
	{
		player->posX = 12;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 12)
	{
		player->posX = 6;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 7) //Maze
	{
		player->posX = 13;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
	}
	else if (player->posX == 2 && openDoor == true)// If the door is open
	{
		player->posX = 1;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 2 && openDoor == false)// If the door is closed
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
	if (player->posX == 0)
	{
		player->posX = 1;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 1)
	{
		player->posX = 9;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 10)
	{
		player->posX = 8;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 11)
	{
		player->posX = 5;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 12)
	{
		player->posX = 7;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 3)
	{
		player->posX = 10;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 4)
	{
		player->posX = 11;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 7) //Maze
	{
		player->posX = 13;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 13) //Maze Loop
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
	if (player->posX == 10)
	{
		player->posX = 3;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 1)
	{
		player->posX = 0;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 9)
	{
		player->posX = 1;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 8)
	{
		player->posX = 10;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 5)
	{
		player->posX = 11;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 7) //Maze
	{
		player->posX = 13;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
	}
	else if (player->posX == 11 && BribeGuards == true) // If you have bribed the guards
	{
		player->posX = 4;
		puts(Room1[player->posX].name);
		puts(Room1[player->posX].desc);
	}
	else if (player->posX == 11 && BribeGuards == false) //If you don't have bribed the guards
	{
		printf("There are two guards blocking the entrance\n");
	}
	else
	{
		printf("You can't go to that direction!!!\n");
	}
}