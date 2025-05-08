#include "polynomial.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <limits>

// Реализация метода проверки коэффициентов
bool Polynomial::validateCoefficients(int deg, const std::vector<double>& coeffs) const {
    if (deg < 0) return false;
    if (coeffs.size() != static_cast<size_t>(deg + 1)) return false;
    return true;
}

// Конструкторы
Polynomial::Polynomial() : degree(0), coefficients({0}) {}

Polynomial::Polynomial(int deg) : degree(deg) {
    if (deg < 0) {
        throw std::invalid_argument("Degree cannot be negative");
    }
    coefficients = std::vector<double>(deg + 1, 0.0);
}

Polynomial::Polynomial(int deg, const std::vector<double>& coeffs) {
    if (!validateCoefficients(deg, coeffs)) {
        throw std::invalid_argument("Invalid coefficients for given degree");
    }
    degree = deg;
    coefficients = coeffs;
}

Polynomial::Polynomial(const Polynomial& other) 
    : degree(other.degree), coefficients(other.coefficients) {}

// Деструктор
Polynomial::~Polynomial() {
    std::cout << "Polynomial of degree " << degree << " destroyed" << std::endl;
}

// Геттеры
int Polynomial::getDegree() const {
    return degree;
}

std::vector<double> Polynomial::getCoefficients() const {
    return coefficients;
}

double Polynomial::getCoefficient(int index) const {
    if (index < 0 || index >= static_cast<int>(coefficients.size())) {
        throw std::out_of_range("Index out of range");
    }
    return coefficients[index];
}

// Сеттеры
void Polynomial::setDegree(int newDegree) {
    if (newDegree < 0) {
        throw std::invalid_argument("Degree cannot be negative");
    }
    degree = newDegree;
    coefficients.resize(newDegree + 1, 0.0);
}

void Polynomial::setCoefficients(const std::vector<double>& newCoefficients) {
    if (!validateCoefficients(degree, newCoefficients)) {
        throw std::invalid_argument("Invalid coefficients for current degree");
    }
    coefficients = newCoefficients;
}

void Polynomial::setCoefficient(int index, double value) {
    if (index < 0 || index >= static_cast<int>(coefficients.size())) {
        throw std::out_of_range("Index out of range");
    }
    coefficients[index] = value;
}

// Вычисление значения
double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * std::pow(x, degree - i);
    }
    return result;
}

// Преобразование в строку
std::string Polynomial::toString() const {
    std::ostringstream oss;
    bool firstTerm = true;
    
    for (int i = 0; i <= degree; ++i) {
        double coeff = coefficients[i];
        if (coeff == 0) continue;
        
        int current_degree = degree - i;
        
        // Знак
        if (!firstTerm) {
            oss << (coeff > 0 ? " + " : " - ");
            coeff = std::abs(coeff);
        } else if (coeff < 0) {
            oss << "-";
            coeff = -coeff;
        }
        
        // Коэффициент
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
        
        firstTerm = false;
    }
    
    if (firstTerm) { // Все коэффициенты нулевые
        oss << "0";
    }
    
    return oss.str();
}

// Методы печати
void Polynomial::print() const {
    std::cout << toString() << std::endl;
}

void Polynomial::print(std::ostream& out) const {
    out << toString() << std::endl;
}

// Оператор присваивания
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        degree = other.degree;
        coefficients = other.coefficients;
    }
    return *this;
}