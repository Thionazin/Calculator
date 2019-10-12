#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <iostream>
#include <string.h>

#include "headers/normalCalculator.h"

normalCalculator::normalCalculator(QWidget *parent) : QWidget(parent)
{

QVBoxLayout *vert = new QVBoxLayout(this);
//QHBoxLayout *horiz = new QHBoxLayout();

QGridLayout *layout = new QGridLayout();
layout->setSpacing(0);

mainDisplay = new QLineEdit(this);

vert->addWidget(mainDisplay);

QList<QString> values({"C","^","+/-","<-","7","8","9","x","4","5","6","/","1","2","3","+","(","0",")","-","Up",".","Down","="});

int iter = 0;


for(int i = 0; i < 6; i++)
{
    for(int j = 0; j < 4; j++)
    {
        QPushButton *but = new QPushButton("\n \n" + values[iter] + "\n \n", this);
        //but->setFixedSize(40, 40);
        layout->addWidget(but, i, j);
        iter++;
    }
}

QPushButton *oneButton = new QPushButton("\n \n1\n \n", this);
QPushButton *clearButton = new QPushButton("\n \nC\n \n", this);
QPushButton *expoButton = new QPushButton("\n \n^\n \n", this);
QPushButton *backspaceButton = new QPushButton("\n \n<-\n \n", this);
QPushButton *sevenButton = new QPushButton("\n \n7\n \n", this);
QPushButton *eightButton = new QPushButton("\n \n8\n \n", this);
QPushButton *nineButton = new QPushButton("\n \n9\n \n", this);
QPushButton *multiplyButton = new QPushButton("\n \nx\n \n", this);
QPushButton *fourButton = new QPushButton("\n \n4\n \n", this);
QPushButton *fiveButton = new QPushButton("\n \n5\n \n", this);
QPushButton *sixButton = new QPushButton("\n \n6\n \n", this);
QPushButton *divideButton = new QPushButton("\n \n/\n \n", this);
QPushButton *twoButton = new QPushButton("\n \n2\n \n", this);
QPushButton *threeButton = new QPushButton("\n \n3\n \n", this);
QPushButton *plusButton = new QPushButton("\n \n+\n \n", this);
QPushButton *zeroButton = new QPushButton("\n \n0\n \n", this);
QPushButton *subtractButton = new QPushButton("\n \n-\n \n", this);


layout->addWidget(oneButton, 3, 0);
layout->addWidget(clearButton, 0, 0);
layout->addWidget(expoButton, 0, 1);
layout->addWidget(backspaceButton, 0, 3);
layout->addWidget(sevenButton, 1, 0);
layout->addWidget(eightButton, 1, 1);
layout->addWidget(nineButton, 1, 2);
layout->addWidget(multiplyButton, 1, 3);
layout->addWidget(fourButton, 2, 0);
layout->addWidget(fiveButton, 2, 1);
layout->addWidget(sixButton, 2, 2);
layout->addWidget(divideButton, 2, 3);
layout->addWidget(twoButton, 3, 1);
layout->addWidget(threeButton, 3, 2);
layout->addWidget(plusButton, 3, 3);
layout->addWidget(zeroButton, 4, 1);
layout->addWidget(subtractButton, 4, 3);


connect(oneButton, &QPushButton::clicked, this, &normalCalculator::one);
connect(clearButton, &QPushButton::clicked, this, &normalCalculator::clear);
connect(expoButton, &QPushButton::clicked, this, &normalCalculator::exponent);
connect(backspaceButton, &QPushButton::clicked, this, &normalCalculator::backspace);
connect(sevenButton, &QPushButton::clicked, this, &normalCalculator::seven);
connect(eightButton, &QPushButton::clicked, this, &normalCalculator::eight);
connect(nineButton, &QPushButton::clicked, this, &normalCalculator::nine);
connect(multiplyButton, &QPushButton::clicked, this, &normalCalculator::multiply);
connect(fourButton, &QPushButton::clicked, this, &normalCalculator::four);
connect(fiveButton, &QPushButton::clicked, this, &normalCalculator::five);
connect(sixButton, &QPushButton::clicked, this, &normalCalculator::six);
connect(divideButton, &QPushButton::clicked, this, &normalCalculator::divide);
connect(twoButton, &QPushButton::clicked, this, &normalCalculator::two);
connect(threeButton, &QPushButton::clicked, this, &normalCalculator::three);
connect(plusButton, &QPushButton::clicked, this, &normalCalculator::add);
connect(zeroButton, &QPushButton::clicked, this, &normalCalculator::zero);
connect(subtractButton, &QPushButton::clicked, this, &normalCalculator::subtract);



vert->addLayout(layout);

setLayout(vert);

}

void normalCalculator::zero()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("0");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 0");
        }
        else
        {
            mainDisplay->insert("0");
        }
    }
}

void normalCalculator::one()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("1");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 1");
        }
        else
        {
            mainDisplay->insert("1");
        }
    }
}

void normalCalculator::two()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("2");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 2");
        }
        else
        {
            mainDisplay->insert("2");
        }
    }
}

void normalCalculator::three()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("3");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 3");
        }
        else
        {
            mainDisplay->insert("3");
        }
    }
}

void normalCalculator::four()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("4");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 4");
        }
        else
        {
            mainDisplay->insert("4");
        }
    }
}

void normalCalculator::five()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("5");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 5");
        }
        else
        {
            mainDisplay->insert("5");
        }
    }
}

void normalCalculator::six()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("6");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 6");
        }
        else
        {
            mainDisplay->insert("6");
        }
    }
}

void normalCalculator::seven()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("7");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 7");
        }
        else
        {
            mainDisplay->insert("7");
        }
    }
}

void normalCalculator::eight()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("8");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 8");
        }
        else
        {
            mainDisplay->insert("8");
        }
    }
}

void normalCalculator::nine()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("9");
    }
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "*" || equation[lastPos] == "/"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 9");
        }
        else
        {
            mainDisplay->insert("9");
        }
    }
}

void normalCalculator::clear()
{
    mainDisplay->setText("");
}

void normalCalculator::exponent()
{
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    if(lastPos <= -1)
    {
        return;
    }
    if(equation[lastPos] == "+" || equation[lastPos] == "-" || equation[lastPos] == "*" || equation[lastPos] == "/")
    {

    }
    else
    {
        mainDisplay->insert("^");
    }
}

void normalCalculator::backspace()
{
    QString equation = mainDisplay->text();
    int secondLastPos = mainDisplay->text().length() - 2;
    if(mainDisplay->text().length() == 1)
    {
        mainDisplay->backspace();
    }
    if(secondLastPos < 0)
    {
        return;
    }
    if(equation[secondLastPos] == " ")
    {
        mainDisplay->backspace();
        mainDisplay->backspace();
    }
    else
    {
        mainDisplay->backspace();
    }
}

void normalCalculator::multiply()
{
    if(mainDisplay->text().length() == 0)
    {
        return;
    }
    mainDisplay->insert(" *");
}

void normalCalculator::divide()
{
    if(mainDisplay->text().length() == 0)
    {
        return;
    }
    mainDisplay->insert(" /");
}

void normalCalculator::add()
{
    if(mainDisplay->text().length() == 0)
    {
        return;
    }
    mainDisplay->insert(" +");
}

void normalCalculator::subtract()
{
    if(mainDisplay->text().length() == 0)
    {
        return;
    }
    mainDisplay->insert(" -");
}
