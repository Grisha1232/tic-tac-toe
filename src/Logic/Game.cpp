#include "Game.h"

void Game::makeMove(int i, int j) {
	if (currMove == 1) {
		setField(currMove, i, j);
		currMove = 2;
	} else {
		setField(currMove, i, j);
		currMove = 1;
	}
	this->isGameOver();
};

void Game::setField(int curr, int i, int j) {
	field[i][j] = curr;
}

void Game::isGameOver() {
	int ret = isSameAtMainDiag();
	qDebug() << "main diag = " << ret;
	if (ret != -1) {
		win = ret;
		isOver = true;
		return;
	}
	ret = isSameAtSecoDiag();
	qDebug() << "second diag = " << ret;
	if (ret != -1) {
		win = ret;
		isOver = true;
		return;
	}
	for (int i = 0; i < 3; i++) {
		ret = isSameAtRow(i);
		qDebug() << "row(" << i << ") = " << ret;
		if (ret != -1) {
			win = ret;
			isOver = true;
			return;
		}
		ret = isSameAtCol(i);
		qDebug() << "col(" << i << ") = " << ret;
		if (ret != -1) {
			win = ret;
			isOver = true;
			return;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (field[i][j] == 0) {
				return;
			}
		}
	}
	isOver = true;
	win = 0;
}

int Game::isSameAtRow(int i) {
	if (field[i][0] == 0 || field[i][1] == 0 || field[i][2] == 0) {
		return -1;
	}
	if (field[i][0] == field[i][1] && field[i][1] == field[i][2]) {
		return field[i][0];
	}
	return -1;
}

int Game::isSameAtCol(int j) {
	if (field[0][j] == 0 || field[1][j] == 0 || field[2][j] == 0) {
		return -1;
	}
	if (field[0][j] == field[1][j] && field[1][j] == field[2][j]) {
		return field[0][j];
	}
	return -1;
}

int Game::isSameAtMainDiag() {
	if (field[0][0] == 0 || field[1][1] == 0 || field[2][2] == 0) {
		return -1;
	} else if (field[0][0] == field[1][1] && field[1][1] == field[2][2]) {
		return field[0][0];
	} else {
		return -1;
	}
}

int Game::isSameAtSecoDiag() {
	if (field[0][2] == 0 || field[1][1] == 0 || field[2][0] == 0) {
		return -1;
	} else if (field[0][2] == field[1][1] && field[2][0] == field[1][1]) {
		return field[1][1];
	} else {
		return -1;
	}
}

void Game::get_win(char* ret) {
	if (this->win == 0) {
		strcpy(ret, "Tie");
		return;
	}
	strcpy(ret, (this->win == 1 ? "Wins X" : "Wins O"));
}

int Game::get_curr() {
	return this->currMove;
}


