#include "player.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Play {
	int checkedCellCount;
	vector<vector<string>> board{0};
	pair<int, int> nextOption;
	Player A;
	Player B;

	void getNextOption();
	bool isValid();
	void printBoard();
	Player checkWinnner();
	bool checkGameEnd();
	void run();
	void MarkInBoard();
	void switchPlayer();
public:
	Play();
};