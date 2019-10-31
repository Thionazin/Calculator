#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <QListWidget>
#include <QMainWindow>
#include <QFileDialog>
#include <QAction>
#include <QMessageBox>
#include <QTextStream>

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
QPushButton *saveClasses = new QPushButton(this);
QPushButton *loadClasses = new QPushButton(this);
QPushButton *addClass = new QPushButton(this);
QPushButton *editClass = new QPushButton(this);
QPushButton *removeClass = new QPushButton(this);
QPushButton *calculate = new QPushButton(this);
buttons->addWidget(saveClasses);
buttons->addWidget(loadClasses);
buttons->addWidget(addClass);
buttons->addWidget(editClass);
buttons->addWidget(removeClass);
buttons->addWidget(calculate);
const QIcon saveIcon = QIcon::fromTheme("save-classes", QIcon(":/images/save.png"));
saveClasses->setIcon(saveIcon);
saveClasses->setToolTip("Save classes");
const QIcon loadIcon = QIcon::fromTheme("load-classes", QIcon(":/images/open.png"));
loadClasses->setIcon(loadIcon);
loadClasses->setToolTip("Load classes");
const QIcon plusIcon = QIcon::fromTheme("new-class", QIcon(":/images/plus.png"));
addClass->setIcon(plusIcon);
addClass->setToolTip("Add a class");
const QIcon editIcon = QIcon::fromTheme("edit-class", QIcon(":/images/edit.png"));
editClass->setIcon(editIcon);
editClass->setToolTip("Edit a class");
const QIcon minusIcon = QIcon::fromTheme("remove-class", QIcon(":/images/minus.png"));
removeClass->setIcon(minusIcon);
removeClass->setToolTip("Remove a class");
const QIcon calculateIcon = QIcon::fromTheme("calculate-class", QIcon(":/images/calculate.png"));
calculate->setIcon(calculateIcon);
calculate->setToolTip("Calculate GPA");

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
overall->addLayout(menu);
overall->addWidget(classes);
overall->addSpacing(0);

//connects the buttons so they actually do something
connect(saveClasses, &QPushButton::clicked, this, &gpaCalculator::saveClasses);
connect(loadClasses, &QPushButton::clicked, this, &gpaCalculator::loadClasses);
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

//slot for the class editor button
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

//slot for delete class button
void gpaCalculator::deleteClassButton()
{
    qDeleteAll(classes->selectedItems());
}

//slot for the calc gpa button
void gpaCalculator::calcGpaButton()
{
    double totalgrade = 0.0;
    //takes each individual entry and splits it into parts. Weighs and adds grade to total.
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

    //Creates the window that displays the gpa result.
    gpaSolver resultScreen;
    resultScreen.setDisplay(finalGpa);
    resultScreen.resize(400, 200);
    resultScreen.exec();
}

//slot for the button that adds a class
void gpaCalculator::addClass(QString className, QString grade, QString multiplier)
{
    classes->addItem(className + " | " + grade + " | " + multiplier);
}

//slot for saving a class to a .gpa file.
void gpaCalculator::saveClasses()
{
    //Gets the file based on name you input in the pop up window
    QString fileName = QFileDialog::getSaveFileName(this,
            tr("Save Grades"), "",
            tr("GPA (*.gpa);;All Files (*)"));
    //Gets the file with the given name.
    QFile file(fileName);
    //If unable to open, error and returns.
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }
    QTextStream out(&file);
    QString output;
    //adds each individual entry to a string seperated by #.
    for(int i = 0; i < classes->count() - 1; i++)
    {
        output = output + classes->item(i)->text() + "#";
    }
    output = output + classes->item(classes->count()-1)->text();
    out << output;
}

//slot for the loading of classes.
void gpaCalculator::loadClasses()
{
    //gets the file based on name
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Load Grades"), "",
            tr("GPA (*.gpa);;All Files (*)"));
    QFile file(fileName);
    //If fails, error
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(this, tr("No file was loaded."),
            file.errorString());
        return;
    }

    //gets the input and splits it into a list.
    QString input;
    QTextStream in(&file);
    input = in.readAll();
    QStringList inputParser = input.split("#");

    //clears the current set of grades
    int times = classes->count();
    for(int i = 0; i < times; i++)
    {
        classes->takeItem(0);
    }


    //loops through each element in list and adds it to the list widget
    for(int i = 0; i < inputParser.length(); i++)
    {
        classes->addItem(inputParser[i]);
    }
}
