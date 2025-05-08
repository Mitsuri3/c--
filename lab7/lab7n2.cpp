#include <iostream>
#include <string>
#include <algorithm> // Для использования функций sort, unique и erase

using namespace std;

int main() {
    string input;
    cout << "Введите строку: ";
    getline(cin, input); // Считываем всю строку, включая пробелы

    // sort сортирует символы
    sort(input.begin(), input.end());

    // unique перемещает уникальные элементы в начало строки
    // и возвращает итератор на конец нового диапазона
    auto last = unique(input.begin(), input.end());

    // erase удаляет элементы от last до конца строки
    input.erase(last, input.end());

    cout << "Количество различных символов: " << input.size() << endl;
    
    cout << "Уникальные символы: " << input << endl;

    return 0;
}