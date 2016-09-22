#include "fighter.h"


fighter::fighter(string name,int maxhitpoints,int strength,int speed, int magic)
{
	this->name = name;
	this->maxhitpoints = maxhitpoints;
	this->strength = strength;
	this->speed = speed;
	this->magic = magic;
	currenthitpoints = maxhitpoints;
}

fighter::~fighter()
{
}
string fighter::getName()
{
	return name;
}

/*
*	getMaximumHP()
*
*	Returns the maximum hit points of this fighter.
*/
int fighter::getMaximumHP()
{
	return maxhitpoints;
}

/*
*	getCurrentHP()
*
*	Returns the current hit points of this fighter.
*/
 int fighter::getCurrentHP()
 {
	 return currenthitpoints;
 }

/*
*	getStrength()
*
*	Returns the strength stat of this fighter.
*/ int fighter::getStrength()
 {
	 return strength;
 }

/*
*	getSpeed()
*
*	Returns the speed stat of this fighter.
*/
 int fighter::getSpeed()
 {
	 return speed;
 }
/*
*	getMagic()
*
*	Returns the magic stat of this fighter.
*/
 int fighter::getMagic()
 {
	 return magic;
 }
/*
*	takeDamage(int)
*
*	Reduces the fighter's current hit points by an amount equal to the given
*	damage minus one fourth of the fighter's speed.  This method must reduce
*	the fighter's current hit points by at least one.  It is acceptable for
*	this method to give the fighter negative current hit points.
*
*	Examples:
*		damage=10, speed=7		=> damage_taken=9
*		damage=10, speed=9		=> damage_taken=8
*		damage=10, speed=50		=> damage_taken=1
*/
 void fighter::takeDamage(int damage)
 {
	 int totaldamage = damage - (.25 * speed);

	 if (totaldamage > 1)
	 {
		 currenthitpoints -= totaldamage;
	 }

 }
 //int fighter::getDamage()
 //{
	// return NULL;
 //}
 //void fighter::reset() {}
 //void fighter::regenerate() {}
 //bool fighter::useAbility() 
 //{ return NULL;
 //}
