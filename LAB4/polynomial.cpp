#include "polynomial.h"
#include <cmath>
#include <iomanip>

// Реализация конструктора StandardPolynomial
StandardPolynomial::StandardPolynomial(int deg, const std::vector<double>& coeffs) {
    degree = deg;
    coefficients = coeffs;
}

// Реализация метода вычисления значения многочлена
double StandardPolynomial::evaluate(double x) const {
    double result = 0.0;
    // Вычисление по схеме Горнера для эффективности
    for (int i = degree; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

// Реализация метода вывода многочлена
void StandardPolynomial::print() const {
    bool first = true;
    for (int i = degree; i >= 0; --i) {
        if (coefficients[i] != 0) { // Пропускаем нулевые коэффициенты
            if (!first && coefficients[i] > 0) {
                std::cout << " + ";
            }
            if (i == 0) {
                std::cout << coefficients[i];
            } else if (i == 1) {
                std::cout << coefficients[i] << "x";
            } else {
                std::cout << coefficients[i] << "x^" << i;
            }
            first = false;
        }
    }
    std::cout << std::endl;
}

// Реализация деструктора StandardPolynomial
StandardPolynomial::~StandardPolynomial() {}

// Реализация конструктора NormalizedPolynomial
NormalizedPolynomial::NormalizedPolynomial(int deg, const std::vector<double>& coeffs) {
    degree = deg;
    coefficients = coeffs;
    // Нормировка: делим все коэффициенты на ведущий коэффициент
    if (coeffs[deg] != 0) {
        double leading_coeff = coeffs[deg];
        for (int i = 0; i <= deg; ++i) {
            coefficients[i] /= leading_coeff;
        }
    }
}

// Реализация метода вычисления значения многочлена
double NormalizedPolynomial::evaluate(double x) const {
    double result = 0.0;
    // Вычисление по схеме Горнера
    for (int i = degree; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}

// Реализация метода вывода нормированного многочлена
void NormalizedPolynomial::print() const {
    std::cout << "Normalized: ";
    bool first = true;
    for (int i = degree; i >= 0; --i) {
        if (coefficients[i] != 0) {
            if (!first && coefficients[i] > 0) {
                std::cout << " + ";
            }
            if (i == 0) {
                std::cout << coefficients[i];
            } else if (i == 1) {
                std::cout << coefficients[i] << "x";
            } else {
                std::cout << coefficients[i] << "x^" << i;
            }
            first = false;
        }
    }
    std::cout << std::endl;
}

// Реализация деструктора NormalizedPolynomial
NormalizedPolynomial::~NormalizedPolynomial() {}

// Реализация перегрузки оператора вывода
std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    poly.print();
    return os;
}