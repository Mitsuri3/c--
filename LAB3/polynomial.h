#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <vector>
#include <string>
#include <iostream>
#include <memory>

class Polynomial {
protected:
    int degree;
    std::vector<double> coefficients;

    bool validateCoefficients(int deg, const std::vector<double>& coeffs) const;

public:
    // Конструкторы
    Polynomial();
    explicit Polynomial(int deg);
    Polynomial(int deg, const std::vector<double>& coeffs);
    Polynomial(const Polynomial& other);
    
    // Виртуальный деструктор для полиморфизма
    virtual ~Polynomial();
    
    // Геттеры
    int getDegree() const;
    std::vector<double> getCoefficients() const;
    virtual double getCoefficient(int index) const;
    
    // Сеттеры
    virtual void setDegree(int newDegree);
    virtual void setCoefficients(const std::vector<double>& newCoefficients);
    virtual void setCoefficient(int index, double value);
    
    // Методы вычисления и печати
    virtual double evaluate(double x) const;
    virtual std::string toString() const;
    virtual void print() const;
    virtual void print(std::ostream& out) const;

    // Производная
    virtual Polynomial* derivative() const;
    
    // Оператор присваивания
    Polynomial& operator=(const Polynomial& other);

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
};

// Первый дочерний класс - с дополнительными операциями
class ExtendedPolynomial : public Polynomial {
public:
    using Polynomial::Polynomial; // Наследуем конструкторы
    
    // Перегрузка методов
    double evaluate(double x) const override;
    void print() const override;
    
    // Новые методы
    double integrate(double a, double b) const;
    ExtendedPolynomial* derivative() const override;
};

// Второй дочерний класс - с сокрытием и модификацией
class ModifiedPolynomial : public Polynomial {
private:
    double modifier; // Дополнительное поле
    
    // Скрываем некоторые методы родителя
    using Polynomial::setCoefficient;
    using Polynomial::setCoefficients;
    
public:
    ModifiedPolynomial(int deg, const std::vector<double>& coeffs, double mod);
    ModifiedPolynomial(const ModifiedPolynomial& other);
    
    // Модифицированные методы
    double evaluate(double x) const override;
    std::string toString() const override;
    ModifiedPolynomial* derivative() const override;
    
    // Новые методы
    void setAllCoefficients(double value);
    double getModifier() const;
    void setModifier(double newModifier);
};

#endif // POLYNOMIAL_H