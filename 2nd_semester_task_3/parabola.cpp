#include <iostream>
#include <cassert>

const int SIZE = 100;

struct Parabola
{
    double a;
    double b;
    double c;
};

struct ArrParabolas
{
    Parabola arrParabolas[SIZE];
};

/*#pragma pack(push, 1) - мог бы использовать принудительное выравнивание 
в 1 байт перед описанием структуры,*/
struct MinAndParabola
{
    int countMin = 0;

    Parabola parabolaMax = {0, 0, 0};
};
/*#pragma pack(pop) - и далее убирать это выравнивание, чтобы не было 
проблем с иными библиотеками; дабы сжать размер данной структуры.
но у нас она не слишком большого размера, так что пока воздержусь, 
в будущем буду использовать по необходимости.*/

double compValueOfParabolaInMin(Parabola parabola)
{
    double a = parabola.a;
    double b = parabola.b;
    double c = parabola.c;

    return (a * ((b * b) / (4 * a * a)) + b * ((-b) / (2 * a)) + c);
}

ArrParabolas inputParabolas(int number)
{
    Parabola enteredParabola;
    ArrParabolas arrayParab;

    for (int i = 0; i < number; ++i)
    {
        std::cout << "Enter the coefficients a, b, c of the " << i + 1
                  << " parabola separated by a space." << std::endl;

        std::cin >> enteredParabola.a >> enteredParabola.b >> enteredParabola.c;
        std::cout << std::endl;
        std::cin.clear();

        arrayParab.arrParabolas[i] = enteredParabola;
    }

    return arrayParab;
}

MinAndParabola computMinimum(Parabola array[100], int number)
{
    MinAndParabola countMinAndMaxParabola;

    for (int i = 0; i < number; ++i)
    {
        // если а > 0, то парабола имеет минимум.

        if (countMinAndMaxParabola.countMin == 0 && array[i].a > 0)
        {
            countMinAndMaxParabola.countMin++;
            countMinAndMaxParabola.parabolaMax = array[i];
        }
        else if (array[i].a > 0 &&
                 compValueOfParabolaInMin(countMinAndMaxParabola.parabolaMax) <
                     compValueOfParabolaInMin(array[i]))
        {
            countMinAndMaxParabola.countMin++;
            countMinAndMaxParabola.parabolaMax = array[i];
        }
        else if (array[i].a > 0)
            countMinAndMaxParabola.countMin++;
    }

    return countMinAndMaxParabola;
}

void testComputMinimum()
{
    Parabola arrayPar1[SIZE];
    arrayPar1[0] = {-1, 2, 4};
    arrayPar1[1] = {3, 5, 6};
    arrayPar1[2] = {3, 6, 9};
    arrayPar1[3] = {5, 4, 3};
    assert(computMinimum(arrayPar1, 4).countMin == 3 &&
           computMinimum(arrayPar1, 4).parabolaMax.a == arrayPar1[2].a &&
           computMinimum(arrayPar1, 4).parabolaMax.b == arrayPar1[2].b &&
           computMinimum(arrayPar1, 4).parabolaMax.c == arrayPar1[2].c);
    Parabola arrayPar2[SIZE];
    arrayPar2[0] = {0, 8, 9};
    arrayPar2[1] = {2, 3, 0};
    arrayPar2[2] = {7, 8, -3};
    arrayPar2[3] = {10, 9, -20};
    arrayPar2[4] = {5, 7, 40};
    assert(computMinimum(arrayPar2, 5).countMin == 4 &&
           computMinimum(arrayPar2, 5).parabolaMax.a == arrayPar2[4].a &&
           computMinimum(arrayPar2, 5).parabolaMax.b == arrayPar2[4].b &&
           computMinimum(arrayPar2, 5).parabolaMax.c == arrayPar2[4].c);
    Parabola arrayPar3[SIZE];
    arrayPar3[0] = {-2, 4, 5};
    arrayPar3[1] = {40, 5, 2};
    arrayPar3[2] = {10, 12.3, 45};
    assert(computMinimum(arrayPar3, 3).countMin == 2 &&
           computMinimum(arrayPar3, 3).parabolaMax.a == arrayPar3[2].a &&
           computMinimum(arrayPar3, 3).parabolaMax.b == arrayPar3[2].b &&
           computMinimum(arrayPar3, 3).parabolaMax.c == arrayPar3[2].c);
    Parabola arrayPar4[SIZE];
    arrayPar4[0] = {31, 5, -20};
    arrayPar4[1] = {31, 5, -19};
    arrayPar4[2] = {6, 9, 20};
    arrayPar4[3] = {7, 8, 5};
    arrayPar4[4] = {6, 9, 21};
    arrayPar4[5] = {6, -10, 21};
    assert(computMinimum(arrayPar4, 6).countMin == 6 &&
           computMinimum(arrayPar4, 6).parabolaMax.a == arrayPar4[4].a &&
           computMinimum(arrayPar4, 6).parabolaMax.b == arrayPar4[4].b &&
           computMinimum(arrayPar4, 6).parabolaMax.c == arrayPar4[4].c);
    Parabola arrayPar5[SIZE];
    arrayPar5[0] = {0.5, 2, 1};
    arrayPar5[1] = {-0.5, 2, 1};
    arrayPar5[2] = {3, 10, -4};
    arrayPar5[3] = {3, 10, -5};
    arrayPar5[4] = {4, 6, 8};
    arrayPar5[5] = {4, 6, 7};
    assert(computMinimum(arrayPar5, 6).countMin == 5 &&
           computMinimum(arrayPar5, 6).parabolaMax.a == arrayPar5[4].a &&
           computMinimum(arrayPar5, 6).parabolaMax.b == arrayPar5[4].b &&
           computMinimum(arrayPar5, 6).parabolaMax.c == arrayPar5[4].c);
}
