/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	
** Description: medusa.hpp
**              
*******************************************************************************/
#include "character.hpp"

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <string>

class Medusa : public Character
{
	private:

		std:: string type;

	public:
		//Getters
		
		//Setters

		//Functions
		void defense(int d);
		virtual int calcAttackRoll();
		// int calcDefenseRoll();
		
		//Constructor
		Medusa();



		//Destructor
		~Medusa();
};

#endif
