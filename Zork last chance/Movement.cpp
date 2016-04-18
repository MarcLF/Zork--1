#include <iostream>
#include "World.h"

//Movement functions
void World::GoNorth()
{
	if (openDoor == true && player->posX == 1) //Road to Warehouse
	{
		player->posX = 2;
		if (CashLeft->Cash2 == 1)
		{
			printf("%s", Room1[player->posX]->name);
			printf("%s", Room1[player->posX]->desc);
		}
		else
		{
			printf("%s", Room1[player->posX]->name);
			printf("You are in a warehouse, in front of you there the table where you took the money");
		}
	}
	else if (player->posX == 4) //Purifying plant to Sewers
	{
		player->posX = 3;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 6) //Frost house to Road 4
	{
		player->posX = 12;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 12) //Road 4 to Road 3
	{
		player->posX = 11;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 11) //Road 3 to Road 2
	{
		player->posX = 10;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 10) //Road 2 to Road
	{
		player->posX = 1;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 7) //Maze to Inside the Maze
	{
		player->posX = 13;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
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
	if (player->posX == 3) //Sewers to Purifying plant
	{
		player->posX = 4;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 1) //Road to Road 2
	{
		player->posX = 10;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 10) //Road 2 to Road 3
	{
		player->posX = 11;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 11) //Road 3 to Road 4
	{
		player->posX = 12;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 12) //Road 4 to Frost house
	{
		player->posX = 6;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 7) //Maze to Inside the Maze
	{
		player->posX = 13;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
	}
	else if (player->posX == 2 && openDoor == true)//If the door is open
	{
		player->posX = 1;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 2 && openDoor == false) //If the door is closed
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
	if (player->posX == 0) //Start to Road
	{
		player->posX = 1;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 1) //Road to Mansion
	{
		player->posX = 9;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 10) //Road 2 to jail
	{
		player->posX = 8;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 11) //Road 3 to Gym
	{
		player->posX = 5;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 12) //Road 4 to Maze
	{
		player->posX = 7;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 3) //Sewers to Road 2
	{
		player->posX = 10;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 4) //Purifying Plant to Road 3
	{
		player->posX = 11;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 7) //Maze to Inside the Maze
	{
		player->posX = 13;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
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
	if (player->posX == 10) //Road 2 to Sewers
	{
		player->posX = 3;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 1) //Road to Start
	{
		player->posX = 0;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 9) //Old Mansion to Road
	{
		player->posX = 1;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 8) //Jail to Road 2
	{
		player->posX = 10;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 5) //Gym to Road 3
	{
		player->posX = 11;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 7) //Maze to Inside the Maze
	{
		player->posX = 13;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
	}
	else if (player->posX == 13) //Maze Loop
	{
		printf("You are still in the Maze\n");
		Maze();
	}
	else if (player->posX == 11 && BribeGuards == true) // If you have bribed the guards
	{
		player->posX = 4;
		printf("%s", Room1[player->posX]->name);
		printf("%s", Room1[player->posX]->desc);
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