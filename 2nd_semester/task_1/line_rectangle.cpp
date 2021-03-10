#include <iostream>
#include <iomanip>

void line(int numSymbols, char orientation, int columns = 1, int spaces = 0)
{
    if (orientation == 'h')
    {

        for (int i = 0; i < numSymbols; ++i)
            std::cout << std::setw(2) << '*';

        std::cout << std::endl;
    }

    else if (orientation == 'v')
    {

        for (int i = 0; i < numSymbols; ++i)
        {

            for (int j = 0; j < columns; ++j)
            {

                std::cout << std::setw(2) << '*';

                for (int k = 0; k < spaces; ++k)
                    std::cout << std::setw(2) << ' ';
            }

            std::cout << std::endl;
        }
    }

    else
    {
        std::cout << std::endl
                  << "wrong input..." << std::endl;
    }
}

void rectangle(int width, int height)
{
    line(width, 'h');
    line(height - 2, 'v', 2, width - 2);
    line(width, 'h');
}
