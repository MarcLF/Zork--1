#include"Room.h"
#include"Player.h"
#include"Exits.h"

class World
{
public:
	World();

	Room* Room1;
	Exit* E1;
	Player* p1;

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

	~World();
};
