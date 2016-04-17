#include <iostream>
#include "String.h"
#include "World.h"

void World::GetInput(MyString&input)// Here we recieve the Input from the player and execute his/her order
{
	Items CashImg;//Cash image
	MyString input2;

	char Input2[30];

	//Various
	if (input == "exit")//strcmp returns 0 if both strings are the same
	{
		exit(0);
	}
	else if (input == "help")
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
	else if (input == "system cls")
	{
		system("cls");
	}

	//Movement inputs
	else if (input == "go north" || input == "north" || input == "go n" || input == "n")
	{
		GoNorth();
	}
	else if (input == "go south" || input == "south" || input == "go s" || input == "s")
	{
		GoSouth();
	}
	else if (input == "go east" || input == "east" || input == "go e" || input == "e")
	{
		GoEast();
	}
	else if (input == "go west" || input == "west" || input == "go w" || input == "w")
	{
		GoWest();
	}
	else if (input == "go")
	{
		printf("go where?\n\n>");
		gets_s(Input2);
		input2 = Input2;

		if (input == "north")
		{
			GoNorth();
		}
		else if (input == "south")
		{
			GoSouth();
		}
		else if (input == "east")
		{
			GoEast();
		}
		else if (input == "west")
		{
			GoWest();
		}
	}

	//Look inputs
	else if (input == "look")
	{
		Look();
	}
	else if (input == "look north")
	{
		LookNorth();
	}
	else if (input == "look south")
	{
		LookSouth();
	}
	else if (input == "look east")
	{
		LookEast();
	}
	else if (input == "look west")
	{
		LookWest();
	}

	//Open / Close door inputs
	else if (input == "open door")
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
	else if (input == "close door")
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
	else if (input == "take cash")
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
	else if (input == "take")
	{
		printf("What item?\n\n>");
		gets_s(Input2);
		input2 = Input2;
		if (input == "cash" && player->posX == 2 && (CashInv->CashX == 0 && CashLeft->Cash2 == 1))
		{
			CashImg.CashImage();
			CashInv->CashX = 1;
			CashLeft->Cash2 = 0;
		}
		else if (input == "cash" && player->posX != 2 && CashLeft->Cash2 == 0)
		{
			printf("There is no cash to take");
		}
		else
		{
			printf("I didn't understand your order, please try another one or type 'help'\nto see more info\n");
		}
	}

	//Actions inputs
	else if (input == "bribe guards")
	{
		if (CashInv->CashX == 1 && CashLeft->Cash2 == 0)
		{
			CashInv->CashX = 0;
			printf("Both guards look at each other and after a few seconds take the money and left the entrance\n");
			BribeGuards = true;
		}
		else if (player->posX != 13)
		{
			printf("What guards?");
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