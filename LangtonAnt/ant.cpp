/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	10/6/18       
** Description:  ant.cpp file
		The Ant class should contain all the information that includes:
		- The ant’s location
		- The ant’s orientation (the direction of the ant)
		Make sure only the class function can modify the variables of Ant class, 
		which means outside program cannot directly change the variables inside the Ant class,
		and instead should call the functions inside Ant class to indirectly modify variables.
		You can determine whether you need to have a separate board class and how you should design it.
**               
*******************************************************************************/

#include "ant.hpp"
#include "board.hpp"
#include <iostream>

//Default Constructor
Ant::Ant(int startRow, int startCol, int r, int col, int totalM)
{
	antRowPosition 	= startRow;
	antColPosition 	= startCol;
	row 			= r;
	column 			= col;
	orientation 	= 'N';

	totalMoves 	= totalM;
	currentMove 	= 0;

	//Create 2-D Array for game board
	gameBoard = new Board*[row];
	for (int i = 0; i < row; i++)
	{
		gameBoard[i] = new Board[column];
	}
}

//Destructor
Ant::~Ant()
{	
	//Delete array of pointers
	for(int i = 0; i < row; i++)
	{	
		delete [] gameBoard[i];
	}

	delete [] gameBoard;
	gameBoard = NULL;
}

// Getters

int Ant::getAntRowPosition()
{
	return antRowPosition;
}

int Ant::getAntColPosition()
{
	return antColPosition;
}

char Ant::getAntOrientation()
{
	return orientation;
}

// getAntPosition() functions returns a Board object that has the Ant's Position
Board Ant::getAntPosition() 	
{
	int x = getAntRowPosition();
	int y = getAntColPosition();

	return gameBoard[x][y];
}

//getSpaceColor() function returns the color of the Space 
char Ant::getSpaceColor()
{
		//getAntPosition() returns a Board obj's Position
		//then we use getColor() from the Board member function 
		//to return what color the Space is
	return getAntPosition().getColor(); 	

}

// Setters

void Ant::setAntRowPosition(int x) 		//set x Position
{
	antRowPosition = x;
}

void Ant::setAntColPosition(int y) 		//set y Position
{
	antColPosition = y;
}

void Ant::setOrientation(char o) 	// set Ant Orientation
{
	orientation = o;
}

//Functions

void Ant::makeMove()
{
	
	if (currentMove > 0)
	{

		
		if(getSpaceColor() == ' ') 		//if space is white ' '
		{
			onWhite();
			// moveAnt();
		}
		else if(getSpaceColor() == '#')		//if space is black '#'
		{
			onBlack();
			// moveAnt();
		}

	}
	else if (currentMove == 0)		// handle first move of game
	{	
		print();
		gameBoard[antRowPosition][antColPosition].setColor('#');
	}

	//temporarily remove ant from gameboard
	gameBoard[antRowPosition][antColPosition].setIsAntOnSpace(false);

	//move the ant
	moveAnt();

	//put ant back on gameboard
	gameBoard[antRowPosition][antColPosition].setIsAntOnSpace(true);

	print();						//use print function to display board
	currentMove++;					//increment the current move counter
	std:: cout << "You have done " << currentMove << " moves so far." <<std:: endl;

}

/******************
Description:
	onWhite() Function
	If ant is on white space then turn 90 degrees to the right and change space
	to black '#'
******************/
void Ant::onWhite()
{
	switch(orientation)
	{
		case 'N': setOrientation('E');
			break;
		case 'E': setOrientation('S');
			break;
		case 'S': setOrientation('W');
			break;
		case 'W': setOrientation('N');
			break;
	}
	
	int x = getAntRowPosition();
	int y = getAntColPosition();
	gameBoard[x][y].setColor('#');
}

/******************
Description:
	onBlack() Function
If ant is on black space then turn 90 degrees to the left and change space
to white ' '
******************/
void Ant::onBlack()
{
	switch(orientation)
	{
		case 'N': setOrientation('W');
			break;
		case 'W': setOrientation('S');
			break;
		case 'S': setOrientation('E');
			break;
		case 'E': setOrientation('N');
			break;
	}
	
	int x = getAntRowPosition();
	int y = getAntColPosition();
	gameBoard[x][y].setColor(' ');
}

void Ant::moveAnt()
{
	//make sure ant doesn't move off board
	//Make sure ant doesn't go off left side of board
	if(antColPosition == 0 && orientation == 'W')
	{
		setOrientation('E');		//turn ant around 180 degrees 
	}
	//Make sure ant doesn't go off top side of board
	else if (antRowPosition == 0 && orientation == 'N')
	{
		setOrientation('S');
	}
	//Make sure ant doesn't go off right side of board
	else if (antColPosition == (column -1) && orientation == 'E')
	{
		setOrientation('W');
	}
	//Make sure ant doesn't go off bottom side of board
	else if (antRowPosition == (row - 1) && orientation == 'S')
	{
		setOrientation('N');
	}

	//Move the ant 
	switch(orientation)
	{
		case 'N':					//Facing north move up 1 row
		{
			if (antRowPosition > 0)
			{
				setAntRowPosition(getAntRowPosition() - 1);
			}
			break;
		}
		case 'W':					//facing west move left 1 column
		{
			if (antColPosition > 0)
			{
				setAntColPosition(getAntColPosition() - 1);
			}
			break;
		}
		case 'E':				//facing east move right 1 column
		{
			if (antColPosition < column)
			{
				setAntColPosition(getAntColPosition() + 1);
			}
			break;
		}
		case 'S':				//facing south move down 1 row
		{
			if (antRowPosition < row)
			{
				setAntRowPosition(getAntRowPosition() + 1);
			}
			break;
		}
	}

}

/******
Description:
	print() function print out gameBoard
*******/
void Ant::print()
{
	for(int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if(gameBoard[i][j].getIsAntOnSpace())
			{
				std::cout << "* "; 			//print out ant 
			}
			else
			{
				std::cout << gameBoard[i][j].getColor() << " ";
			}
		}
		std:: cout << std:: endl;
	}

	//test to find out where is ant
	std:: cout << "Ant is at row " << getAntRowPosition(); 
	std:: cout << " and column " << getAntColPosition() ;
	std:: cout << " Ant orientation is " << getAntOrientation() << std:: endl;
}

/*********
Description:
	startGame() function takes 2 int arguments for starting row and column
	sets the ant in that positon and prints out the starting board 
**********/

void Ant::startGame(int startingRow, int startingCol)
{
	antRowPosition = startingRow;
	antColPosition = startingCol;
	
	//set ant on starting position
	gameBoard[antRowPosition][antColPosition].setIsAntOnSpace(true);
	

	//while loop to start game
	while (currentMove < totalMoves)
	{
		makeMove();

	}
}
