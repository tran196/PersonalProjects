/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	
** Description:  character.hpp file
**              
*******************************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>


class Character
{
	private:
		std:: string type;
		std:: string name;

		int attackDieSides;	//number of attack die sides
		int attackNumOfDie;
		int attackPoints;

		int defenseDieSides;
		int defenseNumOfDie;
		int defensePoints;

		int armor; 
		int strength;

	public:
		//Getters
		std:: string getType()
		{
			return type;
		}
		std:: string getName()
		{
			return name;
		}
		int getAttackPoints() 
		{ 
			return attackPoints; 
		};
		int getDefensePoints() 
		{ 
			return defensePoints; 
		}; 
		int getArmor() 
		{ 
			return armor; 
		}; 
		int getStrength() 
		{ 
			return strength; 
		}; 
		int getAttackDieSides()
		{
			return attackDieSides;
		}
		int getAttackNumOfDie()
		{
			return attackNumOfDie;
		}
		int getDefenseDieSides()
		{
			return defenseDieSides;
		}
		int getDefenseNumOfDie()
		{
			return defenseNumOfDie;
		}
		//Setters
		void setType(std::string s)
		{
			type = s;
		}
		void setName(std::string s)
		{
			name = s;
		}
		void setAttackPoints(int a) 
		{ 
			attackPoints = a; 
		};
		void setDefensePoints(int d) 
		{ 
			defensePoints = d; 
		};
		void setArmor(int a) 
		{ 
			armor = a; 
		};
		void setStrength(int a) 
		{ 
			strength = a; 
		};
		void setAttackDieSides(int s)
		{
			attackDieSides = s;
		};
		void setAttackNumOfDie(int s)
		{
			attackNumOfDie = s;
		};
		void setDefenseDieSides(int s)
		{
			defenseDieSides = s;
		};
		void setDefenseNumOfDie(int s)
		{
			defenseNumOfDie = s;
		};


		//Functions
		virtual int calcAttackRoll();	//return attack roll number
		virtual int calcDefenseRoll();	//return defense roll number
		virtual void defense(int d)=0;

		//Constructors
		Character();

		//Destructor 
		~Character();

};

#endif
