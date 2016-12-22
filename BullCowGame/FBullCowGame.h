/* The game logic. No view code or direct user interaction.
   The game is a simple guess-the-word game based on Mastermind. 
*/

#pragma once

#include <string>

// To make syntax Unreal-friendly.
using FString = std::string;
using int32 = int;
using uint32 = unsigned int;


// All values initialized to zero.
struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};


enum class EGuessStatus {
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};


class FBullCowGame {

public:
	FBullCowGame(); // Constructor.
	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon(FBullCowCount BullCowCount) const;
	EGuessStatus CheckGuessValidity(FString Guess) const;

	void Reset();


	// Counts bulls & cows and increases try #, assuming guess is valid.
	FBullCowCount SubmitValidGuess(FString Guess);

private:
	// See constructor for initialization.
	int32 MyCurrentTry;
	FString MyHiddenWord;

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;

};
