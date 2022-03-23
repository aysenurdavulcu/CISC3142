

#include <iostream>
#include <math.h>
using namespace std;

struct Calculator
{

    //constructors
    Calculator() //default
    {
        op1 = 0;
        op2 = 0;
        Operator = 0;
    }
    Calculator(double o1, double o2, int Operator)
    {
        op1 = o1;
        op2 = o2;
        this->Operator = Operator;
    }
    Calculator(double o1, double o2, char Op)
    {
        op1 = o1;
        op2 = o2;
        setOperator(Op);
    }

    //getters
    double getOperand1()
    {
        return op1;
    }
    double getOperand2()
    {
        return op2;
    }
    int getOperator()
    {
        return Operator;
    }
    char getOperatorCharacter() //returns the operator in character format rather than in the enum format
    {
        switch (this->Operator)
        {
        case 0:
            return '+';
            break;
        case 1:
            return '-';
            break;
        case 2:
            return '/';
            break;
        case 3:
            return '*';
            break;
        case 4:
            return 's';
            break;
        default:
            cerr << "Invalid operator" << endl;
            break;
        }
    }

    //setters
    void setOperand1(double value)
    {
        op1 = value;
    }
    void setOperand2(double value)
    {
        op2 = value;
    }
    void setOperator(char op)
    {
        switch (op)
        {
        case '+':
            Operator = plus;
            break;
        case '-':
            Operator = minus;
            break;
        case '/':
            Operator = divide;
            break;
        case '*':
            Operator = multiply;
            break;
        case 's':
            Operator = squareRoot;
            break;
        default:
            cerr << "Invalid operator" << endl;
            break;
        }
    }

    //Utility functions
    double Calculate() //calculates the result
    {
        switch (this->Operator)
        {
        case 0:
            return op1 + op2;
            break;
        case 1:
            return op1 - op2;
            break;
        case 2:
            if (op2 == 0) //error case
            {
                cout << "Second Operand is invalid for division" << endl;
                return 0;
            }
            return op1 / op2;
            break;
        case 3:
            return op1 * op2;
            break;
        case 4:
            cout << "Displaying Square root of First Operand" << endl;
            return sqrt(op1);
            break;
        default:
            cerr << "Invalid operator" << endl;
            break;
        }
    }
    void Display() //displays the result in a proper format
    {
        if (this->Operator != squareRoot)
        {
            cout << this->getOperand1() << " " << this->getOperatorCharacter() << " " << this->getOperand2() << " = " << this->Calculate() << endl;
        }
        else
        {
            cout << this->getOperatorCharacter() << " " << this->getOperand1() << " " << " = " << this->Calculate() << endl;
        }
    }
    private:
    double op1;
    double op2;
    int Operator;
    enum Operators { plus = 0, minus = 1, divide = 2, multiply = 3, squareRoot = 4 };

};

int main()
{
    //calculator 1
    Calculator C;
    C.setOperand1(5);
    C.setOperand2(4);
    C.setOperator('/');
    C.Display();

    //calculator 2
    Calculator C2(5, 0, '/');
    C2.Display();

    //calculator 3
    Calculator C3(9, 3, 0);
    C3.Display();
    return 0;
}

