#ifndef GPASOLVER_H
#define GPASOLVER_H

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QDialog>

#pragma once

class gpaSolver : public QDialog
{

Q_OBJECT

public:
    gpaSolver(QWidget *parent = nullptr);
    void setDisplay(double gpaNum);

private:
    QLabel *title;
    QLabel *gpa;

};

#endif // GPASOLVER_H
