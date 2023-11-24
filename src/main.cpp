#include <QApplication>
#include "Windows/tic-tac-toeWindow.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	GameWindow game("title");


	return app.exec();
}