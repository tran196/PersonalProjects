/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	10/7/18       
** Description:  board.cpp
**               board cpp file
*******************************************************************************/

#include "board.hpp"

//Constructor
Board::Board()
{
	color = ' '; 		//Starting off with White ' ' space
	isAntOnSpace = false; 	//Starts off with Ant not on space
}

//Getters
char Board::getColor ()
{
	return color;
}

bool Board::getIsAntOnSpace()
{
	return isAntOnSpace;
}

//Setters
void Board::setColor(char c)
{
	color = c;
}

void Board::setIsAntOnSpace(bool isOn)
{
	isAntOnSpace = isOn;
}

