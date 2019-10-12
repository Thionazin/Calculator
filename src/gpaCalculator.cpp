#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QListWidget>

#include "headers/gpaCalculator.h"

gpaCalculator::gpaCalculator(QWidget *parent) : QWidget(parent)
{
//creates the layouts for this mode.
QHBoxLayout *overall = new QHBoxLayout(this);
QVBoxLayout *buttons = new QVBoxLayout();

//listwidget for listing classes you have added.
QListWidget *classes = new QListWidget(this);

//Buttons for application.
QPushButton *addClass = new QPushButton("Add Class", this);
QPushButton *removeClass = new QPushButton("Remove Class", this);
QPushButton *calculate = new QPushButton("Calculate GPA", this);

//adds buttons to layout.
buttons->addWidget(addClass);
buttons->addWidget(removeClass);
buttons->addWidget(calculate);

//adds all layouts and widgets to overall main widget.
overall->addWidget(classes);
overall->addSpacing(20);
overall->addLayout(buttons);
overall->addSpacing(20);

//sets layout to the overall layout.
setLayout(overall);
}
