/* This is the console executable that makes use of the BullCowGame class.
   This acts as the view in MVC pattern and is responsible for all user
   interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
FText PrintGuess(FText Guess);
bool AskToPlayAgain();
FBullCowGame BCGame; // Instantiate a new game.


// The entry point for our application.
int main()
{
	PrintIntro();
	bool bPlayAgain = false;
	do {
		PlayGame();
		// TODO Add a gameplay summary.
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0; // Exit the application.
}


// Introduce the game.
void PrintIntro() {
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "#######################################################" << std::endl;
	std::cout << "#     Welcome to Bulls and Cows, a fun word game!     #" << std::endl;
	std::cout << "#                                                     #" << std::endl;
	std::cout << "# Can you guess the " << WORD_LENGTH << "-letter isogram I'm thinking of? #" << std::endl;
	std::cout << "#######################################################" << std::endl << std::endl;

	return;
}


void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// Loop for the number of turns for the number of guesses.
	// TODO Change from FOR to WHILE loop once we're validating tries.
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); // TODO Check for guess validity.

		// Submit valid guess to the game.
		// Print number of bulls and cows.
		PrintGuess(Guess);
	}
}


// Get the guess from the player.
FText GetGuess() {
	int32 CurrentTry = BCGame.GetCurrentTry();
	std::cout << "Try " << CurrentTry << ". Please enter a guess: ";
	FText Guess = "";
	getline(std::cin, Guess);

	return Guess;
}


// Prints the guess back to the player.
FText PrintGuess(FText Guess) {
	std::cout << "Your guess was: " << Guess << std::endl << std::endl;

	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?" << std::endl;
	FText Response = "";
	getline(std::cin,Response);
	std::cout << std::endl;

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}

