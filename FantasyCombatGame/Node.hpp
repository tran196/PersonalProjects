/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	
** Description:  Node HPP  File
**              
*******************************************************************************/

#ifndef NODE_HPP
#define NODE_HPP

#include "character.hpp"

class Node 
{
	private:
		Node * next;
		Node * prev;
		Character * player;

	public:
		//Getters
		Node * getNextNode();

		Node * getPrevNode();

		Character * getPlayer();
		
		//Setters
		void setNextNode(Node * nextNode);
		void setPrevNode(Node * prevNode);
		void setPlayer(Character * player); 
		
		//Constructor
		Node();

		//Destructor
		~Node();
};

#endif
