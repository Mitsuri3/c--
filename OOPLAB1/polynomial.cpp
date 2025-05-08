#include "polynomial.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <iostream>

// Конструктор
Polynomial::Polynomial(int deg, const std::vector<double>& coeffs) {
    if (deg < 0) {
        throw std::invalid_argument("Degree cannot be negative");
    }
    if (coeffs.size() != deg + 1) {
        throw std::invalid_argument("Number of coefficients must be degree + 1");
    }
    
    degree = deg;
    coefficients = coeffs;
}

// Геттеры
int Polynomial::getDegree() const {
    return degree;
}

std::vector<double> Polynomial::getCoefficients() const {
    return coefficients;
}

// Вычисление значения многочлена в точке x
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * std::pow(x, degree - i);
    }
    return result;
}

// Преобразование многочлена в строку
std::string Polynomial::toString() const {
    if (degree == 0) {
        return std::to_string(coefficients[0]);
    }
    
    std::ostringstream oss;
    for (int i = 0; i <= degree; ++i) {
        double coeff = coefficients[i];
        int current_degree = degree - i;
        
        if (coeff == 0) continue;
        
        // Знак коэффициента
        if (i > 0) {
            if (coeff > 0) {
                oss << " + ";
            } else {
                oss << " - ";
                coeff = -coeff;
            }
        } else if (coeff < 0) {
            oss << "-";
            coeff = -coeff;
        }
        
        // Коэффициент (не печатаем 1 перед x)
        if (coeff != 1 || current_degree == 0) {
            oss << coeff;
        }
        
        // Переменная и степень
        if (current_degree > 0) {
            oss << "x";
            if (current_degree > 1) {
                oss << "^" << current_degree;
            }
        }
    }
    
    return oss.str();
}

// Производная многочлена (дополнительный метод)
Polynomial Polynomial::derivative() const {
    if (degree == 0) {
        return Polynomial(0, {0});
    }
    
    std::vector<double> new_coeffs;
    for (int i = 0; i < degree; ++i) {
        new_coeffs.push_back(coefficients[i] * (degree - i));
    }
    
    return Polynomial(degree - 1, new_coeffs);
}

// Печать многочлена
void Polynomial::print() const {
    std::cout << toString() << std::endl;
}