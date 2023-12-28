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
	if (Play::board[coordinate] == "0" && coordinate < 3) {
		if (A.getTurn()) {
			Play::board[coordinate] = "X";
		}
		else {
			Play::board[coordinate] = "O";
		}

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
		board[nextOption.first][nextOption.second] == "X";
	else
		board[nextOption.first][nextOption.second] == "O";
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

Play::Play() {
	checkedCellCount = 0;
	board = vector<vector<string>>(3, vector<string>(3, "0"));
}

bool Play::checkGameEnd() {
	if (checkedCellCount != 9) {
		for (string a : {"X", "O"}) {
			if (!(board[0][0] == a && board[1][1] == a && board[2][2] == a) or
				!(board[0][2] == a && board[1][1] == a && board[2][0] == a) or
				!(board[0][0] == a && board[0][1] == a && board[0][2] == a) or
				!(board[1][0] == a && board[1][1] == a && board[1][2] == a) or
				!(board[2][0] == a && board[2][1] == a && board[2][2] == a) or
				!(board[0][0] == a && board[1][0] == a && board[2][0] == a) or
				!(board[0][1] == a && board[1][1] == a && board[2][1] == a) or
				!(board[0][2] == a && board[1][2] == a && board[2][2] == a))
				return true;
		}
	}
	return false;
}

void Play::run() {
	do {
		switchPlayer();
		printBoard();
		getNextoption();
		MarkInBoard();
	} while (checkGameEnd());
}