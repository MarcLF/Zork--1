#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "World.h"

#define EQUAL 0

World::World() //constructor
{
	Room1 = new Room[20]; //Room1 = Rooms
	p1 = new Player; //p1 = Player
	E1 = new Exit[20]; //E1 = Exits
	CashLeft = new Items2; //Cash left in the map
	CashInv = new Items; //Cash inventory
}

//Items
void World::Cash()
{
	printf("You take some cash\n");
	printf(R"EOF(
||====================================================================||
||//$\\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\//$\\||
||(100)==================| RESERVE BANK OF INDIA|================(100)||
||\\$//        ~         '------========--------'                \\$//||
||<< /        /$\              // ____ \\                         \ >>||
||>>|        //L\\            // ///..) \\              XXXX       |<<||
||<<|        \\ //           || <||  >\  ||                        |>>||
||>>|         \$/            ||  $$ --/  ||          XXXXXXXXX     |<<||
||<<|     Free to Use        *\\  |\_/  //*                        |>>||
||>>|                         *\\/___\_//*                         |<<||
||<<\      Rating: E     _____/ M GANDHI \________    XX XXXXX     />>||
||//$\                 ~|    REPUBLIC OF INDIA   |~               /$\\||
||(100)===================   ONE HUNDRED RUPEES =================(100)||
||\\$//\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\/\\$//||
||====================================================================||
)EOF");
}

void World::CreateWorld()
{
	char* RoomNames[13] = { "Start", "Road", "Warehouse", "Sewers", "Purifying Plant", "Gym", "Frost House", "Maze", "Jail", "Old Mansion", "Road", "Road", "Road" }; // Room Names
	for (int j = 0; j < 13; j++)
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
		"What first seemed like a garden it looks now like an immense maze.",
		"It seems this building was a jail once, now its nothing but some old empty cells.",
		"After going across that ugly golden door, you find yourself in the living room of a dusty big old mansion.",
		"Moving a little forward you start discerning more buildings around you.",
		"You are still on the same road surrounded by some buildings, ah..this road seems endless.",
		"This is the end of the road, in front of you shows up a small building with a strange frost door."
	};
	for (int j = 0; j < 13; j++)
	{
		strcpy_s((Room1 + j)->desc, RoomsInfo[j]); //Here we are assignint each description a room
	}
}

//destructors
World::~World()
{
	delete[] Room1;
	delete p1;
	delete[]E1;
}

void World::Input()// Here we recieve the Input from the player and execute his/her order
{
	char Input[15];
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
		if (p1->posX == 1 || p1->posX == 2)
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
		if (p1->posX == 1 && openDoor == true)
		{
			printf("You close the door\n");
			openDoor = false;
		}
		else if (p1->posX == 2 && openDoor == true)
		{
			printf("You close the door\n");
			openDoor = false;
		}
	}

	//Take / pick up inputs
	else if ((strcmp("take cash", Input) == EQUAL) || (strcmp("pick up cash", Input) == EQUAL))
	{
		if ((p1->posX == 2) && CashLeft->Cash2 == 1)
		{
			Cash();
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
		if ((strcmp("cash", Input) == EQUAL) && p1->posX == 2 && (CashInv->CashX == 0 && CashLeft->Cash2 == 1))
		{
			Cash();
			CashInv->CashX = 1;
			CashLeft->Cash2 = 0;
		}
		else if ((strcmp("cash", Input) == EQUAL) && p1->posX != 2 && CashLeft->Cash2 == 0)
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
			openDoor2 = true;
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

	strcpy_s(E1[10].desS, "The path continues");

	strcpy_s(E1[10].desE, "There is a locked door which leads to the jail");

	strcpy_s(E1[10].desW, "There is a door which leads to the sewers");

	//Road 3
	strcpy_s(E1[11].desN, "The path continues");

	strcpy_s(E1[11].desS, "The path continues");

	strcpy_s(E1[11].desE, "There is a door which leads to the gym");

	strcpy_s(E1[11].desW, "There is a door which leads to the purifying plant");

	//Road 4
	strcpy_s(E1[12].desN, "The path continues");

	strcpy_s(E1[12].desS, "There is an icy door");

	strcpy_s(E1[12].desE, "You see the entrance of a maze");

	strcpy_s(E1[12].desW, "There is nothing relevant into that direction");
}

//Movement
void World::GoNorth()
{
	if (openDoor == true && p1->posX == 1)
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
	else if (p1->posX == 1 && openDoor == false)
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
	else if (p1->posX == 2 && openDoor == true)
	{
		p1->posX = 1;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 2 && openDoor == false)
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
	else if (p1->posX == 11 && openDoor2 == true) 
	{
		p1->posX = 4;
		puts(Room1[p1->posX].name);
		puts(Room1[p1->posX].desc);
	}
	else if (p1->posX == 11 && openDoor2 == false)
	{
		printf("There are two guards blocking the entrance\n");
	}
	else
	{
		printf("You can't go to that direction!!!\n");
	}
}

void World::Look()
{
	puts(Room1[p1->posX].name);
	puts(Room1[p1->posX].desc);
}

void World::LookNorth()
{
	for (int j = 0; j < 13; j++)
	{
		if (p1->posX == j)
		{
			puts(E1[p1->posX].desN);
		}
	}
}

void World::LookSouth()
{
	for (int j = 0; j < 13; j++)
	{
		if (p1->posX == j)
		{
			puts(E1[p1->posX].desS);
		}
	}
}

void World::LookEast()
{
	for (int j = 0; j < 13; j++)
	{
		if (p1->posX == j)
		{
			puts(E1[p1->posX].desE);
		}
	}
}

void World::LookWest()
{
	for (int j = 0; j < 13; j++)
	{
		if (p1->posX == j)
		{
			puts(E1[p1->posX].desW);
		}
	}
}
