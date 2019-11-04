#include <QApplication>
#include <QPushButton>
#include <QFrame>
#include <QWidget>
#include <QGridLayout>

#include "headers/window.h"

int main(int argc, char *argv[])
{
    //steps to start up the application.
    QApplication app(argc, argv);

    mainWindow window;

    //modifies the window
    window.resize(400, 350);
    window.setWindowTitle("Calculator | Version 1.0.3 Alpha");
    window.show();
    window.setWindowIcon(QIcon(":/images/redeclipse.png"));

    return app.exec();
}
