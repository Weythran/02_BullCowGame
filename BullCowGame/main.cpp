#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuessAndPrintBack();

// The entry point for our application.
int main()
{
	PrintIntro();
	GetGuessAndPrintBack();
	GetGuessAndPrintBack();

	return 0;
}

// Introduce the game.
void PrintIntro() {
	constexpr int WORD_LENGTH = 5;
	cout << "#######################################################" << endl;
	cout << "#     Welcome to Bulls and Cows, a fun word game!     #" << endl;
	cout << "#                                                     #" << endl;
	cout << "# Can you guess the " << WORD_LENGTH << "-letter isogram I'm thinking of? #" << endl;
	cout << "#######################################################" << endl << endl;

	return;
}

// Get the guess from the player.
string GetGuessAndPrintBack() {
	cout << "Please enter a guess: ";
	string Guess = "";
	getline(cin, Guess);
	cout << endl;

	// Prints the guess back to the player.
	cout << "Your guess was: " << Guess << endl << endl;

	return Guess;
}