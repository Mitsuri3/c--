#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>
#include <iostream>

class Polynomial {
private:
    int degree;
    std::vector<double> coefficients;

    // Объявляем приватный метод проверки
    bool validateCoefficients(int deg, const std::vector<double>& coeffs) const;

public:
    // Конструкторы
    Polynomial();
    explicit Polynomial(int deg);
    Polynomial(int deg, const std::vector<double>& coeffs);
    Polynomial(const Polynomial& other);
    
    // Деструктор
    ~Polynomial();
    
    // Геттеры
    int getDegree() const;
    std::vector<double> getCoefficients() const;
    double getCoefficient(int index) const;
    
    // Сеттеры
    void setDegree(int newDegree);
    void setCoefficients(const std::vector<double>& newCoefficients);
    void setCoefficient(int index, double value);
    
    // Методы вычисления и печати
    double evaluate(double x) const;
    std::string toString() const;
    void print() const;
    void print(std::ostream& out) const;

    // Производная
    Polynomial derivative() const;
    
    // Оператор присваивания
    Polynomial& operator=(const Polynomial& other);
};

#endif // POLYNOMIAL_H