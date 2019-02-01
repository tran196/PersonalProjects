/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	
** Description:  bluemen.hpp
**              
*******************************************************************************/
#include "character.hpp"

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include <string>

class BlueMen : public Character
{
	private:

		std:: string type;
		int totalDamageCount;

	public:
		//Getters
		int getTotalDamageCount() 
		{
			return totalDamageCount;
		};
		
		//Setters
		void setTotalDamageCount(int d)
		{
			totalDamageCount = d;
		}

		//Functions
		virtual void defense(int d);
		
		//Constructor
		BlueMen();

		//Destructor
		~BlueMen();
};

#endif
