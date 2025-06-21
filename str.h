#ifndef STR_H
#define STR_H

#include <iostream>
#include <fstream>

#define BUFFER_SIZE 256


class String {
private:
    char str[BUFFER_SIZE];
    char mrk;

public:
    /* Конструктор */
    String();
    String(const char* string, char mark);
    /* Деструктор */
    ~String();
    /* Удаляет символы между указанными скобками*/
    void removeBetweenBrackets();
    /* Запись маркера*/
    void readMarkerFromFile(std::ifstream& file);
    /* Запись строки */
    void readLine(const char* from_string);
    /* Запись строки из файла*/
    void readLineFromFile(std::ifstream& file);
    /* Получение второго маркера */
    char getSecondMarker();
    /* Геттеры */
    char* getString();
    char getMarker();
};


#endif // STR_H