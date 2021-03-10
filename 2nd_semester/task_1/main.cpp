/*
 Написать функцию, принимающую длину линии из звездочек, ее направление
 (вертикально/горизонтально), и рисующую ее в консоли. Написать функцию, 
 которая принимает ширину и высоту, и, используя предыдущую функцию, 
 рисует прямоугольник из звездочек. Определить свою функцию в отдельной 
 единице трансляции и вызывать ее из функции main.
 */

#include <iostream>
#include <iomanip>
#include <limits>

void line(int numSymbols, char orientation, int columns = 1, int spaces = 0);

void rectangle(int width, int height);

int main(int argc, char *argv[])
{
    std::cout << "Please enter the number of symbols:" << std::endl;

    int inpSymbols;
    std::cin >> inpSymbols;
    std::cin.clear();

    std::cout << "Please enter line orientation (v - vertically, "
              << "h - horizontally);" << std::endl;

    char inpOrientation;
    std::cin >> inpOrientation;
    std::cin.clear();

    line(inpSymbols, inpOrientation);

    std::cout << "Please enter the width of rectangle:" << std::endl;

    int widthRect;
    std::cin >> widthRect;
    std::cin.clear();

    std::cout << "Please enter the height of rectangle:" << std::endl;

    int heightRect;
    std::cin >> heightRect;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    rectangle(widthRect, heightRect);

    std::cout << "Please enter smth";

    std::cin.get();

    return 0;
}
