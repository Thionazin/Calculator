#ifndef WINDOW_H
#define WINDOW_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QMainWindow>

class mainWindow : public QMainWindow
{

Q_OBJECT

public:
    mainWindow(QWidget *parent = nullptr);

private slots:
    void switchToNormal();
    void switchToGpa();


private:
    void onCreate();
    void setMainWidget(QWidget *newWidget);
    QLabel *output;

};

#endif // WINDOW_H
