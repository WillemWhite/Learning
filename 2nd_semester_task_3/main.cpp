/*
 Создать структуру «Парабола» с элементами a, b, c – коэффициенты уравнения 
 y=ax^2+bx+c. Определить для N заданных парабол m – количество парабол, 
 имеющих минимум, и если такие есть, найти, у какой из них минимум функции 
 наибольший, т. е парабола расположена выше остальных. Создать тесты, 
 проверяющие корректность работы реализованных функций. Определение структуры
 и объявление функций для работы с ней выполнить в отдельном заголовочном
 файле. Определение функций выполнить в отдельной единице трансляции.
 */
#include <iostream>
#include <limits>
#include "parb.h"

int main(int argc, char *argv[])
{
    testComputMinimum();

    std::cout << "Enter number of parabolas(limit = 100): ";

    int size;

    std::cin >> size;

    std::cin.clear();

    std::cout << std::endl;

    MinAndParabola outParabola = computMinimum(inputParabolas(size).arrParabolas, size);

    if (outParabola.countMin)
    {
        std::cout << "Among the given " << outParabola.countMin
                  << " parabolas has a minimum." << std::endl;
        std::cout << outParabola.parabolaMax.a << "x^2 + ("
                  << outParabola.parabolaMax.b << ")x + ("
                  << outParabola.parabolaMax.c << ") - the minimum "
                  << "point of this parabola is maximum among the given."
                  << std::endl
                  << std::endl;
    }
    else
        std::cout << "There are no parabolas with a minimum among the given."
                  << std::endl
                  << std::endl;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter smth to quit." << std::endl;
    std::cin.get();

    return 0;
}
