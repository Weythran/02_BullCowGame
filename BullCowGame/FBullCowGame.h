#pragma once
#include <string>

class FBullCowGame {

public:
	void Reset(); // TODO Make a more rich return value.
	int GetMaxTries(); 
	void GetCurrentTry();
	bool IsGameWon();
	bool CheckGuessValidity(std::string); // TODO Make a more rich return value.

private:
	int MyCurrentTry;
	int MyMaxTries;

};