#ifndef PLAY_HPP
#define PLAY_HPP

#include "player.hpp"
#include <iostream>
#include <vector>
#include <string>

class Play {
	int checkedCellCount;
	std::pair<int, int> nextOption;
	Player A;
	Player B;

	void getNextOption();
	bool isEmpty(int coordinate_x, int coordinate_y);
	void printBoard();
	void markInBoard();
	void switchPlayer();
	int requestCoordinates(std::string axes);

public:
	Play();
	void run();
	bool checkGameEnd();
	std::vector<std::vector<std::string>> board;
};

#endif // PLAY_HPP
