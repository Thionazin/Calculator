#ifndef NORMALCALCULATOR_H
#define NORMALCALCULATOR_H

#pragma once

#include <QWidget>
#include <QLineEdit>

class normalCalculator : public QWidget {

public:
    normalCalculator(QWidget *parent = nullptr);

private slots:
    void zero();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();
    void leftPar();
    void rightPar();
    void decimal();
    void scrollUp();
    void scrollDown();
    void clear();
    void exponent();
    void sign();
    void backspace();
    void multiply();
    void divide();
    void add();
    void subtract();
    void solve();

private:
    QLineEdit *mainDisplay;

};

#endif // NORMALCALCULATOR_H
