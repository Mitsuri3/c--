#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Введите количество элементов: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Введите элементы массива: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int a, b, sum = 0;

    cout << "Введите начало интервала (a): ";
    cin >> a;
    cout << "Введите конец интервала (b): ";
    cin >> b;

    // Подсчет суммы элементов в интервале [a, b]
    for (int num : arr) {
        if (num >= a && num <= b) {
            sum += num;
        }
    }

    cout << "Сумма элементов в интервале [" << a << ", " << b << "]: " << sum << endl;

    return 0;
}