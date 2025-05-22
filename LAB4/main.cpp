#include "polynomial.h"
#include <vector>

// Основная программа для демонстрации работы классов
int main() {
    // Создаем массив указателей на базовый класс
    std::vector<Polynomial*> polynomials;

    // Создаем объекты производных классов
    std::vector<double> coeffs1 = { -7, 0, 5, 2 }; // 2x^3 + 5x^2 - 7
    std::vector<double> coeffs2 = { 0, 1, 2, 4 };  // 4x^3 + 2x^2 + x

    polynomials.push_back(new StandardPolynomial(3, coeffs1));
    polynomials.push_back(new NormalizedPolynomial(3, coeffs2));

    // Демонстрация полиморфизма
    std::cout << "Polynomials:\n";
    for (const auto* poly : polynomials) {
        std::cout << *poly; // Вызов перегрузки оператора <<, которая использует виртуальный метод print
        std::cout << "Value at x = 2: " << poly->evaluate(2) << "\n\n";
    }

    // Освобождение памяти
    for (auto* poly : polynomials) {
        delete poly;
    }

    return 0;
}