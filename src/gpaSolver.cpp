#include <QtWidgets>

#include <headers/gpaSolver.h>

//creates the window to display the solved gpa
gpaSolver::gpaSolver(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *overallLayout = new QVBoxLayout();

    //creates the labels
    title = new QLabel("Your GPA is:");
    gpa = new QLabel();
    title->setStyleSheet("font-size: 36px;");

    //settings for the labels
    gpa->setAlignment(Qt::AlignCenter);
    gpa->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    title->setAlignment(Qt::AlignCenter);
    title->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    //adds labels to layout
    overallLayout->addWidget(title);
    overallLayout->addWidget(gpa);

    setLayout(overallLayout);

}

//sets the display to the calculated gpa amount
void gpaSolver::setDisplay(double gpaNum)
{
    gpa->setText(QString::number(gpaNum));
}
