/* This is the console executable that makes use of the BullCowGame class.
   This acts as the view in MVC pattern and is responsible for all user
   interaction. For game logic, see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;
using uint32 = unsigned int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
FBullCowCount PrintBullCowCount(FBullCowCount BullCowCount);
FBullCowGame BCGame; // Instantiate a new game.


// The entry point for our application.
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
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
	FBullCowCount BullCowCount;

	// Loop asking for guesses while the game is not won and there are still tries remaining.
	do {
		FText Guess = GetValidGuess();

		// Submit valid guess to the game and receive bulls & cows counts.
		BullCowCount = BCGame.SubmitValidGuess(Guess);
		// Print number of bulls and cows.
		PrintBullCowCount(BullCowCount);
		
		if (BCGame.IsGameWon(BullCowCount) && (BCGame.GetHiddenWordLength() < 10))
		{
			std::cout << "###########################################################" << std::endl;
			std::cout << "#                                                         #" << std::endl;
			std::cout << "# CONGRATULATIONS! You have guessed the " << BCGame.GetHiddenWordLength();
			std::cout << "-letter isogram! #" << std::endl;
			std::cout << "#                                                         #" << std::endl;
			std::cout << "###########################################################" << std::endl << std::endl;
		}
		else if (BCGame.IsGameWon(BullCowCount) && (BCGame.GetHiddenWordLength() >= 10))
		{
			std::cout << "############################################################" << std::endl;
			std::cout << "#                                                          #" << std::endl;
			std::cout << "# CONGRATULATIONS! You have guessed the " << BCGame.GetHiddenWordLength();
			std::cout << "-letter isogram! #" << std::endl;
			std::cout << "#                                                          #" << std::endl;
			std::cout << "############################################################" << std::endl << std::endl;
		}
	} while ((BCGame.GetCurrentTry() <= MaxTries) && (!BCGame.IsGameWon(BullCowCount)));
}


// Loop continually until the user gives a valid guess.
FText GetValidGuess() {
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";

	do
	{
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Please enter a guess: ";
		getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << "-letter word..." << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters..." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter a lower-case word..." << std::endl;
			break;
		case EGuessStatus::Invalid_Status:
			std::cout << "ERROR: EGuessStatus::Invalid_Status received in BCGame.GetValidGuess()! ###" << std::endl;
			break;
		default:
			// Assume the guess is valid.
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);

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
	std::cout << "Would you like to play again (y/n)?" << std::endl;
	FText Response = "";
	getline(std::cin,Response);
	std::cout << std::endl;

	return ((Response[0] == 'y') || (Response[0] == 'Y'));
}
