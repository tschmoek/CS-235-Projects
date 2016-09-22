#pragma once
#include "FighterInterface.h"

class fighter :
	public FighterInterface
{
protected:
	string name;
	int currenthitpoints;
	int maxhitpoints;
	int strength;
	int speed;
	int magic;

public:
	fighter(string name, int maxhitpoints, int strength, int speed, int magic);
	~fighter();
	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getMagic();
	int getSpeed();
	void takeDamage(int damage);
	/*int getDamage();
	void reset();
	void regenerate();
	bool useAbility();*/
};

//	All fighters have the following attributes :
//*Name - The fighter's name
//*		Hit Points - The amount of health the fighter has, with a specified maximum; reaching 0 is equivalent to losing.A Fighter's
//*			starting Hit Points(which is a Fighter's maximum Hit Points) must be greater than 0. There is no upper bound to what
//*			a Fighter's starting/maximum Hit Points could be.
//*		Strength - Physical power, used to determine hit point regeneration.Must be greater than 0. No maximum value.
//*		Speed - Dexterity and physical movement, used to reduce damage when being attacked.Must be greater than 0. No maximum value.
//*		Magic - Magical prowess, used for some special abilities.Must be greater than 0. No maximum value.
