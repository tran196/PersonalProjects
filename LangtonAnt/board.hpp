/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	10/7/18       
** Description:  board.hpp
**               board header file
*******************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

/**********************************************
** Description: 
**		board.hpp header file
**
***********************************************/
class Board 
{
	private:
		char color;
		bool isAntOnSpace;

	public:
		//Getters
		char getColor();
		bool getIsAntOnSpace();
		
		//Setters
		void setColor(char c);
		void setIsAntOnSpace(bool isOn);

		//Constructor
		Board();
};

#endif
