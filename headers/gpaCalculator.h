#ifndef GPACALCULATOR_H
#define GPACALCULATOR_H

#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include <QItemSelection>
#include <QTabWidget>

class gpaCalculator : public QWidget {

public:
    gpaCalculator(QWidget *parent = nullptr);
    void writeToFile();

private slots:
    void saveClasses();
    void loadClasses();
    void deleteClassButton();
    void addClassButton();
    void editClassButton();
    void calcGpaButton();

private:
    QLineEdit *className;
    QLineEdit *classGrade;
    QLineEdit *classMulti;
    QListWidget *classes;
    QLabel *gpa;
    QLabel *description;
    void addClass(QString name, QString grade, QString multiplier);

};

#endif // GPACALCULATOR_H
