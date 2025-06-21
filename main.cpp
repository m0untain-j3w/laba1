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
    
    cout << "Завершаю работу..." << endl;

    return 0;
}

void program(const char* file_name) {

    String string;
    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла..." << endl;
        return;
    }
    
    string.readMarkerFromFile(file);
    string.readLineFromFile(file);
    file.close();
    
    string.removeBetweenBrackets();
    cout << string.getString() << endl;
}