#include <QtWidgets>

#include <headers/addClassWindow.h>
#include "headers/numButton.h"


addClassWindow::addClassWindow(QWidget *parent) : QDialog(parent), nameText(new QLineEdit), gradeText(new QLineEdit), multiText(new QLineEdit)
{
    setStyleSheet("numButton { background-color:#7dc383; border-color:none; border:none; font: bold large 'Ariel'; font-size:10px; padding: 10px; } numButton:hover { background-color:#d0e1f9; } numButton:pressed { background-color: #2a4d69; color: white; } QListWidgetItem:pressed { color: black; }");
//placeholder text for the input fields
nameText->setPlaceholderText("Class Name");
gradeText->setPlaceholderText("Class Grades");
multiText->setPlaceholderText("Class Multiplier");
nameText->setStyleSheet("background-color:#fff1bc; font: 'Museo Sans'; font-size: 12px; padding:2px; border:none;");
gradeText->setStyleSheet("background-color:#fff1bc; font: 'Museo Sans'; font-size: 12px; padding:2px; border:none;");
multiText->setStyleSheet("background-color:#fff1bc; font: 'Museo Sans'; font-size: 12px; padding:2px; border:none;");


cancelled = false;

//creates the buttons on the screen
auto addClassButton = new numButton();
auto cancelButton = new numButton();
addClassButton->setText("Save Changes");
cancelButton->setText("Cancel");

//creates the layout used
auto windowLayout = new QVBoxLayout();
auto inputLayout = new QVBoxLayout();
auto buttonLayout = new QVBoxLayout();

//adds the text edit and button widgets to the layout.
inputLayout->addWidget(nameText);
inputLayout->addWidget(gradeText);
inputLayout->addWidget(multiText);
buttonLayout->addWidget(addClassButton);
buttonLayout->addWidget(cancelButton);

//adds layouts to overall layout
windowLayout->addLayout(inputLayout);
windowLayout->addLayout(buttonLayout);

setLayout(windowLayout);

//connects buttons to the slots
connect(addClassButton, &QAbstractButton::clicked, this, &QDialog::accept);
connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);
connect(cancelButton, &QAbstractButton::clicked, this, &addClassWindow::setCancelled);

setWindowTitle("Add or edit a class.");
}

//constant string for the name input
QString addClassWindow::name() const
{
    return nameText->text();
}

//constant for the grade input
QString addClassWindow::grade() const
{
    return gradeText->text();
}

//constant for the multiplier input
QString addClassWindow::multiplier() const
{
    return multiText->text();
}

//method for adding in the pre existing data for each field.
void addClassWindow::editClass(const QString &name, const QString &grade, const QString &multiplier)
{
    nameText->setText(name);
    gradeText->setText(grade);
    multiText->setText(multiplier);
}

//method for setting the cancelled boolean to true.
void addClassWindow::setCancelled()
{
    cancelled = true;
}

//gets status of cancelled
bool addClassWindow::getCancelled()
{
    return cancelled;
}
//cancelled is used to check whether or not input changes will be saved.
