#include"Room.h"
#include"Player.h"
#include"Exits.h"

class World
{
public:
	World();

	Room* Room1 = nullptr;
	Exit* E1 = nullptr;
	Player* p1 = nullptr;

	void CreateWorld();
	void Input();
	void Exits() const;
	void GoNorth();
	void GoSouth();
	void GoEast();
	void GoWest();
	void LookNorth();
	void LookSouth();
	void LookWest();
	void LookEast();
	void OpenDoor();
	void CloseDoor();

	~World();
};
