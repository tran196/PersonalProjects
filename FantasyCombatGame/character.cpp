/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	       
** Description: character.cpp
**              
*******************************************************************************/

#include "character.hpp"
#include <cstdlib>
#include <iostream>

//Constructor
Character::Character()
{
	
}


Character:: ~Character()
{
}

//Functions

//Calculate attack points 
int Character:: calcAttackRoll()
{
	int result = 0;
	for (int i = 0; i < getAttackNumOfDie(); i++)
	{
		result = result + (rand() % getAttackDieSides()) + 1;
	}
	return result;
}
//Calculate defense points 
int Character:: calcDefenseRoll()
{
	int result = 0;
	for (int i = 0; i < getDefenseNumOfDie(); i++)
	{
		result = result + (rand() % getDefenseDieSides()) + 1;
	}
	return result;
}

//Reduces Strength and Does a Special Ability if Character has one
void Character:: defense(int d)
{
	if (d > 0)
	{
		setStrength(getStrength() - d);
	}
}


