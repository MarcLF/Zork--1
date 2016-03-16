enum directions { n, s, e, w }; //north south east and west

class Exit
{
public:
	Exit();
	Exit(char name, char desN, char desS, char desE, char desW);
	int lockedDoor = 1;
	~Exit();
};
