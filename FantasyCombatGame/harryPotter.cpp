/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	       
** Description: harrypotter.cpp
**              
*******************************************************************************/

#include "harryPotter.hpp"
#include <cstdlib>
#include <iostream>

//Constructor
HarryPotter::HarryPotter()
{
	setType("harrypotter");
	diedOnce = false;

	setAttackDieSides(6);
	setAttackNumOfDie(2);

	setDefenseDieSides(6);
	setDefenseNumOfDie(2);

	setArmor(0);
	setStrength(10);

}

HarryPotter:: ~HarryPotter()
{

}

//Getters


//Setters


void HarryPotter:: defense(int d)
{
	if (d > 0)
	{
		int armor = getArmor();
		d = d - armor;
		setStrength(getStrength() - d);
	}
	if (getStrength() <= 0)			//If Harry Potter Dies then Check to use Hogwarts Special Ability
	{
		if (!diedOnce)
		{
			std:: cout << "Using Hogwarts Spell\nHarry Potter Revived and Strength is 20\n";
			setStrength(20);
			diedOnce = true;
		}
	}
}
