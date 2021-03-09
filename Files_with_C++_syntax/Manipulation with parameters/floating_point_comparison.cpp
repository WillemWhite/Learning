//вот таким fucking shit мы сравниваем числа с плавающей точкой до определенного знака после запятой.

#include <iostream>
#include <iomanip>

int main(int argc, char *argv[])
{
    double doubleX = 1;

    doubleX /= 52;

    long long longX;

    long long remainderLongX;

    std::cout << std::fixed << std::setprecision(10) << doubleX << std::endl;

    doubleX *= 10000000;

    longX = static_cast<long long>(doubleX);

    remainderLongX = longX % 10;

    if (remainderLongX >= 5)
    {
        longX /= 10;
        longX++;
    }
    else
        longX /= 10;

    std::cout << longX << std::endl;

    doubleX = static_cast<double>(longX);

    doubleX /= 1000000;

    std::cout << doubleX << std::endl;

    if (0.019231 == doubleX)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;

    std::cin.get();

    return 0;
}
