#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void Hang(){
	ifstream inFile; //Reads File
	inFile.open("wordList.txt");
	vector <string> wordlist,letters,dash;
	string thisWord, keyword, guess, temp,again;
	int randomIndex, wlen = 0, wrong = 0,correct=0;
	
	srand(time(0));
	while (again != "N") {
		while (inFile >> thisWord) {
			wordlist.push_back(thisWord);
		}
		for (int i = 0; i < 1; i++) { //Outputs random word for game
			randomIndex = rand() % wordlist.size();
			keyword = wordlist[randomIndex];
		}
		wlen = keyword.size();//count letters in word

		for (int i = 0; i < wlen; i++) {
			dash.push_back("-");
		}

		for (int i = 0; i < wlen; i++) {
			temp = tolower(keyword[i]);
			letters.push_back(temp);
		}

		//Start of game


		cout << "There are " << wlen << " letters in your word" << endl;
		cout << keyword << endl;

		while (wrong != 5 && correct != wlen) {
			cout << "Your word is: " << endl;
			for (int i = 0; i < wlen; i++) {
				cout << dash[i];
			}

			cout << endl << endl;

			cout << "Enter your guess: " << endl;
			cin >> guess;
			if (keyword.find(guess) != string::npos) {
				cout << "Yes there is a: " << guess << endl;
				for (int i = 0; i < wlen; i++) {
					if (letters[i] == guess) {
						dash[i] = guess;
						correct += 1;
					}
				}


			}
			else {
				cout << "wrong" << endl;
				wrong += 1;

			}
		}
		dash.clear();
		if (wrong == 5) {
			cout << "YOU LOSE" << endl;
		}
		if (correct == wlen) {
			cout << "YOU WIN" << endl;

		}
		
		for (int i = 0; i < wlen; i++) {
			dash.push_back("-");
		}

		cout << "would you like to play again? Y/N" << endl;
		cin >> again;

	}
}

