#include <iostream>
#include "Stack.hpp"

int main()
{
    std::string kurung = "";
    Stack::ArrayStatis<char> stack1;
    char temp;
    for (int a = 0; a < kurung.length(); a++)
    {
        if (stack1.isKosong())
        {
            stack1.push(kurung[a]);
        }
        else if (stack1.getTop() == '(' && kurung[a] == ')')
        {
            stack1.pop(temp);
        }
        else
        {
            stack1.push(kurung[a]);
        }
    }

    stack1.print();

    if (stack1.isKosong())
    {
        std::cout << "Cocok" << std::endl;
    }
    else
    {
        std::cout << "Lebih ato Kurang" << std::endl;
    }
    return 0;
}