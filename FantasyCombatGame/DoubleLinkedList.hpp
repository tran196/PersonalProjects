/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	
** Description:  Double Linked List HPP  File
**              
*******************************************************************************/

#ifndef DOUBLELINKEDLIST_HPP
#define DOUBLELINKEDLIST_HPP

#include "Node.hpp"

class DoubleLinkedList 
{
	private:
	Node * head;
	Node * tail;
		

	public:
		//Getters
		Node * getHeadNode();

		Node * getTailNode();
		
		//Setters
		void setHeadNode(Node * n);

		void setTailNode(Node * n);



		//Functions

		void addNewNodeToHead(Character * n);				//Function 1
		void addNewNodeToTail(Character * n);				//Function 2
		void deleteHeadNode();						//Function 3
		void deleteTailNode();						//Function 4
		// void traverseListBackToFront(Node * tail); 	//Function 5
		// void traverseListFrontToBack(Node *head); 	//Function 6
		void traverseListBackToFront(); 	//Function 5
		void traverseListFrontToBack(); 	//Function 6

		void printHeadNode();						//Extra Credit
		void printTailNode();						//Extra Credit
		// void createLinkedListFromFile();			//Extra Credit

		//Constructor
		DoubleLinkedList();

		//Destructor
		~DoubleLinkedList();

};

#endif
