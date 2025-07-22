#include "game.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication app(argc, argv);
    game window;

    window.show();
    return app.exec();

}
