#include <iostream>
#include "polynomial.h"
#include <vector>
#include <limits>

int main() {
    // Создаем массив многочленов
    std::vector<Polynomial> polynomials;
    
    // Добавляем несколько многочленов
    polynomials.emplace_back(2, std::vector<double>{1, -3, 2});  // x^2 - 3x + 2
    polynomials.emplace_back(3, std::vector<double>{2, 0, -5, 7}); // 2x^3 - 5x + 7
    polynomials.emplace_back(1, std::vector<double>{-1, 4});      // -x + 4
    polynomials.emplace_back(0, std::vector<double>{5});          // 5
    
    // Выводим многочлены на экран
    std::cout << "Многочлены в массиве:" << std::endl;
    for (const auto& poly : polynomials) {
        poly.print();
    }

    // Ввод значения x с клавиатуры
    double x;
    std::cout << "\nВведите значение x для вычисления: ";
    std::cin >> x;
    
    // Демонстрация вычисления значения
    std::cout << "\nВычисление значений для x = " << x << ":" << std::endl;
    for (const auto& poly : polynomials) {
        std::cout << "P(x) = ";
        poly.print();
        std::cout << "P(" << x << ") = " << poly.evaluate(x) << "\n" << std::endl;
    }
    
    return 0;
}

//Запуск
//g++ -o polynomial_program polynomial.cpp main.cpp
//./polynomial_program