/*
 Пользуясь рекуррентными формулами, вычислить значения многочлена степеней 
 от 0 до N при заданном значении аргумента X, принадлежащего области D. 
 Вычисление значений оформить в виде рекурсивной функции.
 U[n+1](x) = (1/(n+1)) * ((2*n+1-x)*U[n](x) - n*U[n-1](x))
 U[0](x) = 0
 U[1](x) = -x+1
 Область определения аргумента (D): x > 0
 Написать функцию тестирующую результат вычисления при помощи assert.
 Определить обе функции в отдельной единице трансляции. 
 Подключить объявления функций в main.cpp
 при помощи заголовочного файла.
 */
#include <iostream>
#include "pol.h"

int main(int argc, char *argv[])
{
    std::cout << "Please enter the degree and argument of the polynomial\n";

    std::cout << "Degree: ";

    int mainDegree;
    std::cin >> mainDegree;
    std::cin.clear();
    std::cout << "\n";

    std::cout << "Argument: ";

    float mainArgument;

    std::cin >> mainArgument;
    std::cin.clear();
    std::cout << "\n";

    inpConditions(mainDegree, mainArgument);
    testPolComputation();

    std::cout << "Your polynomial value: "
              << polComputation(mainDegree, mainArgument) << "\n";

    std::cin.get();
    std::cin.get();
    return 0;
}
