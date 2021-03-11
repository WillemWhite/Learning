#include <iostream>
/* Пространства имён созданы для решения конфликтов имён(когда, например,
одна и та же функция может называться одинаково, однако определена в разных
файлах, библиотеках и тд.). Сделано это, по видимому, для сокращения названий.
Это на самом деле упрощает работу. */

//пример пространства имён
namespace Add
{
    int doOperation(int a, int b)
    {
        return a - b;
    }
}

namespace Dif
{
    int doOperation(int a, int b)
    {
        return a - b;
    }
}

namespace Int
{
    /* Тут представлено вложенное пространство имён, так что обращаемся как
    Int::Div::intDivis(a,b) */
    namespace Div
    {
        int intDivis(int a, int b)
        {
            return a / b;
        }
    }
}

// Также мы можем одним пространствам имён присваивать другие (например вложенные)
namespace Inv = Int::Div;

/* Вложенность пространств имен не рекомендуется использовать, так как при 
неумелом использовании увеличивается вероятность возникновения ошибок 
и дополнительно усложняется логика программы. */

int main(int argc, char *argv[])
{
    int a = 2;
    int b = 3;

    /* '::' - оператор разрешения области видимости, его также можно
    использовать так: 
    ::doOperation 
    В таком случае мы ссылаемся на глобальное пространство имён */

    std::cout << "2 + 3 = ";
    std::cout << Add::doOperation(a,b) << std::endl;
    
    std::cout << "2 - 3 = ";
    std::cout << Dif::doOperation(a, b) << std::endl;

    std::cout << "2 / 3 = ";
    std::cout << Inv::intDivis(a, b) << " and " << Int::Div::intDivis(a, b)
              <<std::endl;

    std::cin.get();
    return 0;
}