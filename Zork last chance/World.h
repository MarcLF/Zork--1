#include"Room.h"
#include"Player.h"
#include"Exits.h"
#include"Items.h"
#include"Vector.h"
#include"String.h"

class World
{
public:

	World(); //Constructor

	Room* Room1 = nullptr; //Room name
	Exit* Exit1 = nullptr; // Exits name
	Player* player = nullptr; //Player name
	Items* CashInv = nullptr;//Cash you have in the inventory
	Items* CashLeft = nullptr;//Cash left in the map

	void CreateWorld();
	void Input(); //Read the input from the player
	void GetInput(MyString&input);
	void Exits() const;

	//Move functions
	void GoNorth();
	void GoSouth();
	void GoEast();
	void GoWest();

	//Look functions
	void Look() const;
	void LookNorth() const;
	void LookSouth() const;
	void LookWest() const;
	void LookEast() const;

	//Open/close door functions
	void closeDoor();
	bool openDoor = false;

	//Other actions
	bool BribeGuards = false;
	void Maze(); //When the player enters the room Inside the Maze it will automatically call this function

	~World(); //Destructor
};
