#pragma once

class FBullCowGame {

public:
	void Reset(); // TODO Make a more rich return value.
	int GetMaxTries(); 
	void GetCurrentTry();
	bool IsGameWon();

/*	bool CheckGuessValidity(string); // TODO Make a more rich return value.
	bool IsIsogram();
	int GetWordLength();
	int GetCows();
	int GetBulls();
*/

private:
	int MyCurrentTry;
	int MyMaxTries;

};