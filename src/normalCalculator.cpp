#include <QGridLayout>
#include <QPushButton>
#include <QApplication>
#include <QLineEdit>
#include <iostream>
#include <string.h>
#include <cmath>

#include "headers/normalCalculator.h"
#include "headers/numButton.h"

normalCalculator::normalCalculator(QWidget *parent) : QWidget(parent)
{
setStyleSheet("numButton { background-color:#7dc383; border-color: none; border:none; font: large 'Helvetica'; font-size: 21px; color:#555555; } numButton:hover { background-color:#d0e1f9; } numButton:pressed { background-color: #2a4d69; color: white; }");
//creates layouts and sets options for the layout.
QVBoxLayout *vert = new QVBoxLayout(this);

//grid layout for calculator buttons.
QGridLayout *layout = new QGridLayout();
layout->setSpacing(4);
//creates the main display for input and output.
mainDisplay = new QLineEdit(this);

vert->addWidget(mainDisplay);

//QList<QString> values({"C","^","+/-","<-","7","8","9","x","4","5","6","/","1","2","3","+","(","0",")","-","Up",".","Down","="});

//section is going to be removed soon.
/*
int iter = 0;

for(int i = 0; i < 6; i++)
{
    for(int j = 0; j < 4; j++)
    {
        QPushButton *but = new QPushButton("\n \n" + values[iter] + "\n \n", this);
        QPalette pal = palette();
        pal.setColor(QPalette::Background, Qt::black);
        but->setAutoFillBackground(true);
        but->setPalette(pal);
        but->setStyleSheet("background:#03396c;border:0px;");
        layout->addWidget(but, i, j);
        iter++;
    }
}
*/

//end of outdated useless section.

//creates the buttons.
numButton *oneButton = new numButton();
oneButton->setText("\n1\n");
numButton *clearButton = new numButton();
clearButton->setText("\nC\n");
numButton *expoButton = new numButton();
expoButton->setText("\n^\n");
numButton *backspaceButton = new numButton();
backspaceButton->setText("\n←\n");
numButton *sevenButton = new numButton();
sevenButton->setText("\n7\n");
numButton *eightButton = new numButton();
eightButton->setText("\n8\n");
numButton *nineButton = new numButton();
nineButton->setText("\n9\n");
numButton *multiplyButton = new numButton();
multiplyButton->setText("\n✕\n");
numButton *fourButton = new numButton();
fourButton->setText("\n4\n");
numButton *fiveButton = new numButton();
fiveButton->setText("\n5\n");
numButton *sixButton = new numButton();
sixButton->setText("\n6\n");
numButton *divideButton = new numButton();
divideButton->setText("\n÷\n");
numButton *twoButton = new numButton();
twoButton->setText("\n2\n");
numButton *threeButton = new numButton();
threeButton->setText("\n3\n");
numButton *plusButton = new numButton();
plusButton->setText("\n+\n");
numButton *zeroButton = new numButton();
zeroButton->setText("\n0\n");
numButton *subtractButton = new numButton();
subtractButton->setText("\n-\n");
numButton *decimalButton = new numButton();
decimalButton->setText("\n.\n");
numButton *solveButton = new numButton();
solveButton->setText("\n=\n");
numButton *swapSigns = new numButton();
swapSigns->setText("\n+/-\n");
numButton *leftPar = new numButton();
leftPar->setText("\n(\n");
numButton *rightPar = new numButton();
rightPar->setText("\n)\n");
numButton *scrollUp = new numButton();
scrollUp->setText("\nUp\n");
numButton *scrollDown = new numButton();
scrollDown->setText("\nDown\n");

//adds button to the grid layout.
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
layout->addWidget(decimalButton, 5, 1);
layout->addWidget(solveButton, 5, 3);
layout->addWidget(swapSigns, 0, 2);
layout->addWidget(leftPar, 4, 0);
layout->addWidget(rightPar, 4, 2);
layout->addWidget(scrollUp, 5, 0);
layout->addWidget(scrollDown, 5, 2);

//connects buttons to the slots so that they actually do something when pressed.
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
connect(decimalButton, &QPushButton::clicked, this, &normalCalculator::decimal);
connect(solveButton, &QPushButton::clicked, this, &normalCalculator::solve);

//style sheet stuff
mainDisplay->setStyleSheet("border-radius: 4px; padding: 15px; background-color:#fff1bc; font: large 'Museo Sans'; font-size: 21px;");

//adds the grid layout to the overall main layout.
vert->addLayout(layout);

//sets the main layout of the widget to the overall layout.
setLayout(vert);

}

