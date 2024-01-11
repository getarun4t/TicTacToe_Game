#include "play.hpp"
#include <limits>

#undef max

#undef max

using namespace std;

void Play::getNextOption() {
	std::pair<int, int> tempOption;
	do {
		tempOption.first = requestCoordinates("x");
		tempOption.second = requestCoordinates("y");
	} while (isEmpty(tempOption.first, tempOption.second));
	nextOption = tempOption;
}

int Play::requestCoordinates(std::string axes) {
	int option;
	while (1) {
		cout << "Enter the " << axes << " - coordinate(0, 1, or 2) : " << endl;
		cin >> option;
		if (cin.fail()) {
			cout << "Invalid input. Please enter an integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (cin.peek() != '\n') {
			cout << "Invalid input. Please enter only an integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		if (option > 2 || option < 0) {
			cout << "Valid coordinates are 0, 1, or 2. Please retry !! " << endl;
			continue;
		}
		else
			break;
	}
	return option;
}

bool Play::isEmpty(int coordinate_x, int coordinate_y) {
	if (board[coordinate_x][coordinate_y] == "0") {
		return false;
	}
	cout << "The option is already selected. Please select an empty cell !!";
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
		cout << endl << "Player A's turn" << endl;
	}
	else {
		B.setTurn();
		A.resetTurn();
		cout << endl << "Player B's turn" << endl;
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
	}
	if (winner == "Waiting") {
		if (checkedCellCount <= 8) {
			return true;
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
		cout << "Press any key and then ENTER to exit" << endl;
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