#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QListWidget>

#include "headers/gpaCalculator.h"

gpaCalculator::gpaCalculator(QWidget *parent) : QWidget(parent)
{
QHBoxLayout *overall = new QHBoxLayout(this);
QVBoxLayout *buttons = new QVBoxLayout();

QListWidget *classes = new QListWidget(this);

QPushButton *addClass = new QPushButton("Add Class", this);
QPushButton *removeClass = new QPushButton("Remove Class", this);
QPushButton *calculate = new QPushButton("Calculate GPA", this);

buttons->addWidget(addClass);
buttons->addWidget(removeClass);
buttons->addWidget(calculate);

overall->addWidget(classes);
overall->addSpacing(20);
overall->addLayout(buttons);
overall->addSpacing(20);

setLayout(overall);
}
