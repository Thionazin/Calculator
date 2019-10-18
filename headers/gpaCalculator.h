#ifndef GPACALCULATOR_H
#define GPACALCULATOR_H

#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>

class gpaCalculator : public QWidget {

public:
    gpaCalculator(QWidget *parent = 0);

private slots:
    void deleteClassButton();
    void addClassButton();
    void calcGpaButton();

private:
    QLineEdit *className;
    QLineEdit *classGrade;
    QLineEdit *classMulti;
    QListWidget *classes;
    QLabel *gpa;
    QLabel *description;

};

#endif // GPACALCULATOR_H
