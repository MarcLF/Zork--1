#include"Room.h"
#include"Player.h"
#include"Exits.h"
#include"Items.h"

class World
{
public:
	World();

	Room* Room1; //Room name
	Exit* E1; // Exits name
	Player* p1; //Player name
	Items* CashInv;//Cash you have in the inventory
	Items* CashLeft;//Cash left in the map

	void Cash();

	void CreateWorld();
	void Input();
	void Exits() const;
	void GoNorth();
	void GoSouth();
	void GoEast();
	void GoWest();
	void Look();
	void LookNorth();
	void LookSouth();
	void LookWest();
	void LookEast();
	void closeDoor();
	bool openDoor = false;
	bool openDoor2 = false;

	~World();
};
