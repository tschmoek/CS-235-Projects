#include "arena.h"


arena::arena()
{
}


arena::~arena()
{
}

int arena::find(string name)
{
	for(int i = 0; i < Fighters.size(); i++)
	{
		if(name == Fighters[i]->getName())
		{
			return i;
		}
	}
	return 0;

}

bool arena::addFighter(string info)
{
	string name;
	string type;
	int maxHP;
	int strength;
	int speed;
	int magic;
	int namefind;

	stringstream ss;
	ss << info;
	ss >> name >> type >> maxHP >> strength >> speed >> magic;
	namefind = find(name);
	if(maxHP > 0)
	{
		if(namefind == true)
		{
			if (type == "R")
			{
				robot* add = new robot(name, maxHP, strength, speed, magic);// creates new
				Fighters.push_back(add);
				return true;
			}

			else if (type == "A")
			{
				archer* add = new archer(name, maxHP, strength, speed, magic);// creates new
				Fighters.push_back(add);
				return true;
			}

			else if (type == "C")
			{
				cleric* add = new cleric(name, maxHP, strength, speed, magic);// creates new
				Fighters.push_back(add);
				return true;
			}
		}
	}
	return false;

}
bool arena::removeFighter(string name)
{
	int namefind;
	namefind = find(name);
	if(namefind != 0)
	{
			Fighters.erase(Fighters.begin() + namefind);
			return true;
	}
	return false;
}
FighterInterface* arena::getFighter(string name)
{
	int namefind = find(name);
	if (namefind > 0)
	{
		return Fighters[namefind];
	}
	
}
int arena::getSize()
{
	return Fighters.size();
}
/*
ss.fail();
stringstream put info into the string
call a find function to see if the name
check for bad data

*/
