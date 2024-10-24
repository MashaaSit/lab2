#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <cmath>
class GoodStudent : public Person {
public:
    GoodStudent(const std::string& name) : Person(name) {}

    void solveEquations() override;
};


class AverageStudent : public Person {
public:
    AverageStudent(const std::string& name) : Person(name) {}

    void solveEquations() override;
};

class BadStudent : public Person {
public:
    BadStudent(const std::string& name) : Person(name) {}

    void solveEquations() override;
};

#endif
