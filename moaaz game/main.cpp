#include "game.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    game window;

    window.show();
    return app.exec();

}
