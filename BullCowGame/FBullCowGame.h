#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values initialized to zero.
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

public:
	FBullCowGame(); // Constructor.
	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO Make a more rich return value.
	bool CheckGuessValidity(FString); // TODO Make a more rich return value.

	// Counts bulls & cows and increases try #, assuming guess is valid.
	FBullCowCount SubmitGuess(FString Guess);

private:
	// See constructor for initialization.
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;

};