//slot for the zero button. The buttons I have are mostly copy pastes of each other.
void normalCalculator::zero()
{
    //gets the equation and the position of the last character.
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length() - 1;
    //If there is nothing in the equation, print only the character.
    if(mainDisplay->text().length() == 0)
    {
        mainDisplay->insert("0");
    }
    //if the last character is an operation, add a space before. Else add nothing.
    else if(lastPos >= 0)
    {
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
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
        if(equation[lastPos] == "✕" || equation[lastPos] == "÷"  || equation[lastPos] == "+" || equation[lastPos] == "-")
        {
            mainDisplay->insert(" 9");
        }
        else
        {
            mainDisplay->insert("9");
        }
    }
}

//clears equation.
void normalCalculator::clear()
{
    mainDisplay->setText("");
}

//adds exponent
void normalCalculator::exponent()
{
    QString equation = mainDisplay->text();
    if(equation.length() == 0)
    {
        return;
    }
    int lastPos = mainDisplay->text().length() - 1;
    int lastBlank = 0;
    for(int i = 0; i < lastPos; i++)
    {
        if(equation[i] == " ")
        {
            lastBlank = i;
        }
    }
    for(int i = lastBlank; i <= lastPos; i++)
    {
        if(equation[i] == "^")
        {
            return;
        }
    }
    if(equation[lastPos] == "+" || equation[lastPos] == "-" || equation[lastPos] == "✕" || equation[lastPos] == "÷")
    {
        return;
    }
    mainDisplay->insert("^");
}

void normalCalculator::decimal()
{
    QString equation = mainDisplay->text();
    if(equation.length() == 0)
    {
        return;
    }
    int lastPos = mainDisplay->text().length() - 1;
    int lastBlank = 0;
    for(int i = 0; i < lastPos; i++)
    {
        if(equation[i] == " ")
        {
            lastBlank = i;
        }
    }
    for(int i = lastBlank; i <= lastPos; i++)
    {
        if(equation[i] == ".")
        {
            return;
        }
    }
    if(equation[lastPos] == "+" || equation[lastPos] == "-" || equation[lastPos] == "✕" || equation[lastPos] == "÷")
    {
        mainDisplay->insert(" .");
        return;
    }
    mainDisplay->insert(".");
}

