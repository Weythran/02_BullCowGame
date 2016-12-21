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
bool AskToPlayAgain();
FBullCowCount PrintBullCowCount(FBullCowCount BullCowCount);
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
	if (BCGame.GetHiddenWordLength() < 10)
	{
		std::cout << "#######################################################" << std::endl;
		std::cout << "#     Welcome to Bulls and Cows, a fun word game!     #" << std::endl;
		std::cout << "#                                                     #" << std::endl;
		std::cout << "# Can you guess the " << BCGame.GetHiddenWordLength() << "-letter isogram I'm thinking of? #" << std::endl;
		std::cout << "#######################################################" << std::endl << std::endl;
	}
	else 
	{
		std::cout << "########################################################" << std::endl;
		std::cout << "#     Welcome to Bulls and Cows, a fun word game!      #" << std::endl;
		std::cout << "#                                                      #" << std::endl;
		std::cout << "# Can you guess the " << BCGame.GetHiddenWordLength() << "-letter isogram I'm thinking of? #" << std::endl;
		std::cout << "########################################################" << std::endl << std::endl;
	}

	return;
}


void PlayGame() {
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// Loop for the number of turns for the number of guesses.
	// TODO Change from FOR to WHILE loop once we're validating tries.
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess();
		EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

		// Submit valid guess to the game and receive bulls & cows counts.
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// Print number of bulls and cows.
		PrintBullCowCount(BullCowCount);
	}
}


// Get the guess from the player.
FText GetGuess() { // TODO Change to GetValidGuess().
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


FBullCowCount PrintBullCowCount(FBullCowCount BullCowCount)
{
	std::cout << "Your score is: bulls - " << BullCowCount.Bulls;
	std::cout << "; cows - " << BullCowCount.Cows << ".";
	std::cout << std::endl << std::endl;

	return BullCowCount;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again (y/n)?" << std::endl;
	FText Response = "";
	getline(std::cin,Response);
	std::cout << std::endl;

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
