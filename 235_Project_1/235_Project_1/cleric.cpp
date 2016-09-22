#include "cleric.h"


cleric::cleric(string name, int maxhitpoints, int strength, int speed, int magic)
	:fighter ( name,  maxhitpoints,  strength,  speed,  magic)
{
	mana = 5 * magic;
}


cleric::~cleric()
{
}
/*
*	getDamage()
*
*	Returns the amount of damage a fighter will deal.
*
*	Cleric:
*	This value is equal to the Cleric's magic.
*/
int cleric::getDamage()
{
	return magic;
}
/*
*	reset()
*
*	Restores a fighter's current hit points to its maximum hit points.
*
*	Cleric:
*	Also restores a Cleric's current mana to its maximum value (which is 5 times its magic).
*/
void cleric::reset()
{
	currenthitpoints = maxhitpoints;
	currentmana = mana;
}

/*
*	regenerate()
*
*	Increases the fighter's current hit points by an amount equal to one sixth of
*	the fighter's strength.  This method must increase the fighter's current hit
*	points by at least one.  Do not allow the current hit points to exceed the
*	maximum hit points.
*
*	Cleric:
*	Also increases a Cleric's current mana by an amount equal to one fifth of the
*	Cleric's magic.  This method must increase the Cleric's current mana by at
*	least one.  Do not allow the current mana to exceed the maximum mana (again, 5 times its magic).
*/
void cleric::regenerate()
{
	int totalregenerate = (.16 * strength);
	int newhealth = totalregenerate + currenthitpoints;
	int totalmana = (.2 * magic);
	int newmana = currentmana + totalmana;

	if(totalregenerate > 1 && newmana <= mana)
	{
		currentmana += totalmana;
	}
		if (totalregenerate > 1 && newhealth <= maxhitpoints)
		{
			currenthitpoints += totalregenerate;
		}

}
/*
*	Cleric: Healing Light
*	Increases the Cleric's current hit points by an amount equal to one third of its magic.
*	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
*	Will be used even if the Cleric's current HP is equal to their maximum HP.
*	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
*	Cleric Note:
*	This ability, when successful, must increase the Cleric's current hit points
*	by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
*	Do not allow the current hit points to exceed the maximum hit points.
*
*	Return true if the ability was used; false otherwise.
*/
bool cleric::useAbility()
{

	if(mana >= CLERIC_ABILITY_COST)
	{
		 currenthitpoints += (.33 * magic);
		 mana -= CLERIC_ABILITY_COST;
	}


	return true;
}
