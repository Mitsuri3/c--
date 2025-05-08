#include <iostream>
#include <string>
#include <cctype> // для isdigit()

using namespace std;

int main() {
    string expression;
    cout << "Введите выражение (например, '1-2+3-4'): ";
    getline(cin, expression);

    int result = 0;
    int sign = 1; // Начинаем с положительного знака (первое число прибавляется)
    int currentNumber = 0;

    for (char ch : expression) {
        if (isdigit(ch)) {
            currentNumber = ch - '0'; // Преобразуем символ цифры в число
            result += sign * currentNumber;
        } else if (ch == '+') {
            sign = 1; // Следующее число будет прибавляться
        } else if (ch == '-') {
            sign = -1; // Следующее число будет вычитаться
        }
        
    }

    cout << "Результат: " << result << endl;
    return 0;
}