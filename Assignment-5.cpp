// Blake Bartenbach
// INFO 1522 SN
// Assignment 5 - Guessing Game
// A simple console guessing game

#include <iostream>
#include <random>
#include <ctime>
#include <cmath>
#include <string>

using namespace std;

int selectNumber();
int getGuess();
void evaluateGuess(int number, int guess);
void evaluateRound(int count);
bool playAgain();

int main() {
    
	int number;   // Number selected by this program
	int guess;    // Number guessed by the user
	int count;    // Number of tries to guess

	srand(time(static_cast<time_t>(0)));  // Randomize the random number generator

	do {
		count = 0;
		number = selectNumber();
		cout << "I have a number between 1 and 1000.\nCan you guess my number ? \nPlease enter your first guess : ";

		while (number != (guess = getGuess())) {
			evaluateGuess(number, guess);
			count++;
		}
		evaluateRound(count);

	} while (playAgain());
	return 0;
}

// Returns a random number between 1 and 1000
int selectNumber() {
	return ((rand() % 1000) + 1);
}

// Returns the user's guessed integer
int getGuess() {
	int guess;
	cin >> guess;
	return guess;
}

// Evalutes the incorrect guess
void evaluateGuess(int number, int guess) {
	if (guess < number) {
		cout << "Too low. Try Again: ";
	} else {
		cout << "Too high. Try Again: ";
	}
}

// Evaluates how many guesses it took the user
void evaluateRound(int count) {
	cout << "\nExcellent!  You guessed the number!" << endl;
	if (count == 1) {
		cout << "Cheater!" << endl;
	} else if (count <= 10) {
		cout << "Lucky guessing!" << endl;
	} else {
		cout << "I bet I could do better than that!" << endl;
	}
}

// Asks the user if they would like to play again
bool playAgain() {
	cout << "\nWould you like to play again (y or n)? ";
	string play;
	cin >> play;
	if (play == "y") {
		cout << "\n";
		return true;
	}
	return false;
}