#include "tic-tac-toeWindow.h"
#include <qDebug>
#include <QSize>

GameWindow::GameWindow(char title[]) {
	qDebug() << "GameWindow";

	setWindowTitle(QString(title));
	centralWidget = new QWidget(this);

	qgl = new QGridLayout(centralWidget);

	winLabel = new QLabel("Move make X", centralWidget);

	restart_btn = new QPushButton("Restart", centralWidget);

	btns = std::vector<std::vector<QPushButton *>>(3);
	for (int i = 0; i < 3; i++) {
		btns[i] = std::vector<QPushButton *>(3);
		// qDebug() << "Create " << i << "vector of buttons";
		for (int j = 0; j < 3; j++) {
			btns[i][j] = new QPushButton(QString(""), centralWidget);
			map_btns[btns[i][j]] = {i, j};
			// qDebug() << "Create btn at " << i << " " << j;

			qgl->addWidget(btns[i][j], i, j);

			const QSize btn_size = QSize(50, 50);
			btns[i][j]->setFixedSize(btn_size);
			QObject::connect(btns[i][j], SIGNAL(clicked()), this, SLOT(Clicked()));
			// qDebug() << "added functions";

		}
	}
	qgl->addWidget(winLabel, 3, 0, 1, 3);
	qgl->addWidget(restart_btn, 4, 0, 1, 3);
	QObject::connect(restart_btn, SIGNAL(clicked()), this, SLOT(restart()));

	setLayout(qgl);

	this->startGame();
	qDebug() << "end constructor";
};

void GameWindow::Clicked() {
	QPushButton* btn = qobject_cast<QPushButton *>(sender());
	if (game->get_isOver()) {
		return;
	}

	if (game->get_curr() == 1) {
		winLabel->setText("Move makes O");
		btn->setText(QString("X"));
	} else {
		winLabel->setText("Move makes X");
		btn->setText(QString("O"));
	}


	int i = map_btns[btn].first;
	int j = map_btns[btn].second;
	
	game->makeMove(i, j);

	btn->setEnabled(false);
	if (game->get_isOver()) {
		char wins[10];
		game->get_win(wins);
		winLabel->setText(wins);
	}
}

void GameWindow::restart() {
	game = new Game(1);
	winLabel->setText("Move makes X");
	for (auto row : btns) {
		for (auto btn : row) {
			btn->setEnabled(true);
			btn->setText(QString(""));
		}
	}
}

void GameWindow::startGame() {
	game = new Game(1);
	this->show();
}
