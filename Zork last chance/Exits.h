enum directions { n, s, e, w }; //north south east and west

class Exit
{
public:
	Exit();
	char desN[200], desS[200], desE[200], desW[200];
	int lockedDoor = 1;
	~Exit();
};
