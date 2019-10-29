#include <QtWidgets>

#include <headers/gpaSolver.h>

gpaSolver::gpaSolver(QWidget *parent) : QDialog(parent)
{
    QVBoxLayout *overallLayout = new QVBoxLayout();

    title = new QLabel("Your GPA is:");
    gpa = new QLabel();
    title->setStyleSheet("font-size: 36px;");

    gpa->setAlignment(Qt::AlignCenter);
    gpa->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
    title->setAlignment(Qt::AlignCenter);
    title->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);

    overallLayout->addWidget(title);
    overallLayout->addWidget(gpa);

    setLayout(overallLayout);

}

void gpaSolver::setDisplay(double gpaNum)
{
    gpa->setText(QString::number(gpaNum));
}
