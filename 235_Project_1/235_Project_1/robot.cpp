#include "robot.h"


robot::robot(string name, int maxhitpoints, int strength, int speed, int magic)
	:fighter( name,  maxhitpoints,  strength,  speed,  magic)
{
	energy = 2 * magic;
	currentenergy = energy;
}


robot::~robot()
{
}
/*
*	getDamage()
*
*	Returns the amount of damage a fighter will deal.
*
*	Robot:
*	This value is equal to the Robot's strength plus any additional damage added for having just used its special ability.
*/
int robot::getDamage()
{
	return strength;
}
/*
*	reset()
*
*	Restores a fighter's current hit points to its maximum hit points.
*
*	Robot:
*	Also restores a Robot's current energy to its maximum value (which is 2 times its magic).
*	Also resets a Robot's bonus damage (calculated when a Robot uses its ability) to 0.
*/
void robot::reset()
{
	currenthitpoints = maxhitpoints;
	currentenergy = energy;

}
/*
*	regenerate()
*
*	Increases the fighter's current hit points by an amount equal to one sixth of
*	the fighter's strength.  This method must increase the fighter's current hit
*	points by at least one.  Do not allow the current hit points to exceed the
*	maximum hit points.
*/
void robot::regenerate()
{
	int totalregenerate = (.16 * strength);
	int newhealth = totalregenerate + currenthitpoints;
		if (totalregenerate > 1 && newhealth <= maxhitpoints)
		{
			currenthitpoints += totalregenerate;
		}

}

/*
*	useAbility()
*
*	Robot: Shockwave Punch
*	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
*	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
*	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
*		Examples:
*		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
*		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
*		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
*		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
*	Robot Note:
*	The bonus damage formula should be computed using double arithmetic, and only
*	the final result should be cast into an integer.
*
*	Return true if the ability was used; false otherwise.
*/
bool robot::useAbility()
{
	double powered = pow((currentenergy / energy), 4);
	double bonus = strength * powered;
	if (currentenergy >= ROBOT_ABILITY_COST)
	{
		currentenergy -= ROBOT_ABILITY_COST;
		strength += bonus;
		return true;
	}
}
