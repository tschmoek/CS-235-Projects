#include "archer.h"


archer::archer(string name, int maxhitpoints, int strength, int speed, int magic)
	:fighter (name, maxhitpoints, strength, speed, magic)
{
	currentspeed = speed;
}
archer::~archer()
{
}
/*
*	getDamage()
*
*	Returns the amount of damage a fighter will deal.
*	Archer:
*	This value is equal to the Archer's speed.
*/
int archer::getDamage()
{
	return currentspeed;
}

/*
*	reset()
*	Archer:
*	Also resets an Archer's current speed to its original value.
*/
void archer::reset()
{
	currenthitpoints = maxhitpoints;
	currentspeed = speed;
}

/*
*	regenerate()
*
*	Increases the fighter's current hit points by an amount equal to one sixth of
*	the fighter's strength.  This method must increase the fighter's current hit
*	points by at least one.  Do not allow the current hit points to exceed the
*	maximum hit points.
*/
void archer::regenerate()
{
	int totalregenerate = (.16 * strength);
	int newhealth = totalregenerate + currenthitpoints;
		if (totalregenerate > 1 && newhealth <= maxhitpoints)
		{
			currenthitpoints += totalregenerate;
		}
}

/*
*
*	Archer: Quickstep
*	Increases the Archer's speed by one point each time the ability is used.
*	This bonus lasts until the reset() method is used.
*	This ability always works; there is no maximum bonus speed.
*
*	Return true if the ability was used; false otherwise.
*/
bool archer::useAbility()
{
	speed += 1;
	return true;
}
