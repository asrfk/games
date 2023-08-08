#pragma once
#include <vector>
#include <iostream>
#include <string>
using namespace std;

struct card {
	char suit;
	string printout;
	int face;
	bool isAceLow;
};


int Convert(vector<card>hand,int total) {
	bool one=false;
	int store;
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].face == 11){
			one = true;
			store = i;
		}
	}
	if (one == true) {
		if (total > 21) {
			hand[store].face = 1;
			total -= 10;
		}
	}

	return total;
}

int CompTurn(vector<card>chand, vector<card>theDeck, int ctotal) {
	//computes computer hand (first 2)
	cout << "The Computers hand: " << endl;

	for (size_t i = 0; i < chand.size(); i++) {
		cout << chand[i].suit << " "<< chand[i].printout<<endl;
		ctotal += chand[i].face;
	}

	while (ctotal <= 17) {
		chand.push_back(theDeck[0]);
		theDeck.erase(theDeck.begin());
		ctotal += chand.back().face;
		ctotal = Convert(chand, ctotal);
		cout << chand.back().suit << " " << chand.back().printout << endl;

	}
	cout << "The Computers total" << endl;
	cout << ctotal << endl;

	return ctotal;
}

void BJ() {
	string again;
	while (again != "N") {
		string hit;
		vector<card> theDeck, uhand, chand;
		card tempCard;
		int count = 0, randPos, utotal = 0, ctotal = 0;
		char suits[4] = { '\x04','\x05','\x06','\x03' };

	


		//creates new Deck when started again
		theDeck.clear();
		uhand.clear();
		chand.clear();
		again = "Y";

		//generates deck
		for (int i = 0; i < 4; i++) {
			tempCard.suit = suits[i];
			for (int j = 0; j < 13; j++) {
				tempCard.face = j + 2;

				tempCard.printout = to_string(j + 2);
				//allows for royals
				if (j + 2 > 11)
				{
					tempCard.face = 10;
					if (j + 2 == 12) {
						tempCard.printout = "J";
					}
					else if (j + 2 == 13) {
						tempCard.printout = "Q";
					}

					else if (j + 2 == 14) {
						tempCard.printout = "K";
					}
				}
				if (j + 2 == 11) {
					tempCard.printout = "A";
				}

				theDeck.push_back(tempCard);
			}

		}
		//shuffles Deck
		srand(time(0));
		for (int i = 0; i < theDeck.size(); i++) {
			randPos = rand() % (theDeck.size() - 1);
			tempCard = theDeck[randPos];
			theDeck[randPos] = theDeck[i];
			theDeck[i] = tempCard;
		}

		cout << "Your hand is: " << endl;
		for (int i = 0; i < 2; i++) {
			uhand.push_back(theDeck[0]);
			theDeck.erase(theDeck.begin());
			chand.push_back(theDeck[0]);
			theDeck.erase(theDeck.begin());
		}


		while (utotal < 21 && hit != "N") {

			//displays users hand
			for (int i = 0; i < uhand.size(); i++) {

				cout << uhand[i].suit << " " << uhand[i].printout;
				cout << endl;

				utotal += uhand[i].face;
			}

			//check over 21
			utotal = Convert(uhand, utotal);

			if (utotal > 21) {
				break;
			}

			cout << "Total " << utotal << endl;

			//start of the rest of the game
			cout << "Hit? Y/N";
			cin >> hit;

			//user dealt one card at a time
			if (hit != "N") {
				for (int i = 0; i < theDeck.size(); i++) {
					uhand.push_back(theDeck[0]);
					theDeck.erase(theDeck.begin());
					utotal = 0;
					for (int i = 0; i < uhand.size(); i++) {
						cout << uhand[i].suit << " " << uhand[i].printout << endl;
						utotal += uhand[i].face;
					}
					utotal = Convert(uhand, utotal);
					cout << "Total " << utotal << endl << endl;

					if (utotal >= 21) {
						break;
					}

					else {
						cout << "Hit? (Y/N)" << endl;
						cin >> hit;
						if (hit == "N") {
							break;
						}
					}
				}

			}
		}


		if (utotal == 21) {
			cout << "YOU WIN" << endl << endl;
		}
		else if (utotal > 21) {
			cout << "YOU LOSE" << endl << endl;
		}

		else {

			ctotal = CompTurn(chand, theDeck, ctotal);
			if (ctotal >= utotal && ctotal <= 21) {
				cout << "The computer wins" << endl;
			}
			else {
				cout << "YOU WIN" << endl;
			}
		}
		ctotal = 0;
		utotal = 0;
		cout << "Play Again? (Y/N):" << endl;
		cin >> again;
	}
}