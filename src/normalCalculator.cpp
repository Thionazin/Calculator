#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>

#include "headers/normalCalculator.h"

normalCalculator::normalCalculator(QWidget *parent) : QWidget(parent)
{

QVBoxLayout *vert = new QVBoxLayout(this);
//QHBoxLayout *horiz = new QHBoxLayout();

QGridLayout *layout = new QGridLayout();
layout->setSpacing(0);

QLineEdit *mainDisplay = new QLineEdit(this);

vert->addWidget(mainDisplay);

QList<QString> values({"C","^","+/-","<-","7","8","9","x","4","5","6","/","1","2","3","+","(","0",")","-","Up",".","Down","="});

int iter = 0;

for(int i = 0; i < 4; i++)
{
    for(int j = 0; j < 6; j++)
    {
        QPushButton *but = new QPushButton("\n \n" + values[iter] + "\n \n", this);
        //but->setFixedSize(40, 40);
        layout->addWidget(but, i, j);
        iter++;
    }
}

vert->addLayout(layout);

setLayout(vert);

}
