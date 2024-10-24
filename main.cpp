#include <fstream>
#include <iostream>
#include "Student.h"
#include "Teacher.h"


auto createStudentsFromFile(const std::string &filename, std::vector<Person *> &students) -> void {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string name, type;
        ss >> name >> type;

        if (type == "good") {
            students.push_back(new GoodStudent(name));
        } else if (type == "average") {
            students.push_back(new AverageStudent(name));
        } else if (type == "bad") {
            students.push_back(new BadStudent(name));
        }
    }
    file.close();
}

int main() {
    std::vector<Person *> students;
    std::string path = "/home/masha/CLionProjects/допса/2lab/students_list.txt";
    createStudentsFromFile(path, students);

    std::vector<std::pair<std::string, std::vector<std::vector<double>> > > emails;

    path = "/home/masha/CLionProjects/допса/2lab/coefficients.txt";
    for (auto &student: students) {
        student->readCoefficientsFromFile(path);
        student->solveEquations();

        // Формирование письма
        emails.push_back({student->getName(), student->getRoots()}); // Последний вектор корней
    }

    Teacher teacher;
    teacher.readCoefficientsFromFile(path);
    teacher.solveEquations();
    teacher.receiveEmails(emails);
    teacher.checkSolutions();
    teacher.publishResults("results.txt");

    // Освобождение памяти
    for (auto &student: students) {
        delete student;
    }

    return 0;
}
