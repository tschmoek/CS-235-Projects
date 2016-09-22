#pragma once
#include "PathfinderInterface.h"
#include <fstream>
#include <sstream>
#include <math.h>
#include <algorithm>
const int ROWS = 5;
const int COL = 5;
const int PAGES = 5;
class Pathfinder : 
	public PathfinderInterface
{
private:
	int maze[ROWS][COL][PAGES];
	vector<string> output;
	int mazecopy[ROWS][COL][PAGES];
public:
	Pathfinder();
	~Pathfinder();
	bool find_maze_path(int page, int col, int row);
	string getMaze();
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();
		
};

