#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;

//Pre:Nothing 
//Post:makes a struct called cards
struct cards {
	char suit;
	string printout;
	int face;
};

//Pre:
//Post: outputs face and suit
void pHand(vector<cards>hand) {
	for (int i = 0; i < hand.size(); i++)
	{
		cout << hand[i].suit << " " << hand[i].printout << " ";
	}
	cout << endl;
}


int War() {
	string hit, again;
	vector<cards> Deck, uhand, chand,Hold;
	cards tempCard, pc, cc;
	bool holdcheck = false, war2=false;
	int randPos, utotal = 0, ctotal = 0;
	char suits[4] = { '\x04','\x05','\x06','\x03' };

	while (again != "N")
	{


		//creates new Deck when started again
		Deck.clear();
		uhand.clear();
		chand.clear();

		//generates deck
		for (int i = 0; i < 4; i++) {
			tempCard.suit = suits[i];
			for (int j = 0; j < 13; j++) {
				tempCard.face = j + 2;

				tempCard.printout = to_string(j + 2);
				//allows for royals
				if (j + 2 > 11)
				{
					if (j + 2 == 12) {
						tempCard.printout = "Q";
					}
					else if (j + 2 == 13) {
						tempCard.printout = "K";
					}

					else if (j + 2 == 14) {
						tempCard.printout = "A";//highest card
					}
				}
				if (j + 2 == 11) {
					tempCard.printout = "J";
				}

				Deck.push_back(tempCard);
			}

		}
		//shuffles Deck
		srand(time(0));
		for (int i = 0; i < Deck.size(); i++) {
			randPos = rand() % (Deck.size() - 1);
			tempCard = Deck[randPos];
			Deck[randPos] = Deck[i];
			Deck[i] = tempCard;
		}


		//Splits the Deck
		for (int i = 0; i < Deck.size(); i++) {
			uhand.push_back(Deck[0]);
			Deck.erase(Deck.begin());
		}
		chand = Deck;

		//start of the game
		cout << "WELCOME TO WAR" << endl << endl;
		while (chand.size() > 10 && uhand.size() > 10) {


			cout << endl << "Player: " << endl;
			pc = uhand[0];
			pHand(uhand);




			cout << endl << "Computer: " << endl;
			cc = chand[0];
			pHand(chand);


			cout << endl << "Hold: " << endl;
			pHand(Hold);


			cout << "Your Hand: " << uhand.size() << "                      " << "Computer Hand: " << chand.size() << "                      " << "Hold: " << Hold.size() << endl;
			cout << "Player Card: " << pc.suit << " " << pc.printout << "                   " << "Computer Card: " << cc.suit << " " << cc.printout << endl;
			chand.erase(chand.begin());
			uhand.erase(uhand.begin());

			cout << endl << "--------------------------------------------------------------" << endl;//spacing

			Hold.push_back(pc);
			Hold.push_back(cc);
			while (Hold.size() > 0) {

				//if user wins
				if (pc.face > cc.face) {
					uhand.push_back(Hold[0]);
					Hold.erase(Hold.begin());

				}
				//if computer wins
				else if (pc.face < cc.face)
				{
					chand.push_back(Hold[0]);
					Hold.erase(Hold.begin());

				}
				//tie
				else {
					for (int i = 0; i < 3; i++)
					{
						Hold.push_back(uhand[0]);
						Hold.push_back(chand[0]);
						uhand.erase(uhand.begin());
						chand.erase(chand.begin());
						holdcheck = true;
					}
					break;
				}
			}
		}


		cout << endl << endl;

		cout << endl << "Player: " << endl;
		pHand(uhand);
		cout << endl << "Computer: " << endl;
		pHand(chand);

		cout << endl << endl;
		cout << "Your Hand: " << uhand.size() << "                      " << "Computer Hand: " << chand.size() << "                      " << "Hold: " << Hold.size() << endl;
		cout << "Player Card: " << uhand[0].suit << " " << uhand[0].printout << "                   " << "Computer Card: " << chand[0].suit << " " << chand[0].printout << endl;

		//decides winner
		if (uhand.size() > 10) {
			cout << "YOU WIN" << endl << endl;
		}
		else
		{
			cout << "YOU LOSE" << endl << endl;
		}
		cout << "Play Again? (Y/N)" << endl;
		cin >> again;
	}
	
	return 0;
}
