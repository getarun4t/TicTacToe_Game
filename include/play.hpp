#ifndef PLAY_HPP
#define PLAY_HPP

#include "player.hpp"
#include <iostream>
#include <vector>
#include <string>

class Play {
	int checkedCellCount;
	std::vector<std::vector<std::string>> board;
	std::pair<int, int> nextOption;
	Player A;
	Player B;

	void getNextOption();
	bool isValid(int coordinate_x, int coordinate_y);
	void printBoard();
	Player checkWinner();
	bool checkGameEnd();
	void markInBoard();
	void switchPlayer();

public:
	Play();
	void run();
};

#endif // PLAY_HPP
