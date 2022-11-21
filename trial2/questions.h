#ifndef QUESTIONS_H
#define QUESTIONS_H

#include "ui_easywindow.h"
#include "ui_mediumwindow.h"
#include <string>
#include <QLineEdit>
#include <QString>

class questions{
  private:
    std::string questionText;
    std::string optionOne;
    std::string optionTwo;
    std::string optionThree;
    std::string optionFour;
    int correctAnswer;
    int questionPoints;

  public:
    questions(std::string qstn, std::string optOne, std::string optTwo, std::string optThree, std::string optFour, int corrAns, int qP)
    {
        questionText = qstn;
        optionOne = optOne;
        optionTwo = optTwo;
        optionThree = optThree;
        optionFour = optFour;
        correctAnswer = corrAns;
        questionPoints = qP;
    }
    void askQuestion(Ui::easyWindow*);
};

questions eq1("Splitting a number into its factors or divisors", "Division", "Factorization", "Expression", "Multiplication", 2, 1);
questions eq2("Factor 10x^2 + x - 2.", "(5x+2)(2x-1)","(5x - 2)(2x + 1)", "(10x+1)(x-3)", "(5x-4)(2x+2)", 2, 1);
questions eq3("Factor 4x^2 + 12x + 5.", "()()", "()()", "(2x + 5)(2x + 1)", "()()", 3,1);
questions eq4("Factor x^2 + 5x", "x(x+5)", "(x+5)(x+x)", "(5)(x+1)", "(x^2)(1+5)", 1, 1);
questions eq5("","","","","",4,1);

void questions::askQuestion(Ui::easyWindow *easyWinUi){
    easyWinUi -> qstnLbl -> setText(QString::fromStdString(this->questionText));
    easyWinUi -> optnOne -> setText(QString::fromStdString(this->optionOne));
    easyWinUi -> optnTwo -> setText(QString::fromStdString(this->optionTwo));
    easyWinUi -> optnThree -> setText(QString::fromStdString(this->optionThree));
    easyWinUi -> optnFour -> setText(QString::fromStdString(this->optionFour));
};

class mques{
    void askMQues(Ui::mediumWindow*);
};

std::string medQarr[]={"x^4 + 2x^3 - 33x^2 - 50x + 200", "x^6 - 4x^5 - 73x^4 + 280x^3 + 1308x^2 - 5040x", "x^5 - 7x^4 + 12x^3 + 4x^2 - 16x", "x^4 - 2x^3 - 31x^2 - 28x", " x^5 + 3x^4 - 54x^3 - 108x^2 + 648x"};

void mques::askMQues(Ui::mediumWindow *medWinUi){
    for (int i=0; i<5; i++){
        medWinUi -> qstnLbl -> setText(QString::fromStdString(medQarr[i]));
    }
};


#endif // QUESTIONS_H
