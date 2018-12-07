/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	10/6/18       
** Description:  ant.hpp file
		The Ant class should contain all the information that includes:
		- The ant’s location
		- The ant’s orientation (the direction of the ant)
		Make sure only the class function can modify the variables of Ant class, 
		which means outside program cannot directly change the variables inside the Ant class,
		and instead should call the functions inside Ant class to indirectly modify variables.
		You can determine whether you need to have a separate board class and how you should design it.
**               
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "board.hpp"

class Ant
{
	private:
		char orientation; 	//direction of ant (N, S, E, W)
		int antRowPosition;	//Row location of Ant 
		int antColPosition;	//Column location of Ant
		
		int row;		//Hold Total Rows for Board
		int column;		//Hold Total Columns for Board

		int totalMoves;		//Keep track of total moves of Ant
		int currentMove;	//Keep track of current move of Ant

		Board **gameBoard; 	//Use Pointer to a Pointer in order to
					//Dynamically Allocate 2-D Array for 
					//a game board
	public:

		//Getters
		int getAntRowPosition();
		int getAntColPosition();
		char getAntOrientation();

		Board getAntPosition();
		char getSpaceColor();

		//Setters
		void setAntRowPosition(int row);
		void setAntColPosition(int col);
		void setOrientation(char o);

		//Functions
		void makeMove();
		void onWhite();
		void onBlack();
		void moveAnt();
		void print();
		void startGame(int row, int column);

		//Default Constructor
		Ant(int startingRow, int startingCol, int r, int col, int totalM);

		//Destructor
		~Ant();
};

#endif

