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
    onCreate();

    normalCalculator *normCalc;
    normCalc = new normalCalculator();

    setCentralWidget(normCalc);

}

void mainWindow::onCreate()
{
    QMenu *menu = menuBar()->addMenu(tr("&File"));
    //QToolBar *fileToolBar = addToolBar(tr("File"));
    QAction *exit = new QAction("&Quit", this);
    exit->setStatusTip("Exit Program");
    menu->addAction(exit);
    //fileToolBar->addAction(exit);
    menu = menuBar()->addMenu(tr("&Modes"));
    QAction *normal = new QAction("&Basic", this);
    QAction *GPA = new QAction("&GPA", this);
    menu->addAction(normal);
    menu->addAction(GPA);


    connect(exit, &QAction::triggered, qApp, QApplication::quit);
    connect(normal, &QAction::triggered, this, &mainWindow::switchToNormal);
    connect(GPA, &QAction::triggered, this, &mainWindow::switchToGpa);
}

void mainWindow::switchToNormal()
{
    normalCalculator *normCalc = new normalCalculator();
    setCentralWidget(normCalc);
}

void mainWindow::switchToGpa()
{
    gpaCalculator *gpaCalc = new gpaCalculator();
    setCentralWidget(gpaCalc);
}
