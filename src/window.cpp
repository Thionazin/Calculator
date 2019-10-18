#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>

#include "headers/window.h"
#include "headers/normalCalculator.h"
#include "headers/gpaCalculator.h"

mainWindow::mainWindow(QWidget *parent) : QMainWindow(parent)
{
    //Creates the main window and initializes various objects.
    onCreate();

    normalCalculator *normCalc;
    normCalc = new normalCalculator();

    setCentralWidget(normCalc);

}

void mainWindow::onCreate()
{
    //Creates menu bar and adds options to the menu bar.
    QMenu *menu = menuBar()->addMenu(tr("&File"));
    QAction *saveState = new QAction("Save Window");
    menu->addAction(saveState);
    QAction *exit = new QAction("&Quit", this);
    exit->setStatusTip("Exit Program");
    menu->addAction(exit);
    menu = menuBar()->addMenu(tr("&Modes"));
    QAction *normal = new QAction("&Basic", this);
    QAction *GPA = new QAction("&GPA", this);
    menu->addAction(normal);
    menu->addAction(GPA);
    menu = menuBar()->addMenu(tr("&Options"));

    //connects the menu options so they actually do something.
    connect(exit, &QAction::triggered, qApp, QApplication::quit);
    connect(normal, &QAction::triggered, this, &mainWindow::switchToNormal);
    connect(GPA, &QAction::triggered, this, &mainWindow::switchToGpa);
}

//switches main widget to the normal calculator.
void mainWindow::switchToNormal()
{
    normalCalculator *normCalc = new normalCalculator();
    setCentralWidget(normCalc);
    this->setWindowTitle("Calculator | Version 1.0.0 Alpha");
}

//switches main widget to the gpa calculator.
void mainWindow::switchToGpa()
{
    gpaCalculator *gpaCalc = new gpaCalculator();
    setCentralWidget(gpaCalc);
    this->setWindowTitle("GPA Calculator | Version 0.1.0 Useless Edition");
}
