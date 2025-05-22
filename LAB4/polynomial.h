#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <iostream>

// Абстрактный базовый класс для многочленов
class Polynomial {
protected:
    int degree; // Степень многочлена
    std::vector<double> coefficients; // Массив коэффициентов

public:
    // Чисто виртуальный метод для вычисления значения многочлена
    virtual double evaluate(double x) const = 0;

    // Чисто виртуальный метод для вывода описания многочлена
    virtual void print() const = 0;

    // Виртуальный деструктор для корректного освобождения памяти
    virtual ~Polynomial() {}
};

// Первый производный класс: стандартный многочлен
class StandardPolynomial : public Polynomial {
public:
    // Конструктор, принимающий степень и массив коэффициентов
    StandardPolynomial(int deg, const std::vector<double>& coeffs);

    // Реализация метода вычисления значения многочлена
    double evaluate(double x) const override;

    // Реализация метода вывода многочлена
    void print() const override;

    // Деструктор
    ~StandardPolynomial() override;
};

// Второй производный класс: нормированный многочлен
class NormalizedPolynomial : public Polynomial {
public:
    // Конструктор, принимающий степень и массив коэффициентов
    NormalizedPolynomial(int deg, const std::vector<double>& coeffs);

    // Реализация метода вычисления значения многочлена
    double evaluate(double x) const override;

    // Реализация метода вывода нормированного многочлена
    void print() const override;

    // Деструктор
    ~NormalizedPolynomial() override;
};

// Перегрузка оператора вывода для базового класса
std::ostream& operator<<(std::ostream& os, const Polynomial& poly);

#endif // POLYNOMIAL_H