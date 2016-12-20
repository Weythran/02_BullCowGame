#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

// Receives a valid guess, increments turn, and returns count.
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// Increment the turn number.
	MyCurrentTry++;

	// Set up a return variable.
	BullCowCount BullCowCount;

	// Loop through all letters in the guess.
		// Compare letters against the hidden word.
	return BullCowCount;
}
