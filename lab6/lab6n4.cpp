#include <iostream>
#include <vector>

using namespace std;

int main() {
    int rows, cols;
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;

    // Создаем и заполняем исходный массив
    vector<vector<int>> matrix(rows, vector<int>(cols));
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    int threshold;
    cout << "Введите заданное число для сравнения: ";
    cin >> threshold;

    // Создаем массив для результатов
    vector<int> counts(rows);

    // Подсчитываем количество элементов > threshold для каждой строки
    for (int i = 0; i < rows; ++i) {
        int count = 0;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] > threshold) {
                count++;
            }
        }
        counts[i] = count;
    }

    // Выводим результаты
    cout << "Количество элементов больших " << threshold << " в каждой строке:\n";
    for (int i = 0; i < rows; ++i) {
        cout << "Строка " << i + 1 << ": " << counts[i] << endl;
    }

    return 0;
}