//Clears last entered.
void normalCalculator::backspace()
{
    //checks if it is an operation. If not operation, delete one. Otherwise delete two.
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

//Inserts multiplication symbol. If nothing is there, do nothing. Same for the rest.
void normalCalculator::multiply()
{
    QString equation = mainDisplay->text();
    if(mainDisplay->text().length() == 0)
    {
        return;
    }
    if(mainDisplay->text().length() >= 2)
    {
        int secondLastPos = mainDisplay->text().length() - 1;
        if(equation[secondLastPos] == "+" || equation[secondLastPos] == "-" || equation[secondLastPos] == "✕" || equation[secondLastPos] == "÷" || equation[secondLastPos] == "^")
        {
            return;
        }
    }
    mainDisplay->insert(" ✕");
}

void normalCalculator::divide()
{
    QString equation = mainDisplay->text();
    if(mainDisplay->text().length() == 0)
    {
        return;
    }
    if(mainDisplay->text().length() >= 2)
    {
        int secondLastPos = mainDisplay->text().length() - 1;
        if(equation[secondLastPos] == "+" || equation[secondLastPos] == "-" || equation[secondLastPos] == "✕" || equation[secondLastPos] == "÷" || equation[secondLastPos] == "^")
        {
            return;
        }
    }
    mainDisplay->insert(" ÷");
}

void normalCalculator::add()
{
    QString equation = mainDisplay->text();
    if(mainDisplay->text().length() == 0)
    {
        return;
    }
    if(mainDisplay->text().length() >= 2)
    {
        int secondLastPos = mainDisplay->text().length() - 1;
        if(equation[secondLastPos] == "+" || equation[secondLastPos] == "-" || equation[secondLastPos] == "✕" || equation[secondLastPos] == "÷" || equation[secondLastPos] == "^")
        {
            return;
        }
    }
    mainDisplay->insert(" +");
}

void normalCalculator::subtract()
{
    QString equation = mainDisplay->text();
    if(mainDisplay->text().length() == 0)
    {
        return;
    }
    if(mainDisplay->text().length() >= 2)
    {
        int secondLastPos = mainDisplay->text().length() - 1;
        if(equation[secondLastPos] == "+" || equation[secondLastPos] == "-" || equation[secondLastPos] == "✕" || equation[secondLastPos] == "÷" || equation[secondLastPos] == "^")
        {
            return;
        }
    }
    mainDisplay->insert(" -");
}

void normalCalculator::solve()
{
    QList<QString> splitEquation;
    QString equation = mainDisplay->text();
    int lastPos = mainDisplay->text().length();
    QString temp = "";
    QStringList stepOne = equation.split(" ");
    for(int i = 0; i < stepOne.length(); i++)
    {
        splitEquation.insert(i, stepOne[i]);
    }
    //exits if the input cannot be solved.
    if(equation[lastPos-1] == "+" || equation[lastPos-1] == "-" || equation[lastPos-1] == "✕" || equation[lastPos-1] == "÷")
    {
        return;
    }
    //Does exponents first. The pemdas method I'm doing is quick and cheap.

    for(int i = 0; i < splitEquation.length(); i++)
    {
        if(splitEquation[i].contains("^"))
        {
            QString temp = splitEquation[i];
            QStringRef sideOne(&temp, 0, temp.indexOf("^"));
            QStringRef sideTwo(&temp, temp.indexOf("^")+1, temp.length()-temp.indexOf("^")-1);
            double result = pow(sideOne.toDouble(), sideTwo.toDouble());
            splitEquation[i] = QString::number(result);
        }
    }

    //multiplication and division

    for(int i = 0; i < splitEquation.length();)
    {
        if(splitEquation[i] == "✕")
        {
            double numOne = splitEquation[i-1].toDouble();
            double numTwo = splitEquation[i+1].toDouble();
            double result = numOne * numTwo;
            splitEquation[i] = QString::number(result);
            splitEquation.removeAt(i+1);
            splitEquation.removeAt(i-1);
            i--;
        }
        else if(splitEquation[i] == "÷")
        {
            double numOne = splitEquation[i-1].toDouble();
            double numTwo = splitEquation[i+1].toDouble();
            double result = numOne / numTwo;
            splitEquation[i] = QString::number(result);
            splitEquation.removeAt(i+1);
            splitEquation.removeAt(i-1);
            i--;
        }
        else
        {
            i++;
        }
    }

    //add and subtract

    for(int i = 0; i < splitEquation.length();)
    {
        if(splitEquation[i] == "+")
        {
            double numOne = splitEquation[i-1].toDouble();
            double numTwo = splitEquation[i+1].toDouble();
            double result = numOne + numTwo;
            splitEquation[i] = QString::number(result);
            splitEquation.removeAt(i+1);
            splitEquation.removeAt(i-1);
            i--;
        }
        else if(splitEquation[i] == "-")
        {
            double numOne = splitEquation[i-1].toDouble();
            double numTwo = splitEquation[i+1].toDouble();
            double result = numOne - numTwo;
            splitEquation[i] = QString::number(result);
            splitEquation.removeAt(i+1);
            splitEquation.removeAt(i-1);
            i--;
        }
        else
        {
            i++;
        }
    }

    QString endResult;

    //turns results into a single string
    for(int i = 0; i < splitEquation.length(); i++)
    {
        endResult += splitEquation[i];
    }


    //debug thingy
    mainDisplay->setText(endResult);
}
