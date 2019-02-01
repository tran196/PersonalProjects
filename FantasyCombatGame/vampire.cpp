/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	       
** Description: vampire.cpp
**              
*******************************************************************************/

#include "vampire.hpp"
#include <iostream>

//Constructor
Vampire::Vampire()
{
	setType("vampire");

	setAttackDieSides(12);
	setAttackNumOfDie(1);

	setDefenseDieSides(6);
	setDefenseNumOfDie(1);

	setArmor(1);
	setStrength(18);

}

Vampire:: ~Vampire()
{

}

//Getters


//Setters

//Functions

void Vampire:: defense(int d)
{
	if (d > 0)
	{
		if (rand() % 2 == 0)	//50% chance that Vampire uses charm ability
		{
			std:: cout << "Used Vampire Charm. No Damage Taken\n";
		}
		else
		{
			setStrength(getStrength() - d);
		}
		
	}
}

