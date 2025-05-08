#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    // Создаем и заполняем двумерный массив
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int a, b, sum = 0;
    cout << "Введите начало интервала (a): ";
    cin >> a;
    cout << "Введите конец интервала (b): ";
    cin >> b;

    // Подсчет суммы элементов в интервале [a, b]
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] >= a && matrix[i][j] <= b) {
                sum += matrix[i][j];
            }
        }
    }

    cout << "Сумма элементов в интервале [" << a << ", " << b << "]: " << sum << endl;

    return 0;
}