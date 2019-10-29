#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QListWidget>

#include "headers/gpaCalculator.h"
#include <headers/addClassWindow.h>
#include <headers/gpaSolver.h>

gpaCalculator::gpaCalculator(QWidget *parent) : QWidget(parent)
{
//creates the layouts for this mode.
QVBoxLayout *overall = new QVBoxLayout(this);
QHBoxLayout *buttons = new QHBoxLayout();
QHBoxLayout *menu = new QHBoxLayout();
QVBoxLayout *display = new QVBoxLayout();


//stuff for the display fields
//obsolete
/*
description = new QLabel("Your GPA is:");
gpa = new QLabel("0");
description->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
gpa->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
description->setAlignment(Qt::AlignCenter);
gpa->setAlignment(Qt::AlignCenter);
//display->addWidget(description);
//display->addWidget(gpa);
*/


//listwidget for listing classes you have added.
classes = new QListWidget(this);


//Line Edits
//Useless, outdated
/*
className = new QLineEdit(this);
classGrade = new QLineEdit(this);
classMulti = new QLineEdit(this);
className->setPlaceholderText("Class Name");
classGrade->setPlaceholderText("Class Grade");
classMulti->setPlaceholderText("Class Multiplier");
*/

//Buttons for application.
QPushButton *addClass = new QPushButton("Add Class", this);
QPushButton *editClass = new QPushButton("Edit Class", this);
QPushButton *removeClass = new QPushButton("Remove Class", this);
QPushButton *calculate = new QPushButton("Calculate GPA", this);
buttons->addWidget(addClass);
buttons->addWidget(editClass);
buttons->addWidget(removeClass);
buttons->addWidget(calculate);

buttons->setSpacing(0);

//add lineedits to layout
//outdated, useless
/*
textFields->addWidget(className);
textFields->addWidget(classGrade);
textFields->addWidget(classMulti);
*/

//adds buttons to layout.
menu->addLayout(buttons);
menu->addLayout(display);

//adds all layouts and widgets to overall main widget.
overall->addWidget(classes);
overall->addSpacing(20);
overall->addLayout(menu);
overall->addSpacing(20);

//connects the buttons so they actually do something
connect(addClass, &QPushButton::clicked, this, &gpaCalculator::addClassButton);
connect(editClass, &QPushButton::clicked, this, &gpaCalculator::editClassButton);
connect(removeClass, &QPushButton::clicked, this, &gpaCalculator::deleteClassButton);
connect(calculate, &QPushButton::clicked, this, &gpaCalculator::calcGpaButton);


//sets layout to the overall layout.
setLayout(overall);
}

//takes the input of the three text fields and adds an element to the big list.
void gpaCalculator::addClassButton()
{
    QString clsName;
    QString clsGrade;
    QString clsMulti;

    addClassWindow newWindow;

    if(newWindow.exec())
    {
        clsName = newWindow.name();
        clsGrade = newWindow.grade();
        clsMulti = newWindow.multiplier();
    }

    if(newWindow.getCancelled())
    {

    }
    else
    {
        classes->addItem(clsName + " | " + clsGrade + " | " + clsMulti);
    }

}

void gpaCalculator::editClassButton()
{
    if(classes->selectedItems().count() >= 1)
    {
        QString clsName;
        QString clsGrade;
        QString clsMulti;

        auto selectedItems = classes->selectedItems();
        QString classInput = selectedItems[0]->text();
        QStringList splitInput = classInput.split(" | ");

        addClassWindow editWindow;
        editWindow.editClass(splitInput[0], splitInput[1], splitInput[2]);

        if(editWindow.exec())
        {
            clsName = editWindow.name();
            clsGrade = editWindow.grade();
            clsMulti = editWindow.multiplier();
        }

        if(editWindow.getCancelled())
        {

        }
        else
        {
            classes->selectedItems()[0]->setText(clsName + " | " + clsGrade + " | " + clsMulti);
        }

    }
}

/* Old stuff
QString clsName = className->text();
QString clsGrade = classGrade->text();
QString clsMulti = classMulti->text();
classes->addItem(clsName + " | " + clsGrade + " | " + clsMulti);
*/

void gpaCalculator::deleteClassButton()
{
    qDeleteAll(classes->selectedItems());
}

void gpaCalculator::calcGpaButton()
{
    double totalgrade = 0.0;
    for(int i = 0; i < classes->count(); i++)
    {
        QString classInfo = classes->item(i)->text();
        QStringList stepOne = classInfo.split(" | ");
        double grade = stepOne[1].toDouble();
        double multi = stepOne[2].toDouble();
        double weighted = grade * multi;
        totalgrade += weighted;
    }
    double finalGpa = totalgrade / classes->count();

    gpaSolver resultScreen;

    resultScreen.setDisplay(finalGpa);

    resultScreen.resize(400, 200);

    resultScreen.exec();

}

void gpaCalculator::addClass(QString className, QString grade, QString multiplier)
{
    classes->addItem(className + " | " + grade + " | " + multiplier);
}
