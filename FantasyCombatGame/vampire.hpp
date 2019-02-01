/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	
** Description:  vampire.hpp
**              
*******************************************************************************/
#include "character.hpp"

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <string>


class Vampire : public Character
{
	private:

		std:: string type;

	public:
		//Getters
		
		//Setters

		//Functions

		virtual void defense(int d);
		
		//Constructor
		Vampire();

		//Destructor
		~Vampire();
};

#endif