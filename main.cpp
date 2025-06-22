#include <iostream>
#include <fstream>
#include <locale.h>
#include "str.h"
#define BUFFER_SIZE 256

using namespace std;

void program(const char* file_name);

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

void program(const char* file_name) {

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
    
    string.readMarkerFromFile(file_in);
    if (!string.getMarker()) {
        file_out << "Пустой маркер! Пропускаю файл..." << endl;
        file_out << "-----------" << endl;
        return;
    }
    string.readLineFromFile(file_in);
    if (!string.getString()[0]) {
        file_out << "Получена пустая строка!" << endl;
        file_out << "-----------" << endl;
        return;
    }
    
    string.removeBetweenBrackets();
    file_out << "Полученная строка: " << endl;
    file_out << string.getString() << endl;
    file_out << "-----------" << endl;
    
    file_in.close();
    file_out.close();
}
