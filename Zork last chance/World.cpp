#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "World.h"

#define EQUAL 0

//constructor
World::World()
{
	Room1 = new Room[20]; //Room1 = Rooms
	player = new Player; //player = Player
	Exit1 = new Exit[20]; //Exit1 = Exits
	CashLeft = new Items; //Cash left in the map
	CashInv = new Items; //Cash inventory
}

void World::CreateWorld()
{
	char* RoomNames[14] = { "Start", "Road", "Warehouse", "Sewers", "Purifying Plant", "Gym", "Frost House", "Maze", "Jail", "Old Mansion", "Road", "Road", "Road", "Inside the Maze"}; // Room Names
	for (int j = 0; j < 14; j++)
	{
		strcpy_s((Room1 + j)->name, RoomNames[j]); //Here we are assignint each name a room
	}

	//Room descriptions
	char* RoomsInfo[] =
	{
		"You see a big sign which says WELCOME to the COWARD CITY! Where all cowards come to hide from the rest of the world!",
		"You find yourself in the middle of a dirty old road.",
		"You are in a warehouse, in front of you there is a table with a few bills.",
		"This place stinks! I guess that's because this are the sewers.",
		"You are in a purifying plant.",
		"An old gym with a small boxing ring in the middle.",
		"If you were wondering why the main door was frost as hell now you know the reason, this house is a freezer!",
		"What first seemed like a garden it looks now like an immense maze. Becare where you go or you might get lost.",
		"It seems this building was a jail once, now its nothing but some old empty cells.",
		"After going across that ugly golden door, you find yourself in the living room of a dusty big old mansion.",
		"Moving a little forward you start discerning more buildings around you.",
		"You are still on the same road surrounded by some buildings, ah..this road seems endless.",
		"This is the end of the road, in front of you shows up a small building with a strange frost door.",
		"Suddenly you find yourself lost deep into the maze."
	};
	for (int j = 0; j < 14; j++)
	{
		strcpy_s((Room1 + j)->desc, RoomsInfo[j]); //Here we are assignint each description a room
	}
}

