#include <iostream>
#include "str.h"
#define BUFFER_SIZE 256

/* Конструкторы */
String::String() {}
String::String(const char* string, char mark) {
    mrk = mark;
    readLine(string);
}
/* Деструктор */
String::~String() {}
/* Удаляет символы между указанными скобками*/
void String::removeBetweenBrackets() {
    bool between_brackets = false;
    int write_index = 0;
    char mrk2 = getSecondMarker();

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == mrk) {
            between_brackets = true;
            continue; // Пропускаем начальную скобку
        }

        if (between_brackets) {
            if (str[i] == mrk2) {
                between_brackets = false;
            }
            continue; // Пропускаем символы внутри скобок
        }

        // Если не внутри скобок — копируем символ
        str[write_index++] = str[i];
    }

    str[write_index] = '\0';
}
/* Запись маркера*/
void String::readMarkerFromFile(std::ifstream& file) { 
    char string[BUFFER_SIZE];
    file.getline(string, BUFFER_SIZE);

    if (string[0] == '(') { mrk = '('; return; }
    if (string[0] == '{') { mrk = '{'; return; }
    if (string[0] == '[') { mrk = '['; return; }
}
/* Запись строки */
void String::readLine(const char* from_string) {

    int i = 0;
    for (; from_string[i] && i < BUFFER_SIZE; i++) {
        str[i] = from_string[i];
    }
    str[i] = '\0';
}
/* Запись строки из файла */
void String::readLineFromFile(std::ifstream& file) {

    char file_string[BUFFER_SIZE];
    file.getline(file_string, BUFFER_SIZE);

    int i = 0;
    for (;file_string[i] && file_string[i] != '\n' && i < BUFFER_SIZE; i++) {
        str[i] = file_string[i];
    }
    str[i] = '\0';
}
/* Получение второго маркера */
char String::getSecondMarker() {
    if (mrk == '(') { return ')';}
    if (mrk == '{') { return '}'; }
    if (mrk == '[') { return ']'; } 
    return '0';
}
/* Геттеры */
char* String::getString() { return str; }
char String::getMarker() { return mrk; }
