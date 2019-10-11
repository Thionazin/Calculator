#include <QApplication>
#include <QPushButton>
#include <QFrame>
#include <QWidget>
#include <QGridLayout>

#include "headers/window.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    mainWindow window;

    window.resize(400, 350);
    window.setWindowTitle("Calculator");
    window.show();
    window.setWindowIcon(QIcon(":/images/redeclipse.png"));

    return app.exec();
}
