#ifndef TEACHER_H
#define TEACHER_H
#include "Person.h"

class Teacher:public Person{
    std::vector<std::pair<std::string, std::vector<std::vector<double>>>> emails; // Письма на проверку
    std::map<std::string, int> results; // Результаты студентов

public:
    Teacher():Person(){};

    void solveEquations();

    void receiveEmails(const std::vector<std::pair<std::string, std::vector<std::vector<double>>>>& newEmails);

    void checkSolutions();

    void publishResults(const std::string& filename);
};

#endif
