#include <iostream>
#include <fstream>
#include <locale.h>
#include "str.h"
#define BUFFER_SIZE 256

using namespace std;

void removeBetweenBrackets(char* string, char bracket1, char bracket2);
void program(const char* file_name);

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    program("file1.txt");
    program("file2.txt");
    program("file3.txt");\
    
    cout << "Завершаю работу..." << endl;

    return 0;
}

void program(const char* file_name) {

    ifstream file(file_name);
    if (!file.is_open()) {
        cerr << "Ошибка при открытии файла..." << endl;
        return;
    }

    char string[BUFFER_SIZE];
    char brackets[BUFFER_SIZE];

    if (!file.getline(brackets, BUFFER_SIZE)) {
        cerr << "Ошибка при чтении строки из файла" << endl;
        return;
    }
    if (!file.getline(string, BUFFER_SIZE)) {
        cerr << "Ошибка при чтении строки из файла" << endl;
        return;
    }
    file.close();

    removeBetweenBrackets(string, brackets[0], brackets[1]);
    cout << "Получившая строка:\n" << string << endl;
    cout << "Нажмите любую клавишу, чтобы продолжить" << endl;
    cin.get();
}

void removeBetweenBrackets(char* string, char bracket1, char bracket2) {
    
    if (!string) return;

    bool between_brackets = false;
    int write_index = 0;

    for (int i = 0; string[i] != '\0'; ++i) {
        if (string[i] == bracket1) {
            between_brackets = true;
            continue; // Пропускаем начальную скобку
        }

        if (between_brackets) {
            if (string[i] == bracket2) {
                between_brackets = false;
            }
            continue; // Пропускаем символы внутри скобок
        }

        // Если не внутри скобок — копируем символ
        string[write_index++] = string[i];
    }

    string[write_index] = '\0';
}