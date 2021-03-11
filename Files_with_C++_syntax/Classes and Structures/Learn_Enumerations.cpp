#include <iostream>
#include <string>

/* Перечисление (или «перечисляемый тип») — это тип данных, 
где любое значение (или «перечислитель») определяется как символьная константа.
Объявить перечисление можно с помощью ключевого слова enum */

// Объявляем новое перечисление Colors
enum Colors
{
    // Ниже находятся перечислители - все возможные значения этого типа данных
    // Каждый перечислитель отделяется запятой (НЕ точкой с запятой)
    /* Каждому перечислителю присваивается значение. Обычно начинается с 0, 
    к каждому следующему прибавляется 1 (так работает и тогда, когда переменная 
    инициализировалась отдельно от остальных) */
    COLOR_YELLOW, // присваивается 0
	COLOR_WHITE, // присваивается 1
	COLOR_ORANGE, // присваивается 2
	COLOR_GREEN, // присваивается 3
	COLOR_RED = 10, // присваивается 10
	COLOR_GRAY, // присваивается 11
	COLOR_PURPLE, // присваивается 12
	COLOR_BROWN // присваивается 13
};
/* Совет: Не присваивайте свои значения перечислителям.
Правило: Не присваивайте одинаковые значения двум перечислителям 
в одном перечислении, если на это нет веской причины. */

// Можем сделать так, если мы хотим вывести названия перечислителей
// В ином случае у нас будут выводиться их целочисленные значения. 

// Рассмотрим полезность перечислителей, например, при выводе ошибок:
enum ParseResult
{
    SUCCESS = 0,
    ERROR_OPENING_FILE = -1,
    ERROR_PARSING_FILE = -2,
    ERROR_READING_FILE = -3
};
 
ParseResult readFileContents()
{
    if (!openFile())
        return ERROR_OPENING_FILE;
    if (!parseFile())
        return ERROR_PARSING_FILE;
    if (!readfile())
        return ERROR_READING_FILE;
 
    return SUCCESS; // если всё прошло успешно
}
 
enum ItemType
{
    ITEMTYPE_GUN,
    ITEMTYPE_ARBALET,
    ITEMTYPE_SWORD
};

std::string getItemName(ItemType itemType)
{
    if (itemType == ITEMTYPE_GUN)
        return std::string("Gun");
    if (itemType == ITEMTYPE_ARBALET)
        return std::string("Arbalet");
    if (itemType == ITEMTYPE_SWORD)
        return std::string("Sword");
}
 
void printColor(Colors color)
{
    if (color == COLOR_PURPLE)
        std::cout << "Purple";
    else if (color == COLOR_GRAY)
        std::cout << "Gray";
    else if (color == COLOR_GREEN)
        std::cout << "Green";
    else if (color == COLOR_BROWN)
        std::cout << "Brown";
    else if (color == COLOR_YELLOW)
        std::cout << "Yellow";
    else
        std::cout << "Who knows!";
}

int main(int argc, char *argv[])
{
    Colors paint = COLOR_RED;
    Colors house(COLOR_GRAY);
    std::cout << paint;

    std::cin.get();
    return 0;
}