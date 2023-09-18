#include <iostream>
#include <string>
#include <Windows.h>
#include<stack>

void getExpression(std::string& str)
{
    std::cout << "Enter a mathematical expression: ";
    std::cin >> str;
    if (str[str.size() - 1] != '=')
        throw "Error! Missing =";
}

int priority(char sign)
{
    switch(sign)
    {
        case '(':
            return 1;
        case '+':
            return 2;
        case '-':
            return 2;
        case '*':
            return 3;
        case '/':
            return 3;
        default:
            throw std::logic_error("Unintended operation!");
    }
}

std::string reversePolishNotation(const std::string& str)
{
    std::string outputStr = "";
    std::stack<char> operations;
    std::stack<char> openBrackets;
    int i = 0;
    while (str[i] != '=')
    {
        if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*')
        {
            while (!operations.empty() && priority(operations.top()) >= priority(str[i]))
            {
                outputStr += " "; //separating space
                outputStr += operations.top();
                operations.pop();
            }
            if (operations.empty() || priority(operations.top()) < priority(str[i]))
            {
                outputStr += " "; //separating space
                operations.push(str[i]);
            }
        }
        else if (str[i] == '(')
        {
            operations.push(str[i]);
            openBrackets.push(str[i]);
        }
        else if (str[i] == ')')
        {
            if (!openBrackets.empty())
                openBrackets.pop();
            else
                throw "Incorrect bracket sequence!";
            while (operations.top() != '(')
            {
                outputStr += " "; //separating space
                outputStr += operations.top();
                operations.pop();
            }
            operations.pop();
        }
        else
        {
            outputStr += str[i];
        }
        ++i;
    }
    while (!operations.empty()) //If there are operations, then we put it in the outputStr
    {
        outputStr += " "; //separating space
        outputStr += operations.top();
        operations.pop();
    }
    return outputStr;
}

void executeOperation(std::stack<double>& operands, char sign)
{
    double a = operands.top();
    operands.pop();
    double b = operands.top();
    operands.pop();
    switch(sign)
    {
        case '+':
            operands.push(b + a);
            break;
        case '-':
            operands.push(b - a);
            break;
        case '*':
            operands.push(b * a);
            break;
        case '/':
            operands.push(b / a);
            if (a == 0)
                throw std::logic_error("Division by zero!");
            break;
    }
}

double calc(const std::string& expr)
{
    std::stack<double> operands;
    std::string number = "";
    for (int i = 0; i < expr.size(); ++i)
    {
        if (isdigit(expr[i]) > 0)
        {
            number += expr[i];
        }
        else
        {
            if (!number.empty())
            {
                operands.push(std::stod(number));
                number = "";
            }
            if (expr[i] == ' ')
                continue;
            else
                executeOperation(operands, expr[i]);
        }
    }
    return operands.top();
}

int main()
{
    std::setlocale(LC_ALL, "RUS");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    try
    {
        std::string mathExpression;
        getExpression(mathExpression);
        std::cout << calc(reversePolishNotation(mathExpression)) << "\n";
    }
    catch (std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }
    catch (const char* msg)
    {
        std::cout << msg << "\n";
    }
    return 0;
}