void World::Input()// Here we recieve the Input from the player and execute his/her order
{
	Items CashImg;//Cash image

	
	char Input[30];
	gets_s(Input);

	//Various
	if (strcmp("exit", Input) == EQUAL || strcmp("quit", Input) == EQUAL)//strcmp returns 0 if both strings are the same
	{
		exit(0);
	}
	else if (strcmp("help", Input) == EQUAL || strcmp("Help", Input) == EQUAL)
	{
		printf(R"EOF(Move options ->
		To go north: go north | north | go n | n
		To go south: go south | south | go s | s
		To go east:  go east  | east  | go e | e
		To go west:  go west  | west  | go e | e
		If you want to get information about the room you are in type 'Look' 
		There are other options like bribe a npc or to open / close a door
		or if you prefer to know about the exits you can take type: look [direction] or look [n/s/e/w]
		Type 'system cls' to clean the screen 'exit' or 'quit' to leave)EOF");
	}
	else if (strcmp("system cls", Input) == EQUAL)
	{
		system("cls");
	}

	//Movement inputs
	else if ((strcmp("go north", Input) == EQUAL) || (strcmp("north", Input) == EQUAL) || (strcmp("go n", Input) == EQUAL) || (strcmp("n", Input) == EQUAL))
	{
		GoNorth();
	}
	else if ((strcmp("go south", Input) == EQUAL) || (strcmp("south", Input) == EQUAL) || (strcmp("go s", Input) == EQUAL) || (strcmp("s", Input) == EQUAL))
	{
		GoSouth();
	}
	else if ((strcmp("go east", Input) == EQUAL) || (strcmp("east", Input) == EQUAL) || (strcmp("go e", Input) == EQUAL) || (strcmp("e", Input) == EQUAL))
	{
		GoEast();
	}
	else if ((strcmp("go west", Input) == EQUAL) || (strcmp("west", Input) == EQUAL) || (strcmp("go w", Input) == EQUAL) || (strcmp("w", Input) == EQUAL))
	{
		GoWest();
	}
	else if ((strcmp("go", Input) == EQUAL))
	{
		printf("go where?\n\n>");
		gets_s(Input);

		if ((strcmp("north", Input) == EQUAL))
		{
			GoNorth();
		}
		else if ((strcmp("south", Input) == EQUAL))
		{
			GoSouth();
		}
		else if ((strcmp("east", Input) == EQUAL))
		{
			GoEast();
		}
		else if ((strcmp("west", Input) == EQUAL))
		{
			GoWest();
		}
	}

	//Look inputs
	else if ((strcmp("look", Input) == EQUAL))
	{
		Look();
	}
	else if ((strcmp("look north", Input) == EQUAL) || (strcmp("look n", Input) == EQUAL) || (strcmp("l n", Input) == EQUAL))
	{
		LookNorth();
	}
	else if ((strcmp("look south", Input) == EQUAL) || (strcmp("look s", Input) == EQUAL) || (strcmp("l s", Input) == EQUAL))
	{
		LookSouth();
	}
	else if ((strcmp("look east", Input) == EQUAL) || (strcmp("look e", Input) == EQUAL) || (strcmp("l e", Input) == EQUAL))
	{
		LookEast();
	}
	else if ((strcmp("look west", Input) == EQUAL) || (strcmp("look w", Input) == EQUAL) || (strcmp("l w", Input) == EQUAL))
	{
		LookWest();
	}

	//Open / Close door inputs
	else if ((strcmp("open door", Input) == EQUAL) || (strcmp("open d", Input) == EQUAL) || (strcmp("o d", Input) == EQUAL))
	{
		if (player->posX == 1 || player->posX == 2)
		{
			printf("Door is open\n");
			openDoor = true;
		}
		else
		{
			printf("There is no door to open\n");
		}
	}
	else if ((strcmp("close door", Input) == EQUAL) || (strcmp("close d", Input) == EQUAL) || (strcmp("c d", Input) == EQUAL))
	{
		if (player->posX == 1 && openDoor == true)
		{
			printf("You close the door\n");
			openDoor = false;
		}
		else if (player->posX == 2 && openDoor == true)
		{
			printf("You close the door\n");
			openDoor = false;
		}
	}

	//Take / pick up inputs
	else if ((strcmp("take cash", Input) == EQUAL) || (strcmp("pick up cash", Input) == EQUAL))
	{
		if ((player->posX == 2) && CashLeft->Cash2 == 1)
		{
			CashImg.CashImage();
			CashInv->CashX = 1;
			CashLeft->Cash2 = 0;
		}
		else
		{
			printf("There is no cash to take\n");
		}
	}
	else if ((strcmp("take", Input) == EQUAL) || (strcmp("pick up", Input) == EQUAL))
	{
		printf("What item?\n\n>");
		gets_s(Input);
		if ((strcmp("cash", Input) == EQUAL) && player->posX == 2 && (CashInv->CashX == 0 && CashLeft->Cash2 == 1))
		{
			CashImg.CashImage();
			CashInv->CashX = 1;
			CashLeft->Cash2 = 0;
		}
		else if ((strcmp("cash", Input) == EQUAL) && player->posX != 2 && CashLeft->Cash2 == 0)
		{
			printf("There is no cash to take");
		}
		else
		{
			printf("I didn't understand your order, please try another one or type 'help'\nto see more info\n");
		}
	}

	//Actions inputs
	else if ((strcmp("bribe guards", Input) == EQUAL))
	{
		if (CashInv->CashX == 1 && CashLeft->Cash2 == 0)
		{
			CashInv->CashX = 0;
			printf("Both guards look at each other and after a few seconds take the money and left the entrance\n");
			BribeGuards = true;
		}
		else
		{
			printf("You have nothing to bribe them\n");
		}
	}

	//Error message
	else
	{
		printf("I didn't understand your order, please try another one or type 'help'\nto see more info\n");
	}
}

//destructor
World::~World()
{
	delete[] Room1;
	delete player;
	delete[]Exit1;
	delete CashLeft;
	delete CashInv;
}