#include "main.h"

int main() {
	// :)
}

int checkInput(char* in) {  // Returns 0 if the input is valid, 1 otheriwse 
	if (in != "Rock" && in != "Paper" && in != "Scissors"){
		return 1;
	}
	return 0;
}

char* runGame(char* p1, char* p2) {

	// Checks for valid inputs
	if (checkInput(p1) + checkInput(p2) != 0) {
		return "Invalid input";
	}

	// Checks for draw
	if (p1 == p2) {
		return "Draw";
	}

	if (p1 == "Rock") {
		if (p2 == "Paper") {
			return "Player2";
		} 
		return "Player1";
	}

	if (p1 == "Paper") {
		if (p2 == "Scissors") {
			return "Player2";
		}
		return "Player1";
	}

	if (p1 == "Scissors") {
		if (p2 == "Rock") {
			return "Player2";
		}
		return "Player1";
	}

}