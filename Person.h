#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <map>
#include <cmath>

class Person {
protected:
    std::string name;
    std::vector<std::vector<double>> roots; // Вектор векторов для корней
    std::vector<std::vector<double>> coefficients; // Вектор векторов для коэффициентов

public:
    virtual ~Person() = default;

    Person(const std::string& name) : name(name) {}

    Person(){};

    virtual void solveEquations() = 0; // Чисто виртуальная функция

    const std::string& getName() const { return name; }
    const std::vector<std::vector<double>>& getRoots() const { return roots; }

    void addRoots(const std::vector<double>& newRoots) {
        roots.push_back(newRoots);
    }

    void setCoefficients(const std::vector<std::vector<double>>& coeffs) {
        coefficients = coeffs;
    }

     void readCoefficientsFromFile(const std::string& filename);
};


#endif
