#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Введите размер массива n x n: ";
    cin >> n;

    // Создаем и заполняем массив
    vector<vector<int>> arr(n, vector<int>(n));
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
        }
    }

    // Если количество строк четное - меняем местами
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            swap(arr[i], arr[i + 1]);
        }
    }

    // Выводим результат
    cout << "Результат:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}