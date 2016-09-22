#include "Pathfinder.h"


Pathfinder::Pathfinder()
{
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			for (int k = 0; k < PAGES; ++k)
			{
				maze[i][j][k] = 1;
			}
		}
	}
}

Pathfinder::~Pathfinder()
{
}

//Part 1-----------------------------------------------------------------------------------
/*
* getMaze
*
* Returns a string representation of the current maze. Returns a maze of all 1s if no maze
* has yet been generated or imported.
*
* A valid string representation of a maze consists only of 125 1s and 0s (each separated
* by spaces) arranged in five 5x5 grids (each separated by newlines). A valid maze must
* also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
*
* Cell (0, 0, 0) is represented by the first number in the string representation of the
* maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
* number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
* sixth number. Increasing in z means moving downward to a new grid, meaning cell
* (0, 0, 1) is the twenty-sixth number. Cell (4, 4, 4) is represented by the last number.
*
* Returns:		string
*				A single string representing the current maze
*/
string Pathfinder::getMaze()
{
	stringstream output;

	for (int i = 0; i < ROWS; ++i)
	{
		if (i != 0)
		{
			output << endl;
		}
		for (int j = 0; j < COL; ++j)
		{
			output << endl;
			for (int k = 0; k < PAGES; ++k)
			{
				output << maze[i][j][k] << " ";

			}
		}
	}
	return output.str();
				
}

/*
* createRandomMaze
*
* Generates a random maze and stores it as the current maze.
*
* The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
* in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
* solvable or unsolvable, and this method should be able to produce both kinds of mazes.
*/
void Pathfinder::createRandomMaze()
{
	for (int i = 0; i < ROWS; ++i)
	{
		for (int j = 0; j < COL; ++j)
		{
			for (int k = 0; k < PAGES; ++k)
			{
				maze[i][j][k] = rand() % 2;
				if (i == 0 && j == 0 && k == 0)
				{
					maze[i][j][k] = 1;
				}
				else if (i == 4 && j == 4 && k == 4)
				{
					maze[i][j][k] = 1;
				}
			}
		}
	}
}
//-----------------------------------------------------------------------------------------

//Part 2-----------------------------------------------------------------------------------
/*
* importMaze
*
* Reads in a maze from a file with the given file name and stores it as the current maze.
* Does nothing if the file does not exist or if the file's data does not represent a valid
* maze.
*
* The file's contents must be of the format described above to be considered valid.
*
* Parameter:	file_name
*				The name of the file containing a maze
* Returns:		bool
*				True if the maze is imported correctly  false otherwise
*/
bool Pathfinder::importMaze(string file_name)
{
	ifstream input;
	ifstream test;
	test.open(file_name.c_str());
	string line;
	string testinput;
	int cnt = 0;
	if (!test.fail())
	{
		while (test >> testinput)
		{
			cnt++;
			if (cnt == 1)
			{
				if (testinput != "1")
				{
					return false;
				}	
			}
			for (int i = 0; i < testinput.size(); i++)
			{
				if (!isdigit(testinput[i]))
				{
					return false;
				}
			}
			if (testinput != "1" && testinput != "0")
			{
				return false;
			}
			
		}
		if (cnt != 125)
		{
			return false;
		}
		if (testinput != "1" && cnt == 125)
		{
			return false;
		}
	}
	else
	{
		test.close();
		return false;
	}
	test.close();
	input.open(file_name.c_str());
		
			for (int i = 0; i < ROWS; ++i)
				for (int j = 0; j < COL; ++j)
					for (int k = 0; k < PAGES; ++k)
					{
						input >> line;
						maze[i][j][k] = stoi(line);
					}
						
		return true;
}
//-----------------------------------------------------------------------------------------

//Part 3-----------------------------------------------------------------------------------
/*
* solveMaze
*
* Attempts to solve the current maze and returns a solution if one is found.
*
* A solution to a maze is a list of coordinates for the path from the entrance to the exit
* (or an empty vector if no solution is found). This list cannot contain duplicates, and
* any two consecutive coordinates in the list can only differ by 1 for only one
* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
* where x, y, and z are the integer coordinates of a cell.
*
* Understand that most mazes will contain multiple solutions
*
* Returns:		vector<string>
*				A solution to the current maze, or an empty vector if none exists
*/
vector<string> Pathfinder::solveMaze()
{
		/** Wrapper function. */
	//clear vector
	output.clear();
	//copy maze and then 
	for (int i = 0; i < ROWS; ++i)
		for (int j = 0; j < COL; ++j)
			for (int k = 0; k < PAGES; ++k)
			{
				mazecopy[i][j][k] = maze[i][j][k];
			}
	//call find maze path
	bool found = find_maze_path(0,0,0);
	//reverse vector in algorigthm library
	reverse(output.begin(), output.end());
	//return vector or not
	if (found)
	{
		return output;
	}
	output.clear();
	return output;
		
}

bool Pathfinder::find_maze_path(int page, int col, int row)
{
	
	if (row < 0 || col < 0 || page < 0 || row > 4 || col > 4 || page > 4)
		return false;      // Cell is out of bounds.
	else if (mazecopy[page][col][row] == 0)
	{
		return false;      // Cell is on barrier or dead end.
	}
	else if (mazecopy[page][col][row] == 2)
	{
		return false;
	}
	else if (row == ROWS - 1 && col == COL - 1 && page == PAGES - 1)
	{
		stringstream ss;
		ss << "(" << page << ", " << row << ", " << col << ")";
		output.push_back(ss.str());         // Cell is on path
		return true;               // and is maze exit.
	}
	else
	{
		mazecopy[page][col][row] = 2;
		if (find_maze_path(page, col + 1, row) || find_maze_path(page, col - 1, row) || find_maze_path(page, col, row - 1)
			|| find_maze_path(page + 1, col, row) || find_maze_path(page - 1, col, row) || find_maze_path(page, col, row + 1))
		{
			stringstream ss;
			ss << "(" << page << ", " << row << ", " << col << ")";
			output.push_back(ss.str());
			return true;
		}
	}
}