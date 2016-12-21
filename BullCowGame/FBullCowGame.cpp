#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;

	return;
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const
{
	return false;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// If the guess isn't an isogram, return an error.
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	// If the guess isn't all lowercase, return an error.
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	// If the guess length is wrong, return an error.
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	// Otherwise, return OK.
	else
	{
		return EGuessStatus::OK;
	}
}


// Receives a valid guess, increments turn, and returns count.
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// Increment the turn number.
	MyCurrentTry++;

	// Set up a return variable.
	FBullCowCount BullCowCount;

	// Loop through all letters in the guess.
	for (int32 i = 0; i < MyHiddenWord.length(); i++)
	{
		for (int32 j = 0; j < Guess.length(); j++)
		{
			// Compare letters against the hidden word.
			if ((MyHiddenWord[i]==Guess[j])&&(i==j)) // If they match in the same place.
			{
				BullCowCount.Bulls++;
			}
			else if ((MyHiddenWord[i] == Guess[j]) && (i != j)) // If they match no in the same place.
			{
				BullCowCount.Cows++;
			}
		}
	}

	return BullCowCount;
}
