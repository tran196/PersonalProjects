/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	10/7/18       
** Description:  Langton Ant
		 main.cpp
		The rule of Langton’s Ant is very simple: the ant is placed onto the board 
		that is filled with white spaces, and starts moving forward.
		For each step forward, the Langton’s ant will follow 2 rules:
			- If the ant is on a white space, turn right 90 degrees and change the space to black.
			- If the ant is on a black space, turn left 90 degrees and change the space to white.
		After that the ant moves to the next step and continue moving forward.
		The ant will follow these rules, and continue moving around the board, until the number of steps runs out.
**               
*******************************************************************************/

#include <iostream>
#include <string>
#include "ant.hpp"
#include "board.hpp"

void menu();
void checkForChar(char &input);
void checkForInt(int &input);
void checkWithinBoundary(int &input, int boundary);

/**********************************************
** Description: 
**
**
***********************************************/
int main()
{
	menu();
	return 0;
}

/**********************************************
** Description: Menu Function
**
		When the program starts the menu should provide 2 options:
			- Start Langton’s Ant simulation
			- Quit

		If the user decided to quit, the program should quit.
		Otherwise, start the Langton’s Ant simulation.
		After the simulation starts, the program should prompt user for all the 
		information to run the simulation, including:
			- The number of rows for the board.
			- The number of columns for the board.
			- The number of steps during simulation.
			- The starting row of the ant.
			- The starting column of the ant.
		After the simulation ended, the menu should provide user 2 choices: play again, or quit.

		
**
***********************************************/
void menu()
{
	int boardRows, boardColumns, numberOfMoves;
	int startingRow, startingColumn;

	bool gameStatus = false;
	char startGame = 'n';

	do 
	{
	 	std:: cout << "Starting Langton Ant Program\n";

		std:: cout << "To Start Game Please Enter \'y\' for Yes or \'n\' to Quit\n";
		checkForChar(startGame);

		if (startGame == 'n')
		{
			break;
		}

		std:: cout << "How many rows will the board have?\n";	
		checkForInt(boardRows);								//helper function to check input

		std:: cout << "How many columns will the board have?\n";	
		checkForInt(boardColumns);							//helper function to check input

		std:: cout << "How many moves will the ant make?\n";
		checkForInt(numberOfMoves);							//helper function to check input

		std:: cout << "Enter the Starting Row for the Ant.\n";
		checkWithinBoundary(startingRow, boardRows);		//helper function to check input
		
		std:: cout << "Enter the Starting Column for the Ant\n";
		checkWithinBoundary(startingColumn, boardColumns);	
		
		//create ant object
		Ant ant1(startingRow, startingColumn, boardRows, boardColumns, numberOfMoves);
		
		//Start Game
		ant1.startGame(startingRow, startingColumn);

		std:: cout << "To Play Again Please Enter \'y\' for Yes or \'n\' to Quit\n";
		checkForChar(startGame);
		if (startGame == 'y')
		{
			gameStatus = true;
		}
		else if (startGame == 'n')
		{
			gameStatus = false;
		}

	} while (gameStatus);	
}

//Helper Functions

//Input Validation for Char
void checkForChar(char &input)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		std:: cin >> input;
		if (input == 'y')
		{
			break;
		}
		else if (input == 'n')
		{
			break;
		}
		else
		{
			invalidInput = true;
			std:: cout << "Please enter either \'y\' or \'n\' \n";
			std:: cin.clear();
			std:: cin.ignore();
		}
	} while(invalidInput);
}

//Input Validation for Integer
void checkForInt(int &input)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		std::cin >> input;
		if (std::cin.fail())
		{
			invalidInput = true;
			std:: cout << "Please enter a valid integer\n";
			std:: cin.clear();
			std:: cin.ignore();
		}
		else if (input < 0)
		{
			invalidInput = true;
			std:: cout << "Please enter a Positive integer\n";
			std:: cin.clear();
			std:: cin.ignore();
		}

	}while(invalidInput);
}

void checkWithinBoundary(int &input, int boundary)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		std:: cin >> input;
		if (input <= 0 || input > (boundary - 1))
		{
			invalidInput = true;
			std:: cout << "No within Board Boundary. Please enter a valid integer\n";
			std:: cin.clear();
			std:: cin.ignore();
		}
	}while (invalidInput);
}



