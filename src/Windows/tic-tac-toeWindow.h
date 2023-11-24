#pragma once
#include "../Logic/Game.h"
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QObject>
#include <vector>
#include <map>


class GameWindow: public QWidget {
	Q_OBJECT
public:
	GameWindow(char title[]);
public slots:
	void startGame();

	void Clicked();

	void restart();

private:
	Game* game;

	QWidget* centralWidget;

	std::vector<std::vector<QPushButton*>> btns;
	std::map<QPushButton *, std::pair<int, int>> map_btns;

	QGridLayout* qgl;

	QLabel* winLabel;
	QPushButton* restart_btn;

};