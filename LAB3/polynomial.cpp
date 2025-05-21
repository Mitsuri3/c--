#include "polynomial.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <limits>

// Реализация Polynomial

bool Polynomial::validateCoefficients(int deg, const std::vector<double>& coeffs) const {
    if (deg < 0) return false;
    if (coeffs.size() != static_cast<size_t>(deg + 1)) return false;
    return true;
}

Polynomial::Polynomial() : degree(0), coefficients({0}) {}

Polynomial::Polynomial(int deg) : degree(deg) {
    if (deg < 0) throw std::invalid_argument("Degree cannot be negative");
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

Polynomial::~Polynomial() {
    std::cout << "Polynomial of degree " << degree << " destroyed" << std::endl;
}

int Polynomial::getDegree() const { return degree; }
std::vector<double> Polynomial::getCoefficients() const { return coefficients; }

double Polynomial::getCoefficient(int index) const {
    if (index < 0 || index >= static_cast<int>(coefficients.size())) {
        throw std::out_of_range("Index out of range");
    }
    return coefficients[index];
}

void Polynomial::setDegree(int newDegree) {
    if (newDegree < 0) throw std::invalid_argument("Degree cannot be negative");
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

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        result += coefficients[i] * std::pow(x, degree - i);
    }
    return result;
}

std::string Polynomial::toString() const {
    std::ostringstream oss;
    bool firstTerm = true;
    
    for (int i = 0; i <= degree; ++i) {
        double coeff = coefficients[i];
        if (coeff == 0) continue;
        
        int current_degree = degree - i;
        
        if (!firstTerm) {
            oss << (coeff > 0 ? " + " : " - ");
            coeff = std::abs(coeff);
        } else if (coeff < 0) {
            oss << "-";
            coeff = -coeff;
        }
        
        if (coeff != 1 || current_degree == 0) oss << coeff;
        
        if (current_degree > 0) {
            oss << "x";
            if (current_degree > 1) oss << "^" << current_degree;
        }
        
        firstTerm = false;
    }
    
    if (firstTerm) oss << "0";
    return oss.str();
}

void Polynomial::print() const { std::cout << toString() << std::endl; }
void Polynomial::print(std::ostream& out) const { out << toString() << std::endl; }

Polynomial* Polynomial::derivative() const {
    if (degree == 0) return new Polynomial(0, {0});
    
    std::vector<double> new_coeffs(degree);
    for (int i = 0; i < degree; ++i) {
        new_coeffs[i] = coefficients[i] * (degree - i);
    }
    
    return new Polynomial(degree - 1, new_coeffs);
}

Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        degree = other.degree;
        coefficients = other.coefficients;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
    os << p.toString();
    return os;
}

// Реализация ExtendedPolynomial

double ExtendedPolynomial::evaluate(double x) const {
    // Более точное вычисление с использованием схемы Горнера
    double result = coefficients[0];
    for (int i = 1; i <= degree; ++i) {
        result = result * x + coefficients[i];
    }
    return result;
}

void ExtendedPolynomial::print() const {
    std::cout << "Extended Polynomial: " << toString() << std::endl;
}

double ExtendedPolynomial::integrate(double a, double b) const {
    double result = 0.0;
    for (int i = 0; i <= degree; ++i) {
        int power = degree - i + 1;
        result += coefficients[i] * (std::pow(b, power) - std::pow(a, power)) / power;
    }
    return result;
}

ExtendedPolynomial* ExtendedPolynomial::derivative() const {
    if (degree == 0) return new ExtendedPolynomial(0, {0});
    
    std::vector<double> new_coeffs(degree);
    for (int i = 0; i < degree; ++i) {
        new_coeffs[i] = coefficients[i] * (degree - i);
    }
    
    return new ExtendedPolynomial(degree - 1, new_coeffs);
}

// Реализация ModifiedPolynomial

ModifiedPolynomial::ModifiedPolynomial(int deg, const std::vector<double>& coeffs, double mod)
    : Polynomial(deg, coeffs), modifier(mod) {}

ModifiedPolynomial::ModifiedPolynomial(const ModifiedPolynomial& other)
    : Polynomial(other), modifier(other.modifier) {}

double ModifiedPolynomial::evaluate(double x) const {
    return Polynomial::evaluate(x) * modifier;
}

std::string ModifiedPolynomial::toString() const {
    return "Modified[" + std::to_string(modifier) + "] " + Polynomial::toString();
}

ModifiedPolynomial* ModifiedPolynomial::derivative() const {
    Polynomial* baseDeriv = Polynomial::derivative();
    ModifiedPolynomial* result = new ModifiedPolynomial(
        baseDeriv->getDegree(), 
        baseDeriv->getCoefficients(), 
        modifier
    );
    delete baseDeriv;
    return result;
}

void ModifiedPolynomial::setAllCoefficients(double value) {
    for (auto& coeff : coefficients) {
        coeff = value;
    }
}

double ModifiedPolynomial::getModifier() const { return modifier; }
void ModifiedPolynomial::setModifier(double newModifier) { modifier = newModifier; }