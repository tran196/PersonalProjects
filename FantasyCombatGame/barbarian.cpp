/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	       
** Description: barbarian.cpp
**              
*******************************************************************************/

#include "barbarian.hpp"

//Constructor
Barbarian::Barbarian()
{

	setType("barbarian");

	setAttackDieSides(6);
	setAttackNumOfDie(2);

	setDefenseDieSides(6);
	setDefenseNumOfDie(2);

	setArmor(0);
	setStrength(12);


}

Barbarian:: ~Barbarian()
{

}

//Getters


//Setters

//Functions

void Barbarian:: defense(int d)
{
	if (d > 0)
	{
		setStrength(getStrength() - d);
	}
}
