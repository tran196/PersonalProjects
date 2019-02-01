/******************************************************************************* 
** Author:       Tuan Tran
** Date:         11/19/18
** Description:  Project 4
**               
*******************************************************************************/

#include <iostream>
#include "character.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "harryPotter.hpp"
#include "vampire.hpp"
#include "blueMen.hpp"


#include "Node.hpp"
#include "DoubleLinkedList.hpp"

void playRound(Character *obj1, Character *obj2);
void menu();
void checkForChar(char &input);
void checkForCharacter1Input(char &input);
void checkForCharacter2Input(char &input);
void checkForInt(int &input);
void printCharacterMenu();
void checkForOneOrTwo(int &input);


int main()
{
	menu();

	return 0;
}

void playRound(Character *obj1, Character *obj2)
{
	//1. Attacker Type
	std:: cout << "Attacker Type: " << obj1->getType() << "Name: " << obj1->getName() << std:: endl;

	//2. Defender Type, Armor, Strength
	std:: cout << "Defender Type: " << obj2->getType() << "Name: " << obj2->getName() << std:: endl;
	std:: cout << "Defender Armor: " << obj2->getArmor() << std:: endl;
	std:: cout << "Defender Strength: " << obj2->getStrength() << std:: endl;

	//3. Attacker's Attack Dice Roll
	int obj1AttackPoints = obj1->calcAttackRoll();
	obj1->setAttackPoints(obj1AttackPoints);
	std:: cout << "Attack Dice Roll: "<< obj1AttackPoints << std:: endl;
	
	//4. Defender's Defense Dice Roll
	int obj2DefensePoints = obj2->calcDefenseRoll();
	obj2->setDefensePoints(obj2DefensePoints);
	std:: cout << "Defense Dice Roll: "<< obj2DefensePoints << std:: endl;
	// std:: cout << obj2->getType() << " Armor Points: " << obj2->getArmor() << std:: endl;

	//5. Damage = Attackers Roll - (Defenders Roll + Armor)
	int damage = obj1AttackPoints - (obj2DefensePoints + obj2->getArmor());
	std:: cout << "Damage dealt: " << damage << std:: endl;

	// Defender's Updated Strength Point Amount
	//Inflict damange
	obj2->defense(damage);
	//Display Obj1 Strength Points
	// std:: cout << "Attacker " << obj1->getType() << " Strength Points: " << obj1->getStrength() << std:: endl;
	//Display Obj2 Strength Points
	std:: cout << "Defender " << obj2->getType() << ": Updated Strength Points: " << obj2->getStrength() << std:: endl;

	//Check Strength > 0
	if (obj2->getStrength() <= 0)
	{
		std:: cout << obj2->getName() << " has died. Fight Over\n";

		std:: cout << "As A Reward For Winning: Adding 3 Stregth Points Back to " << obj1->getName() << "\n";
		obj1->setStrength(obj1->getStrength() + 3);
		return;
	}

	//Switching Attacking/Defending
	std:: cout << std:: endl;

	//1. Attacker Type
	std:: cout << "Attacker Type: " << obj2->getType() << "Name: " << obj2->getName() << std:: endl;

	//2. Defender Type, Armor, Strength
	std:: cout << "Defender Type: " << obj1->getType() << "Name: " << obj1->getName() << std:: endl;
	std:: cout << "Defender Armor: " << obj1->getArmor() << std:: endl;
	std:: cout << "Defender Strength: " << obj1->getStrength() << std:: endl;

	//3. Attacker's Attack Dice Roll
	int obj2AttackPoints = obj2->calcAttackRoll();
	obj2->setAttackPoints(obj2AttackPoints);
	std:: cout << "Attack Dice Roll: "<< obj2AttackPoints << std:: endl;
	
	//4. Defender's Defense Dice Roll
	int obj1DefensePoints = obj1->calcDefenseRoll();
	obj1->setDefensePoints(obj1DefensePoints);
	std:: cout << "Defense Dice Roll: "<< obj1DefensePoints << std:: endl;
	// std:: cout << obj2->getType() << " Armor Points: " << obj2->getArmor() << std:: endl;

	//5. Damage = Attackers Roll - (Defenders Roll + Armor)
	damage = obj2AttackPoints - (obj1DefensePoints + obj1->getArmor());
	std:: cout << "Damage dealt: " << damage << std:: endl;

	// Defender's Updated Strength Point Amount
	//Inflict damange
	obj1->defense(damage);
	//Display Obj1 Strength Points
	// std:: cout << "Attacker " << obj1->getType() << " Strength Points: " << obj1->getStrength() << std:: endl;
	//Display Obj2 Strength Points
	std:: cout << "Defender " << obj1->getType() << " Strength Points: " << obj1->getStrength() << std:: endl;

	//Check Strength > 0
	if (obj1->getStrength() <= 0)
	{
		std:: cout << obj1->getName() << " has died. Fight Over\n";

		std:: cout << "As A Reward For Winning: Adding 3 Stregth Points Back to " << obj2->getName() << "\n";
		obj2->setStrength(obj2->getStrength() + 3);
		return;
	}
}


