#include "\include\play.hpp"

void Play::getNextOption() {
	do {
		cout << "Enter the x co-ordinates" << endl;
		cin >> nextOption.first;
		cout << "Enter the y co-ordinates" << endl;
		cin >> nextOption.second;
	} while (Play::isValid(nextOption.first) && Play::isValid(nextOption.second));
}

bool Play::isValid(int coordinate) {
	if (Play::board[coordinate] == 0 && coordinate < 3) {
		Play::board[coordinate] == 1;
	}
	else {
		cout << "Invalid Input ! Re-try with a valid input !! "
			return false;
	}
	return true;
}

void Play::printBoard() {
	cout << endl;
	cout << "Current board is below" << endl;
	for (auto y : board) {
		for (auto x : y) {
			cout << "| ";
			if (x) {
				if (x == 1)
					cout << "X";
				else
					cout << "O";
			}
			else {
				cout << " ";
			}
			cout << " |" << endl;
		}
		cout << endl;
		cout << " ____________" << endl;
		cout << endl;
	}
}

void Play::MarkInBoard() {
	if (A.getTurn)
		board[nextOption.first][nextOption.second] == 1;
	else
		board[nextOption.first][nextOption.second] == 2;
}

void Play::switchPlayer() {
	if (!A.getTurn) {
		A.setTurn();
		B.resetTurn();
	}
	else {
		B.setTurn();
		A.resetTurn();
	}
}

Play::Play() {
	checkedCellCount = 0;
	board = vector<vector<int>>(3, vector<int>(3, 0));
}

void Play::run() {
	do {
		switchPlayer();
		printBoard();
		getNextoption();
		MarkInBoard();
	} while (checkGameEnd());
}

bool Play::checkGameEnd() {
	if (checkedCellCount != 9) {
		
	}
}