#include "FBullCowGame.h"

using FString = std::string;
using int32 = int;
using uint32 = unsigned int;

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

bool FBullCowGame::IsGameWon(FBullCowCount BullCowCount) const
{
	return (BullCowCount.Bulls == MyHiddenWord.length());
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


// Receives a valid guess, increments turn, returns count, and checks for win condition.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	// Set up a return variable.
	FBullCowCount BullCowCount;

	// Loop through all letters in the hidden word.
	for (uint32 i = 0; i < MyHiddenWord.length(); i++)
	{
		// Loop through all letters in the valid guess.
		for (uint32 j = 0; j < Guess.length(); j++)
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
