/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	       
** Description: blueMen.cpp
**              
*******************************************************************************/

#include "blueMen.hpp"
#include <iostream>

//Constructor
BlueMen::BlueMen()
{
	setType("bluemen");

	setTotalDamageCount(0);

	setAttackDieSides(10);
	setAttackNumOfDie(2);

	setDefenseDieSides(6);
	setDefenseNumOfDie(3);

	setArmor(3);
	setStrength(12);

}

BlueMen:: ~BlueMen()
{

}

//Getters


//Setters

//Function 

void BlueMen:: defense(int d)
{
	std::cout << "Blue Men Mob Defense\n";
	if (d > 0)
	{
		int armor = getArmor();
		d = d - armor;
		setStrength(getStrength() - d);
		setTotalDamageCount(getTotalDamageCount() + d);
	}
	if (getTotalDamageCount() > 3)
	{
		//Reduce Number of Die if BlueMen loses 4 strength
		setDefenseNumOfDie(getStrength() / 4);
	}
}
