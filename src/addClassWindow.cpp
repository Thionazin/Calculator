#include <QtWidgets>

#include <headers/addClassWindow.h>


addClassWindow::addClassWindow(QWidget *parent) : QDialog(parent), nameText(new QLineEdit), gradeText(new QLineEdit), multiText(new QLineEdit)
{
//placeholder text for the input fields
nameText->setPlaceholderText("Class Name");
gradeText->setPlaceholderText("Class Grades");
multiText->setPlaceholderText("Class Multiplier");

cancelled = false;

auto addClassButton = new QPushButton();
auto cancelButton = new QPushButton();
addClassButton->setText("Save Changes");
cancelButton->setText("Cancel");

auto windowLayout = new QVBoxLayout();
auto inputLayout = new QVBoxLayout();
auto buttonLayout = new QVBoxLayout();

inputLayout->addWidget(nameText);
inputLayout->addWidget(gradeText);
inputLayout->addWidget(multiText);
buttonLayout->addWidget(addClassButton);
buttonLayout->addWidget(cancelButton);

windowLayout->addLayout(inputLayout);
windowLayout->addLayout(buttonLayout);

setLayout(windowLayout);

connect(addClassButton, &QAbstractButton::clicked, this, &QDialog::accept);
connect(cancelButton, &QAbstractButton::clicked, this, &QDialog::reject);
connect(cancelButton, &QAbstractButton::clicked, this, &addClassWindow::setCancelled);

setWindowTitle("Add or edit a class.");
}

QString addClassWindow::name() const
{
    return nameText->text();
}

QString addClassWindow::grade() const
{
    return gradeText->text();
}

QString addClassWindow::multiplier() const
{
    return multiText->text();
}

void addClassWindow::editClass(const QString &name, const QString &grade, const QString &multiplier)
{
    nameText->setText(name);
    gradeText->setText(grade);
    multiText->setText(multiplier);
}

void addClassWindow::setCancelled()
{
    cancelled = true;
}

bool addClassWindow::getCancelled()
{
    return cancelled;
}
