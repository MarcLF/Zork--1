enum directions { n, s, e, w }; //north south east and west

class Exit
{
public:
	Exit();
	char name[200];
	char desN[200];
	char desS[200];
	char desE[200];
	char desW[200];
	int lockedDoor = 1;
	~Exit();
};
