#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
string PrintGuess(string Guess);
bool AskToPlayAgain();


// The entry point for our application.
int main()
{
	PrintIntro();
	bool bPlayAgain = false;
	do {
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; // Exit the application.
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


void PlayGame() {
	// Loop for the number of turns for the number of guesses.
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string Guess = GetGuess();
		PrintGuess(Guess);
	}
}


// Get the guess from the player.
string GetGuess() {
	cout << "Please enter a guess: ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}


// Prints the guess back to the player.
string PrintGuess(string Guess) {
	cout << "Your guess was: " << Guess << endl << endl;

	return Guess;
}


bool AskToPlayAgain()
{
	cout << "Do you want to play again (y/n)?" << endl;
	string Response = "";
	getline(cin,Response);
	cout << endl;

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
