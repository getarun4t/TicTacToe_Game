#include <iostream>

using namespace std;

class Player {
	bool my_turn;

public:
	bool getTurn() {
		return my_turn;
	}

	void setTurn() {
		my_turn = true;
	}

	void resetTurn() {
		my_turn = false;
	}

	Player() {
		my_turn{ false };
	}
};