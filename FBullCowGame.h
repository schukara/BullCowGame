/* The game logic (no view code or direct user interaction)
The game is a simple guess the word game based on Mastermind.
*/

#pragma once

#include <string>

// to make syntax Unreal friendly
using Fstring = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase,
};

class FBullCowGame
{
	public:
		FBullCowGame(); // constructor

		int32 GetMaxTries() const;
		int32 GetCurrentTry() const;
		int32 GetHiddenWordLength() const;
		bool IsGameWon() const;
		EGuessStatus CheckGuessValidity(Fstring) const;

		void Reset();
		FBullCowCount SubmitValidGuess(Fstring);


	// Please try and grnore this and focus on the interface above ^^
	private:
		// see constructor for initialisation
		int32 MyCurrentTry;
		Fstring MyHiddenWord;
		bool bGameIsWon;

		bool IsIsogram(Fstring) const;
		bool IsLowercase(Fstring) const;
};