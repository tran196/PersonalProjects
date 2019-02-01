/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	       
** Description: medusa.cpp
**              
*******************************************************************************/

#include "medusa.hpp"
#include <cstdlib>
#include <iostream>

//Constructor
Medusa::Medusa()
{
	setType("medusa");

	setAttackDieSides(6);
	setAttackNumOfDie(2);

	setDefenseDieSides(6);
	setDefenseNumOfDie(1);

	setArmor(3);
	setStrength(8);

}

Medusa:: ~Medusa()
{

}

//Getters


//Setters

//Functions

void Medusa:: defense(int d)
{
	if (d > 0)
	{
		setStrength(getStrength() - d);
	}
}

//Medusa Attack
int Medusa:: calcAttackRoll()
{
	int result = 0;
	for (int i = 0; i < getAttackNumOfDie(); i++)
	{
		result = result + (rand() % getAttackDieSides()) + 1;
		result = 12;
		//Medusa Special Ability if result == 12 then Medusa Automatically Wins
		if (result == 12)
		{
			std:: cout << "Medusa uses Glare\n";
			return 1000;
		}
	}
	return result;
}
