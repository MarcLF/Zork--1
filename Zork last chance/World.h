#include"Room.h"
#include"Player.h"
#include"Exits.h"
#include"Items.h"

class World
{
public:

	World(); //Constructor

	Room* Room1; //Room name
	Exit* E1; // Exits name
	Player* p1; //Player name
	Items* CashInv;//Cash you have in the inventory
	Items* CashLeft;//Cash left in the map

	void CreateWorld();
	void Input(); //Read the input from the player
	void Exits() const;

	//Move functions
	void GoNorth();
	void GoSouth();
	void GoEast();
	void GoWest();

	//Look functions
	void Look();
	void LookNorth();
	void LookSouth();
	void LookWest();
	void LookEast();

	//Open/close door functions
	void closeDoor();
	bool openDoor = false;

	//Other actions
	bool BribeGuards = false;
	void Maze(); //When the player enters the room Inside the Maze it will automatically call this function

	~World(); //Destructor
};
