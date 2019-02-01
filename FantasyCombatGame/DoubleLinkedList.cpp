/******************************************************************************* 
** Author:       Tuan Tran
** Date:  	       
** Description: Double Linked List CPP  File 
**              
*******************************************************************************/

#include "DoubleLinkedList.hpp"
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <string>

//Constructor
DoubleLinkedList::DoubleLinkedList()
{
	head = nullptr;
	tail = nullptr;
}

//Destructor 
DoubleLinkedList::~DoubleLinkedList()
{
	Node * n = head;
	if(n != nullptr)
	{
		while (n->getNextNode() != nullptr)
		{
			n = n->getNextNode();
			delete n->getPrevNode();
		}
		delete n;
	}
}

//Getters

Node * DoubleLinkedList::getHeadNode()
{
	return head;
}

Node * DoubleLinkedList::getTailNode()
{
	return tail;
}

//Setters
void DoubleLinkedList::setHeadNode(Node * n)
{
	if (n != nullptr) {
		// Set next of the new head to the old head if one exists
		n->setNextNode(head);
		// Set the new head's prev pointer to null in its new position
		n->setPrevNode(nullptr);
    }
    if (head != nullptr) {
        // Set prev pointer of head to the new node (or nullptr)
        head->setPrevNode(n);
    }
    head = n;
}

void DoubleLinkedList::setTailNode(Node * n)
{
	if (n != nullptr) 
	{
		n->setNextNode(nullptr);
		n->setPrevNode(tail);
    }
    if (tail != nullptr) {
        tail->setNextNode(n);
    }
    tail = n;
}

//Functions

/*****
 * Description:
	* When user adds a new node, the program should prompt the user to enter a 
	* number and validate the input, before calling the function.

	* Operation of adding functions: The function should create a new Node with inputted value stored inside, 
	* add the Node object to the list, and re-assign the head tail pointer accordingly. 
	* After the Node is added, the menu should call function #6, which prints the linked list from head to tail.	
 * *******/
void DoubleLinkedList::addNewNodeToHead(Character * n)				//Function 1
{
    Node* n1 = new Node();
	n1->setPlayer(n);
    // Set the head node
    setHeadNode(n1);
    // Set the tail if none exists
    if (getTailNode() == nullptr) 
    {
        setTailNode(n1);
    }		
	std:: cout << "Your linked list is:\n";
	// traverseListFrontToBack(head);

	traverseListFrontToBack();			//test without argument
}

//Add Node to tail
void DoubleLinkedList::addNewNodeToTail(Character *  n)				//Function 2
{
    Node* n1 = new Node();
	n1->setPlayer(n);
    // Set the tail node
    setTailNode(n1);
    // Set the head if none exists
    if (getHeadNode() == nullptr) 
    {
        setHeadNode(n1);
    }
	//std:: cout << "Your linked list is: ";
	// traverseListFrontToBack(head);

	//traverseListFrontToBack();		//test without argument
}

//Delete first node in the list
void DoubleLinkedList::deleteHeadNode()						//Function 3
{	
	//Copy node to head node 
	Node *currentHeadNode = head;

	//Check to see if head node exists
	if (head != nullptr)
	{
		if (head == tail)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			head = head->getNextNode();
			head->setPrevNode(nullptr);
		}
		delete currentHeadNode;
		
		// std:: cout << "Your linked list is:\n";
		// traverseListFrontToBack(head);

		//traverseListFrontToBack();		//test without argument
	}
	else
	{
		std:: cout << "There is no head node\n";
	}
}

void DoubleLinkedList::deleteTailNode()						//Function 4
{
	//Copy node to tail node 
	Node *currentTailNode = tail;

	//Check to see if head node exists
	if (tail != nullptr)
	{
		if (tail == head)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			tail = tail->getPrevNode();
			tail->setNextNode(nullptr);
		}
		delete currentTailNode;
		// std:: cout << "Your linked list is:\n";
		// traverseListFrontToBack(head);

		// traverseListFrontToBack();		//test without argument
	}
	else
	{
		std:: cout << "There is no tail node\n";
	}
}


// void DoubleLinkedList::traverseListBackToFront(Node * tail) 	//Function 5	
void DoubleLinkedList::traverseListBackToFront() 	//Function 5		test without argument
{
	// Node *n = tail;
	Node *n = getTailNode();
	if (n == nullptr)
	{
		std:: cout << "The List is Empty\n";
		return;
	}
	while (n != nullptr) 
	{
        // Print the value
		if (n != nullptr) 
		{
        // std:: cout << n->getVal() << std:: endl;
		std:: cout << n->getPlayer()->getName() << " ";
    	}
        // Move on to the prev
        n = n->getPrevNode();
    }

}
// void DoubleLinkedList::traverseListFrontToBack(Node * head) 	//Function 6
void DoubleLinkedList::traverseListFrontToBack() 	//Function 6
{
	// Node* n = head;
	Node* n = getHeadNode();
    // Print a message if the list is empty
    if (n == nullptr) {
        std:: cout << "This list is empty.\n";
		return;
    }
    while (n != nullptr) 
	{
        // Print the value
		if (n != nullptr) 
		{
        // std:: cout << n->getVal() << std:: endl;
		std:: cout << n->getPlayer()->getName() << " ";
    	}
        // Move on to the next
        n = n->getNextNode();
    }
	std:: cout << std:: endl;
}

void DoubleLinkedList:: printHeadNode()
{
	if (getHeadNode() != nullptr)
	{
		std:: cout << "Head Value: " << head->getPlayer() << std:: endl;
	}
}

void DoubleLinkedList:: printTailNode()
{
	if (getTailNode() != nullptr)
	{
		std:: cout << "Tail Value: " << tail->getPlayer() << std:: endl;
	}
}

// void DoubleLinkedList:: createLinkedListFromFile()
// {
// 	std:: cout << "Creating Linked List from File\n";

// 	std:: ifstream inputFile;	//Initalize ifstream object

// 	inputFile.open("LinkedListInput.txt");

// 	int result = 0;

// 	if(inputFile)
// 	{
// 		while (inputFile >> result)
// 		{
// 			addNewNodeToTail(result);
// 		}

// 		inputFile.close();
// 	}
// 	else
// 	{
// 		std:: cout << "Error Opening File.\n";
// 	}

// }



