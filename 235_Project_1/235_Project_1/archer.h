#pragma once
#include "fighter.h"
class archer :
	public fighter
{
private:
	int currentspeed;
public:
	archer(string name, int maxhitpoints, int strength, int speed, int magic);
	~archer();
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
};
