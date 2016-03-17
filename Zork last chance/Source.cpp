#include <iostream>
#include <stdio.h>
#include <string>
#include <conio.h>
#include "World.h"

int main()
{
	World scenary;

	scenary.CreateWorld();
	scenary.Exits();

	printf("--Welcome to Zork: Last Chance--\n\n");
	printf("%s\n", scenary.Room1[0].name);
	printf("\n%s\n", scenary.Room1[0].desc);

	while (1)
	{
		printf("\n>");
		scenary.Input();
	}

	system("pause");
	return 0;
}