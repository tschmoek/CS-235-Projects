#pragma once
#include "ArenaInterface.h"
#include<string>
#include<vector>
#include"fighter.h"
#include"archer.h"
#include"cleric.h"
#include"robot.h"
#include <sstream>
class arena :
	public ArenaInterface
{
private:
	vector<fighter*> Fighters;
public:
	arena();
	~arena();
	bool addFighter(string info);
	bool removeFighter(string name);
	FighterInterface* getFighter(string name);
	int getSize();
	int find(string name);
};
