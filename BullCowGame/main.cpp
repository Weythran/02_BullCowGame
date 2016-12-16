#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();

// The entry point for our application.
int main()
{
	PrintIntro();
	PlayGame();
	AskToPlayAgain();

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
		// Prints the guess back to the player.
		cout << "Your guess was: " << Guess << endl << endl;
	}
}


// Get the guess from the player.
string GetGuess() {
	cout << "Please enter a guess: ";
	string Guess = "";
	getline(cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again? " << endl;
	string Response = "";
	getline(cin,Response);

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
