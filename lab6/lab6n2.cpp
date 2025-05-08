#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов массива: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Введите элементы массива:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    // Находим позиции минимального и максимального элементов
    int min_pos = 0, max_pos = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[min_pos]) min_pos = i;
        if (arr[i] > arr[max_pos]) max_pos = i;
    }

    // Проверяем единственность min и max
    int count_min = 0, count_max = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] == arr[min_pos]) count_min++;
        if (arr[i] == arr[max_pos]) count_max++;
    }

    if (count_min != 1 || count_max != 1) {
        cout << "Ошибка: минимальный или максимальный элемент не единственный!\n";
        return 1;
    }

    // Определяем левую и правую границу
    int left = min_pos < max_pos ? min_pos : max_pos;
    int right = min_pos > max_pos ? min_pos : max_pos;

    // Сумма элементов между left и right (не включая их)
    int sum = 0;
    for (int i = left + 1; i < right; ++i) {
        sum += arr[i];
    }

    cout << "Сумма элементов между минимальным и максимальным: " << sum << endl;

    return 0;
}