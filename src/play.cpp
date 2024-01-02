#include "play.hpp"

using namespace std;

void Play::getNextOption() {
	do {
		cout << "Enter the x-coordinate (0, 1, or 2): " << endl;
		cin >> nextOption.first;
		cout << "Enter the y-coordinate (0, 1, or 2): " << endl;
		cin >> nextOption.second;
	} while (isValid(nextOption.first, nextOption.second));
}

bool Play::isValid(int coordinate_x, int coordinate_y) {
	if (board[coordinate_x][coordinate_y] == "0" && coordinate_y < 3 && coordinate_x < 3) {
		if (A.getTurn()) {
			board[coordinate_x][coordinate_y] = "X";
		}
		else {
			board[coordinate_x][coordinate_y] = "O";
		}
	}
	else {
		cout << "Invalid Input ! Re-try with a valid input !! ";
		printBoard();
		return false;
	}
	return true;
}

void Play::printBoard() {
	cout << endl;
	cout << "Current board is below" << endl;

	for (const auto& y : board) {
		for (const auto& x : y) {
			cout << "| ";
			if (x == "0") {
				cout << " ";
			}
			else {
				cout << x;
			}
			cout << " |" << endl;
		}
		cout << endl;
		cout << " ____________" << endl;
		cout << endl;
	}
}

void Play::markInBoard() {
	if (A.getTurn())
		board[nextOption.first][nextOption.second] = "X";
	else
		board[nextOption.first][nextOption.second] = "O";
	checkedCellCount++;
}

void Play::switchPlayer() {
	if (!A.getTurn()) {
		A.setTurn();
		B.resetTurn();
	}
	else {
		B.setTurn();
		A.resetTurn();
	}
}

Play::Play() : checkedCellCount(0), board(vector<vector<string>>(3, vector<string>(3, "0"))) {};

bool Play::checkGameEnd() {
	if (checkedCellCount != 9) {
		for (const string& a : { "X", "O" }) {
			if (!(board[0][0] == a && board[1][1] == a && board[2][2] == a) ||
				!(board[0][2] == a && board[1][1] == a && board[2][0] == a) ||
				!(board[0][0] == a && board[0][1] == a && board[0][2] == a) ||
				!(board[1][0] == a && board[1][1] == a && board[1][2] == a) ||
				!(board[2][0] == a && board[2][1] == a && board[2][2] == a) ||
				!(board[0][0] == a && board[1][0] == a && board[2][0] == a) ||
				!(board[0][1] == a && board[1][1] == a && board[2][1] == a) ||
				!(board[0][2] == a && board[1][2] == a && board[2][2] == a)) {
				return true;
			}
		}
	}
	return false;
}

void Play::run() {
	do {
		switchPlayer();
		printBoard();
		getNextOption();
		markInBoard();
	} while (checkGameEnd());
}