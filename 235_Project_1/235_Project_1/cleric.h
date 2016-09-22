#pragma once
#include "fighter.h"
class cleric :
	public fighter
{
private:
	int mana;
	int currentmana;
public:
	cleric(string name, int maxhitpoints, int strength, int speed, int magic);
	~cleric();
	int getDamage();
	void reset();
	void regenerate();
	bool useAbility();
};

