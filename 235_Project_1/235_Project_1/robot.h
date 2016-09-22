#pragma once
#include "fighter.h"
#include <math.h>
class robot :
	public fighter
{
private:
	int energy;
	int currentenergy;
public:
	robot(string name, int maxhitpoints, int strength, int speed, int magic);
	~robot();
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
};

