#include "play.hpp"

using namespace std;

void Play::getNextOption() {
	do {
		do {
			cout << "Enter the x-coordinate (0, 1, or 2): " << endl;
			cin >> nextOption.first;
			if (cin.fail()) {
				cout << "Invalid input. Please enter an integer." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (cin.fail());
		do {
			cout << "Enter the y-coordinate (0, 1, or 2): " << endl;
			cin >> nextOption.second;
			if (cin.fail()) {
				cout << "Invalid input. Please enter an integer." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
			}
		} while (cin.fail());
	} while (isValid(nextOption.first, nextOption.second));
}

bool Play::isValid(int coordinate_x, int coordinate_y) {
	if (coordinate_y < 3 && coordinate_x < 3) {
		if (board[coordinate_x][coordinate_y] == "0") {
			return false;
		}
	}
	cout << "Invalid Input ! Re-try with a valid input !! ";
	printBoard();
	return true;
}

void Play::printBoard() {
	cout << endl;
	cout << "Current board is below" << endl;

	cout << "=============" << endl;
	for (const auto& y : board) {
		cout << "|";
		for (const auto& x : y) {
			if (x == "0") {
				cout << "   ";
			}
			else {
				cout << " " << x << " ";
			}
			cout << "|";
		}
		cout << endl;
		cout << "=============" << endl;
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
	string winner = "Waiting";
	for (const string& a : { "X", "O" }) {
		if ((board[0][0] == a && board[1][1] == a && board[2][2] == a) ||
			(board[0][2] == a && board[1][1] == a && board[2][0] == a) ||
			(board[0][0] == a && board[0][1] == a && board[0][2] == a) ||
			(board[1][0] == a && board[1][1] == a && board[1][2] == a) ||
			(board[2][0] == a && board[2][1] == a && board[2][2] == a) ||
			(board[0][0] == a && board[1][0] == a && board[2][0] == a) ||
			(board[0][1] == a && board[1][1] == a && board[2][1] == a) ||
			(board[0][2] == a && board[1][2] == a && board[2][2] == a)) {
			winner = a;
			break;
		}
		else {
			if (checkedCellCount <= 8) {
				return true;
			}
			else {
				break;
			}
		}
	}

	if (winner == "X") {
		cout << endl << "Player A wins" << endl;
	}
	else if (winner == "O") {
		cout << endl << "Player B wins" << endl;
	}
	else {
		cout << endl << "No winner. Game ends !!" << endl;
	}

	printBoard();
	string x = "Waiting";
	while (x == "Waiting") {
		cout << "Press any key to exit" << endl;
		cin >> x;
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