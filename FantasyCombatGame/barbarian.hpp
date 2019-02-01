/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	
** Description:  barbarian.hpp
**              
*******************************************************************************/
#include "character.hpp"

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <string>


class Barbarian : public Character
{
	private:

		std:: string type;

	public:
		//Getters
		
		//Setters

		//Functions
		void defense(int d);
		
		//Constructor
		Barbarian();



		//Destructor
		~Barbarian();
};

#endif
