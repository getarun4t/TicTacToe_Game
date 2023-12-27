#include <iostream>
#include <vector>

using namespace std;

class Play {
	vector<vector<int>> board{0};

	pair<int, int> getNextOption();
	bool isValid();
	void printBoard();
	Player checkWinnner();
	bool checkGameEnd();
};