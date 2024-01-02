#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>

class Player {
	bool my_turn;

public:
	bool getTurn();
	void setTurn();
	void resetTurn();

	Player();
};

#endif // PLAYER_HPP