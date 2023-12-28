#include <iostream>
#include <vector>

using namespace std;

class Play {
	int checkedCellCount;
	vector<vector<int>> board{0};

	pair<int, int> getNextOption();
	bool isValid();
	void printBoard(board);
	Player checkWinnner();
	bool checkGameEnd();
};