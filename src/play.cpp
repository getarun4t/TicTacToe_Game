#include "\include\play.hpp"

Play::getNextOption() {
	pair<int, int> input;
	do {
		cout << "Enter the x co-ordinates" << endl;
		cin >> input.first;
		cout << "Enter the y co-ordinates" << endl;
		cin >> input.second;
	} while (Play::isValid(input.first) && Play::isValid(input.second));
	return input;
}

Play::isValid(int coordinate) {
	if (Play::board[coordinate] == 0 && coordinate < 3) {
		Play::board[coordinate] == 1;
	}
	else {
		cout << "Invalid Input ! Re-try with a valid input !! "
			return false;
	}
	return true;
}

Play::printBoard(Play::board) {
	for (auto y : board) {
		for (auto x : y) {
			cout << "| ";
			if (x) {
				cout << x ;
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

Play::checkGameEnd() {

}