void menu()
{

	bool gameStatus = false;
	bool continueRound = true;
	int startGame;
	int playAgain, viewLoserList;

	int numOfPlayersTeam1, numOfPlayersTeam2;
	int team1Score, team2Score;

	char player1Choice, player2Choice;

	int roundCounter = 0;

	DoubleLinkedList * team1 = new DoubleLinkedList;
	DoubleLinkedList * team2 = new DoubleLinkedList;
	DoubleLinkedList * loserList = new DoubleLinkedList;

	do 
	{
	 	std:: cout << "Fantasy Combat Tournament\n";

		std:: cout << "To Start Game Please Enter \n1. Play\n2. Exit\n";
		checkForOneOrTwo(startGame);

		if (startGame == 2)
		{
			break;
		}

		//Prompt User for how many player you want for Team 1
		std:: cout << "How many players do you want for Team 1?\n";
		checkForInt(numOfPlayersTeam1);
		Character *p1;

		//Loop Through and add to team1 Queue
		for (int i = 0; i < numOfPlayersTeam1; i++)
		{
			std:: cout << "For Team 1 Player " << i+1 << ":\n";
			printCharacterMenu();
			checkForCharacter1Input(player1Choice);

			if (player1Choice == 'a') { p1 = new Vampire; }
			else if (player1Choice == 'b') {p1 = new Barbarian;}
			else if (player1Choice == 'c') {p1 = new BlueMen;}
			else if (player1Choice == 'd') {p1 = new Medusa;}
			else if (player1Choice == 'e') {p1 = new HarryPotter;}

			std:: string playerName;

			std:: cout << "Enter " << p1->getType() << " name.\n";
			std:: cin >> playerName;
			p1->setName(playerName);

			team1->addNewNodeToTail(p1);
		}
			
		//Prompt Use for how many player you want for Team 2
		std:: cout << "How many players do you want for Team 2?\n";
		checkForInt(numOfPlayersTeam2);
		Character *p2;

		//Loop Through and add to team2 Queue
		for (int i = 0; i < numOfPlayersTeam2; i++)
		{
			std:: cout << "For Team 2 Player " << i+1 << ":\n";
			printCharacterMenu();
			checkForCharacter1Input(player2Choice);

			if (player2Choice == 'a') { p2 = new Vampire; }
			else if (player2Choice == 'b') {p2 = new Barbarian;}
			else if (player2Choice == 'c') {p2 = new BlueMen;}
			else if (player2Choice == 'd') {p2 = new Medusa;}
			else if (player2Choice == 'e') {p2 = new HarryPotter;}

			std:: string playerName;						
			std:: cout << "Enter " << p2->getType() << " name.\n";		//ask user to enter player/character name
			std:: cin >> playerName;
			p2->setName(playerName);

			team2->addNewNodeToTail(p2);
		}		


		while (continueRound)
			{

				std:: cout << "\nRound " << roundCounter + 1 << " Starting:\n";
				p1 = team1->getHeadNode()->getPlayer();
				p2 = team2->getHeadNode()->getPlayer();
				playRound(p1, p2);

				if ((p1->getStrength() <= 0) || (p2->getStrength() <= 0))
				{
					continueRound = false;

					//Place loser in "loser stack"
					if (p1->getStrength() <= 0)
					{
						std:: cout << p1->getName() << " has died and is being added to the loser queue\n";
						
						
						loserList->addNewNodeToTail(p1);
						team1->deleteHeadNode();
						team2Score++;			//Increment Team 2 Score Since Team 1 Player Died

						//move winner to back of list
						std:: cout << "Moving " << p2->getName() << " to back of lineup\n";
						Character * n = team2->getHeadNode()->getPlayer();
						team2->deleteHeadNode();

						
						team2->addNewNodeToTail(n);

						//Display Winner and Round
						std:: cout << "Round " << roundCounter + 1 << " : ";
						std:: cout << "Team 1 " << p1->getName() << " vs. ";
						std:: cout << "Team 2 " << p2->getName() << "\n";
						std:: cout << "Winner: Team 2 " << p2->getName() << "!!!";

						//Display Score
						std:: cout << std:: endl;
						std:: cout << "Team 1 Score: " << team1Score << std:: endl;
						std:: cout << "Team 2 Score: " << team2Score << std:: endl;
						

						if (team1->getHeadNode() == nullptr)
						{
							break;
						}
					}
					else if (p2->getStrength() <= 0)
					{
						std:: cout << p2->getName() << " has died and is being added to the loser queue\n";
						
						
						loserList->addNewNodeToTail(p2);
						team2->deleteHeadNode();
						team1Score++;			//Increment Team 1 Score Since Team 2 Player Died
						
						//move winner to back of list
						std:: cout << "Moving " << p1->getName() << " to back of lineup\n";
						Character * n = team1->getHeadNode()->getPlayer();
						team1->deleteHeadNode();

						
						team1->addNewNodeToTail(n);
						
						//Display Winner and Round
						std:: cout << "Round " << roundCounter + 1 << " : ";
						std:: cout << "Team 1 " << p1->getName() << " vs. ";
						std:: cout << "Team 2 " << p2->getName() << "\n";
						std:: cout << "Winner: Team 1 " << p1->getName() << "!!!";

						//Display Score
						std:: cout << std:: endl;
						std:: cout << "Team 1 Score: " << team1Score << std:: endl;
						std:: cout << "Team 2 Score: " << team2Score << std:: endl;

						if (team2->getHeadNode() == nullptr)
						{
							break;
						}
					}

					//Continue Fight
					p1 = team1->getHeadNode()->getPlayer();
					p2 = team2->getHeadNode()->getPlayer();

					std:: cout << std:: endl;
					std:: cout << "Player 1: " << p1->getName() << " is now fighting " << "Player 2: " << p2->getName();
					std:: cout << std:: endl;
				}

				// std:: cout << "To Continue Round Please Enter \n1. Continue\n2. Exit\n";
				// checkForOneOrTwo(startGame);
				if (startGame == 1)
				{
					continueRound = true;
				}
				else if (startGame == 2)
				{
					continueRound = false;
				}

				//Increment Round Counter
				roundCounter++;
			}

			//Ask User to See the Loser List
			std:: cout << "Combat is over. Do You want to see the Loser List?\n1. Yes\n2. No\n";
			checkForOneOrTwo(viewLoserList);
			if (viewLoserList)
			{
				std:: cout << "Loser List: ";
				loserList->traverseListBackToFront();
				std:: cout << std:: endl;
			}

			if (team1Score > team2Score)
			{
				std:: cout << "Team 1 is the Winner\n";
			}
			
			else if (team2Score > team1Score)
			{
				std:: cout << "Team 2 is the Winner\n";
			}
			else if (team1Score == team2Score)
			{
				std:: cout << "Team 1 and Team 2 Tie\n";
			}
			

			std:: cout << "Combat is over.\n1. Play Again\n2. Exit Game\n";
			checkForOneOrTwo(playAgain);
			if (playAgain == 1)
			{
				gameStatus = true;
				continueRound = true;
				team1Score = 0;
				team2Score = 0;
				while (loserList->getHeadNode() != nullptr)
				{
					loserList->deleteHeadNode();
				}
				while (team1->getHeadNode() != nullptr)
				{
					team1->deleteHeadNode();
				}
				while (team2->getHeadNode() != nullptr)
				{
					team2->deleteHeadNode();
				}

			}
			else
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

//Input Validation for Character
void checkForCharacter1Input(char &input)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		std:: cin >> input;
		//Create Vampire
		if (input == 'a')
		{
			break;
		}
		//Create Barbarian
		else if (input == 'b')
		{
			break;
		}
		//Create BlueMen
		else if (input == 'c')
		{
			break;
		}
		//Create Medusa
		else if (input == 'd')
		{
			break;
		}
		//Create Harry Potter
		else if (input == 'e')
		{
			break;
		}
		else
		{
			invalidInput = true;
			std:: cout << "Please enter either \'a\' or \'b\' or \'c\' or \'d\' or \'e\' \n";
			std:: cin.clear();
			std:: cin.ignore();
		}
	} while(invalidInput);

	std:: cout << std::endl;
}
//Input Validation for Character
void checkForCharacter2Input(char &input)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		std:: cin >> input;
		//Create Vampire
		if (input == 'a')
		{
			break;
		}
		//Create Barbarian
		else if (input == 'b')
		{
			break;
		}
		//Create BlueMen
		else if (input == 'c')
		{
			break;
		}
		//Create Medusa
		else if (input == 'd')
		{
			break;
		}
		//Create Harry Potter
		else if (input == 'e')
		{
			break;
		}
		else
		{
			invalidInput = true;
			std:: cout << "Please enter either \'a\' or \'b\' or \'c\' or \'d\' or \'e\' \n";
			std:: cin.clear();
			std:: cin.ignore();
		}
	} while(invalidInput);

	std:: cout << std::endl;
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

//Input Validation for Integer
void checkForOneOrTwo(int &input)
{
	bool invalidInput;
	do
	{
		invalidInput = false;
		std:: cin >> input;
		if (input == 1)
		{
			break;
		}
		else if (input == 2)
		{
			break;
		}
		else
		{
			invalidInput = true;
			std:: cout << "Please enter either \'1\' or \'2\' \n";
			std:: cin.clear();
			std:: cin.ignore();
		}
	} while(invalidInput);
}


//Character Menu Print
void printCharacterMenu()
{
	std:: cout << "Enter the corresponding letter for what Character you want\n";
	std:: cout << "a. Vampire\n";
	std:: cout << "b. Barbarian\n";
	std:: cout << "c. Blue Men\n";
	std:: cout << "d. Medusa\n";
	std:: cout << "e. Harry Potter\n";
}



