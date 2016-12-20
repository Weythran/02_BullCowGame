#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
std::string PrintGuess(std::string Guess);
bool AskToPlayAgain();
FBullCowGame BCGame; // Instantiate a new game.


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
	std::cout << "#######################################################" << std::endl;
	std::cout << "#     Welcome to Bulls and Cows, a fun word game!     #" << std::endl;
	std::cout << "#                                                     #" << std::endl;
	std::cout << "# Can you guess the " << WORD_LENGTH << "-letter isogram I'm thinking of? #" << std::endl;
	std::cout << "#######################################################" << std::endl << std::endl;

	return;
}


void PlayGame() {
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	std::cout << MaxTries << std::endl;

	// Loop for the number of turns for the number of guesses.
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess();
		PrintGuess(Guess);
	}
}


// Get the guess from the player.
std::string GetGuess() {
	int CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Please enter a guess: ";
	std::string Guess = "";
	getline(std::cin, Guess);

	return Guess;
}


// Prints the guess back to the player.
std::string PrintGuess(std::string Guess) {
	std::cout << "Your guess was: " << Guess << std::endl << std::endl;

	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?" << std::endl;
	std::string Response = "";
	getline(std::cin,Response);
	std::cout << std::endl;

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}

