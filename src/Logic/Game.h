#pragma once

#include <vector>
#include <qDebug>
#include <QPushButton>

class Game {

public:

	Game(int firstMove): currMove(firstMove) {
		field = std::vector<std::vector<int>>(3, std::vector<int>(3, 0));
	}

	void makeMove(int i, int j);


	void setField(int curr, int i, int j);

	bool get_isOver() {
		return isOver;
	}

	void get_win(char* ret);

	int get_curr();

private:

	void isGameOver();
	int isSameAtRow(int i); // 1 = X, 2 = O, -1 = none
	int isSameAtCol(int j); // 1 = X, 2 = O, -1 = none
	int isSameAtMainDiag();  //  player (1 = X, 2 = O)
	int isSameAtSecoDiag();

	bool isOver = false;
	int win;
	int currMove;
	std::vector<std::vector<int>> field;
};