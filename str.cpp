#include "str.h"
#include <iostream>
#define BUFFER_SIZE 256

/* Конструкторы */
String::String() { str[0] = mrk; }

String::String(const char *string) { readString(string); }
/* Деструктор */
String::~String() {}

void String::removeBetweenBrackets(char bracket1, char bracket2) {
  /* Удаляет символы между указанными скобками */
  bool between_brackets = false;
  int write_index = 0;

  for (int i = 0; str[i] != mrk; i++) {
    if (str[i] == bracket1) {
      between_brackets = true;
      continue; // Пропускаем начальную скобку
    }

    if (between_brackets) {
      if (str[i] == bracket2) {
        between_brackets = false;
      }
      continue; // Пропускаем символы внутри скобок
    }

    // Если не внутри скобок — копируем символ
    str[write_index++] = str[i];
  }

  if (str[write_index-1] == ' ') {
    str[write_index-1] = mrk;
    return;
  }
  str[write_index] = mrk;
}
/* Запись строки */
void String::readString(const char *from_string) {

  int i = 0;
  for (; from_string[i] != '\n' && i < BUFFER_SIZE; i++) {
    str[i] = from_string[i];
  }
  str[i] = mrk;
}
/* Запись строки из файла */
void String::readStringFromFile(std::ifstream &file) {

  char file_string[BUFFER_SIZE];
  file.getline(file_string, BUFFER_SIZE);

  int i = 0;
  for (; file_string[i] != '\n' && file_string[i] != '\0' && i < BUFFER_SIZE; i++) {
    str[i] = file_string[i];
  }
  str[i] = mrk;
}
/* Вывод строки в файл*/
void String::printToFile(std::ofstream &file) const {
  for (int i = 0; str[i] != mrk && i < BUFFER_SIZE; i++) {
    file << str[i];
  }
  file << mrk << std::endl;
}
/* Геттеры */
char *String::getString() { return str; }
char String::getMarker() { return mrk; }
