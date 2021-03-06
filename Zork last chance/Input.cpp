#include <iostream>
#include "String.h"
#include "World.h"

void World::Input(MyString&input)// Here we recieve the Input from the player and execute his/her order
{
	MyString input2;
	char Input2[30];

	//Various
	if (input == "exit" || input == "quit")
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
		To take/drop items type take or drop and then the name of the item you want to take/drop
		If you want to put an item into another one first type the name of the item you want to store
		then type the name of the container
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

		if (input2 == "north")
		{
			GoNorth();
		}
		else if (input2 == "south")
		{
			GoSouth();
		}
		else if (input2 == "east")
		{
			GoEast();
		}
		else if (input2 == "west")
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
		if ((player->Pos == (Room*)entity[1] || player->Pos == (Room*)entity[2]) && ((Item*)entity[44])->taken == true)
		{
			printf("\nDoor is open\n");
			((Exit*)entity[8])->door = false;
			((Exit*)entity[9])->door = false;
		}
		else if ((player->Pos == (Room*)entity[1] || player->Pos == (Room*)entity[2]) && ((Item*)entity[44])->taken == false)
		{
			printf("You have nothing to open this door\n");
		}
		else
		{
			printf("There is no door to open\n");
		}
	}
	else if (input == "close door")
	{
		if ((player->Pos == (Room*)entity[1] || player->Pos == (Room*)entity[2]) && (((Exit*)entity[2])->door == false || ((Exit*)entity[3])->door == false))
		{
			printf("\nYou close the door\n");
			((Exit*)entity[8])->door = true;
			((Exit*)entity[9])->door = true;
		}
		else 
		{
			printf("\nThere is no door to be closed\n");
		}
	}

	//Take / pick up /objects
	else if (input == "take")
	{
		printf("What item?\n\n>");
		gets_s(Input2);
		input2 = Input2;

		for (int i = 0; i < NUM_ITEMS; i++)
		{
			if (((Item*)entity[i])->taken == false && ((Item*)entity[i])->name == input2 && player->Pos == ((Item*)entity[i])->place)
			{
				TakeObject(input2);
				return;
			}
			else if (((Item*)entity[i])->name == input2 && player->Pos != ((Item*)entity[i])->place)
			{
				printf("\nThere is no %s to take. \n", input2);
				return;
			}
		}
		printf("\n%s doesn't exist in this world. \n", input2);
	}

	//Drop objects
	else if (input == "drop")
	{
		printf("What item?\n\n>");
		gets_s(Input2);
		input2 = Input2;

		for (int i = 0; i < NUM_ITEMS; i++)
		{
			if (((Item*)entity[i])->taken == true && ((Item*)entity[i])->name == input2)
			{
				DropObject(input2);
				return;
			}
			else if (((Item*)entity[i])->name == input2 && ((Item*)entity[i])->taken == false)
			{
				printf("\nThere is no %s to drop \n", input2);
				return;
			}
		}
		printf("\n%s doesn't exist in this world. \n", input2);
	}

	//Put an object inside another one
	else if (input == "put")
	{
		printf("What item?\n\n>");
		gets_s(Input2);
		input2 = Input2;

		for (int i = 0; i < NUM_ITEMS; i++)
		{
			if (((Item*)entity[i])->taken == true && ((Item*)entity[i])->name == input2)
			{
				PutObject(input2);
				return;
			}
		}
		printf("\n%s doesn't exist in this world. \n", input2);
	}

	//Actions inputs
	else if (input == "bribe guards")
	{
		if (((Item*)entity[0])->taken == true)
		{
			printf("Both guards look at each other and after a few seconds take the money and left the entrance\n");
			((Exit*)entity[19])->door = false;
		}
		else if (player->Pos != (Room*)entity[12])
		{
			printf("What guards?");
		}
		else
		{
			printf("You have nothing to bribe them\n");
		}
	}
	else if (input == "inventory")
	{
		Inventory();
	}

	//Error message
	else
	{
		printf("I didn't understand your order, please try another one or type 'help'\nto see more info\n");
	}
}
