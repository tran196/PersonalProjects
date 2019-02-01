/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	       
** Description: Node CPP  File 
**              
*******************************************************************************/

#include "Node.hpp"
#include "character.hpp"

//Constructor
Node::Node()
{
	setPlayer(nullptr);
	next = nullptr;
	prev = nullptr;
}

//Destructor
Node::~Node()
{

}

//Getters
Node * Node::getNextNode()
{
	return next;
}

Node * Node::getPrevNode()
{
	return prev;
}

Character * Node::getPlayer()
{
	return player;
}

//Setters

void Node::setNextNode(Node * nextNode)
{
	next = nextNode;
}

void Node::setPrevNode(Node * prevNode)
{
	prev = prevNode;
}

void Node:: setPlayer(Character * p) 
{
	player = p;
}
