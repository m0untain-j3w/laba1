#include "str.h"
#include <fstream>
#include <iostream>
#include <locale.h>
#define BUFFER_SIZE 256

using namespace std;

void program(const char *);
bool checkBracket(char);
char getSecondBracket(char);

int main() {
  setlocale(LC_ALL, "ru_RU.UTF-8");

  program("file1.txt");
  program("file2.txt");
  program("file3.txt");
  program("file4.txt");
  program("file5.txt");
  program("file6.txt");

  return 0;
}

void program(const char *file_name) {

  char bracket1;
  char bracket2;
  String string;
  ifstream file_in(file_name);
  ofstream file_out("output.txt", ios::app);
  if (!file_in.is_open()) {
    cerr << "Ошибка при открытии входного файла..." << endl;
    return;
  }
  if (!file_out.is_open()) {
    cerr << "Ошибка при открытии выходного файла..." << endl;
    return;
  }

  file_in >> bracket1;
  if (!checkBracket(bracket1)) {
    file_out << "Скобка не дана. Пропускаю файл..." << endl;
    file_out << "-----------" << endl;
    return;
  }
  file_in.get();

  bracket2 = getSecondBracket(bracket1);

  string.readStringFromFile(file_in);
  if (string.getString()[0] == string.getMarker()) {
    file_out << "Получена пустая строка." << endl;
    file_out << "-----------" << endl;
    return;
  }

  string.removeBetweenBrackets(bracket1, bracket2);
  file_out << "Полученная строка: " << endl;
  string.printToFile(file_out);
  file_out << "-----------" << endl;

  file_in.close();
  file_out.close();
}

bool checkBracket(char bracket) {
  if (bracket == '(' || bracket == '{' || bracket == '[')
    return true;
  else
    return false;
}

char getSecondBracket(char bracket) {
  if (bracket == '(')
    return ')';
  if (bracket == '[')
    return ']';
  if (bracket == '{')
    return '}';

  cerr << "Скобка не получена! Возвращаю 0";
  return '0';
}
