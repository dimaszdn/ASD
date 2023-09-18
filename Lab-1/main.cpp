#include <iostream>
#include<Windows.h>
#include<stack>

void getSequence(std::string& str)
{
    std::setlocale(LC_ALL, "RUS");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::cout << "Enter the bracket sequence: ";
    std::cin >> str;
}

bool checkSumBrackets(char a, char b) //sum ( + ) = 81; { + } = 248; [ + ] = 184
{
    if (a + b == 81 || a + b == 248 || a + b == 184)
        return true;
    else
        return false;
}

void checkRightSequence(std::string& str)
{
    std::stack<char> openBrackets;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(' || str[i] == '{' || str[i] == '[')
            openBrackets.push(str[i]);
        else
        {
            if (!openBrackets.empty() && checkSumBrackets(openBrackets.top(), str[i]))
                openBrackets.pop();
            else
            {
                std::cout << "The string does not exist!" << "\n";
                return;
            }
        }
    }
    if (openBrackets.empty())
        std::cout << "The string exist!" << "\n";
    else
        std::cout << "The string does not exist!" << "\n";
}

int main()
{
    std::string sequence;
    getSequence(sequence);
    checkRightSequence(sequence);
    return 0;
}