#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
	srand(time(0)); 
	string choices[] = { "rock", "paper", "scissors" };

	int playerChoice, computerChoice;
	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "Enter 0 for Rock, 1 for Paper, or 2 for Scissors: ";

	cin >> playerChoice;

	if (playerChoice < 0 || playerChoice > 2) {
		cout << "Invalid choice. Please enter 0, 1, or 2." << endl;
		return 1;
	}

	computerChoice = rand() % 3; 

	cout << "you chose: " << choices[playerChoice] << endl;
	cout << "computer chose: " << choices[computerChoice] << endl;

	if (playerChoice == computerChoice) {
		cout << "It's a tie!" << endl;
	}
	else if ((playerChoice == 0 && computerChoice == 2) ||
		(playerChoice == 1 && computerChoice == 0) ||
		(playerChoice == 2 && computerChoice == 1)) {
		cout << "You win!" << endl;
	}
	else {
		cout << "Computer wins!" << endl;
	}

	return 0;

}
