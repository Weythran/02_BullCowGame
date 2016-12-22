#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;
using uint32 = unsigned int;


FBullCowGame::FBullCowGame() { Reset(); }


void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "dog";

	MyCurrentTry = 1;
	MyHiddenWord = HIDDEN_WORD;
	
	return;
}


int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }


int32 FBullCowGame::GetMaxTries() const 
{ 
	TMap<int32, int32>WordLengthToMaxTries
	{ 
		{1,3}, {2,3}, {3,4}, {4,6}, {5,8}, {6,9}, {7,11}, {8,14}, {9,20}, {10,20}
	};
	return WordLengthToMaxTries[MyHiddenWord.length()];
}


bool FBullCowGame::IsGameWon(FBullCowCount BullCowCount) const
{
	return (BullCowCount.Bulls == MyHiddenWord.length());
}


bool FBullCowGame::IsIsogram(FString Guess) const
{
	// Treat 0- or 1-letter words as isograms.
	if (Guess.length() < 2) { return true; }

	TMap <char, bool> LetterSeen; // Declare our map.
	for (char Letter : Guess) // For every letter in the guess word...
	{
		Letter = tolower(Letter); // To be able to handle mixed case.
		if (LetterSeen[Letter]) // If a letter is on the map...
		{
			return false; // We don't have an isogram.
		}
		else 
		{
			LetterSeen[Letter] = true; // Add letter to the map as seen.
		}
	}
	return true;
}


bool FBullCowGame::IsLowercase(FString Guess) const
{
	// Treat 0-letter words as lowercase.
	if ((Guess.length() < 1)) { return true; }
	
	for (char Letter : Guess)
	{
		if (!islower(Letter))
		{
			return false; // The guess is not all-lowercase.
		}
	}
	return true;
}


EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	// If the guess isn't an isogram, return an error.
	if (!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}
	// If the guess isn't all lowercase, return an error.
	else if (!IsLowercase(Guess))
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


// Receives a valid guess, increments turn, returns count.
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
