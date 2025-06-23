#ifndef STR_H
#define STR_H

#include <fstream>
#include <iostream>

#define BUFFER_SIZE 256

class String {
private:
  char str[BUFFER_SIZE];
  char mrk = '!';

public:
  /* Конструктор */
  String();
  String(const char *);
  /* Деструктор */
  ~String();
  /* Удаляет символы между указанными скобками */
  void removeBetweenBrackets(char, char);
  /* Запись строки из char* */
  void readString(const char *);
  /* Запись строки из файла */
  void readStringFromFile(std::ifstream &);
  /* Вывод строки */
  void printToFile(std::ofstream &) const;
  /* Геттеры */
  char *getString();
  char getMarker();
};

#endif // STR_H