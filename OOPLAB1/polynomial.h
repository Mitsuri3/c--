#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>

class Polynomial {
private:
    int degree; // Степень многочлена
    std::vector<double> coefficients; // Коэффициенты (от старшей степени к младшей)

public:
    // Конструкторы
    Polynomial(int deg, const std::vector<double>& coeffs);
    Polynomial() : degree(0) {} // Конструктор по умолчанию
    
    // Методы доступа
    int getDegree() const;
    std::vector<double> getCoefficients() const;
    
    // Основные методы
    double evaluate(double x) const; // Вычисление значения многочлена
    std::string toString() const; // Преобразование в строку

    // Дополнительный метод (не указанный в задании)
    Polynomial derivative() const; // Производная многочлена
    
    // Метод печати
    void print() const;
};

#endif // POLYNOMIAL_H