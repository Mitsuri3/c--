#include <iostream>
#include "polynomial.h"
#include <vector>

int main() {
    // 1. Демонстрация работы конструкторов
    std::cout << "=== Демонстрация конструкторов ===" << std::endl;
    
    // Конструктор по умолчанию (степень 0, коэффициент 0)
    Polynomial p0;
    std::cout << "p0 (по умолчанию): ";
    p0.print();
    
    // Конструктор с указанием степени (все коэффициенты 0)
    Polynomial p1(2); // 0x² + 0x + 0
    std::cout << "p1 (степень 2): ";
    p1.print();
    
    // Конструктор с указанием степени и коэффициентов
    Polynomial p2(3, {1, 0, -2, 3.5}); // x³ - 2x + 3.5
    std::cout << "p2: ";
    p2.print();
    
    // Конструктор копирования
    Polynomial p3 = p2; // Копия p2
    std::cout << "p3 (копия p2): ";
    p3.print();
    
    // 2. Работа с геттерами и сеттерами
    std::cout << "\n=== Работа с геттерами и сеттерами ===" << std::endl;
    
    // Получаем степень и коэффициенты
    std::cout << "Степень p2: " << p2.getDegree() << std::endl;
    std::cout << "Коэффициенты p2: ";
    for (double coeff : p2.getCoefficients()) {
        std::cout << coeff << " ";
    }
    std::cout << std::endl;
    
    // Изменяем коэффициент при x²
    p2.setCoefficient(1, 4.0); // Теперь: x³ + 4x² - 2x + 3.5
    std::cout << "p2 после изменения: ";
    p2.print();
    
    // Увеличиваем степень (новые коэффициенты = 0)
    p2.setDegree(4); // x⁴ + 0x³ + 4x² - 2x + 3.5
    std::cout << "p2 после увеличения степени: ";
    p2.print();
    
    // 3. Вычисление значения
    std::cout << "\n=== Вычисление значения ===" << std::endl;
    double x;
    std::cout << "Введите x для вычисления p2(x): ";
    std::cin >> x;
    std::cout << "p2(" << x << ") = " << p2.evaluate(x) << std::endl;
    
    std::cout << "\n=== Завершение программы ===" << std::endl;
    return 0;
}

//    g++ -o polynomial_program polynomial.cpp main.cpp
//    ./polynomial_program