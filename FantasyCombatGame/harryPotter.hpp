/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	
** Description:  harry potter hpp file
**              
*******************************************************************************/
#include "character.hpp"

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include <string>

class HarryPotter : public Character
{
	private:
		std:: string type;
		bool diedOnce;

	public:
		//Getters
		
		//Setters

		//Function

		virtual void defense(int d);

		//Constructor
		HarryPotter();

		//Destructor
		~HarryPotter();
};

#endif
