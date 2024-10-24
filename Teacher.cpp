#include "Teacher.h"




void Teacher::solveEquations() {
    for (const auto& coeff : coefficients) {
        double a = coeff[0];
        double b = coeff[1];
        double c = coeff[2];
        double discriminant = b * b - 4 * a * c;

        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            addRoots({root1, root2});
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            addRoots({root});
        } else {
            addRoots({});
        }
    }
}

void Teacher::receiveEmails(const std::vector<std::pair<std::string, std::vector<std::vector<double>>>> &newEmails) {
    emails.insert(emails.end(), newEmails.begin(), newEmails.end());
}

void Teacher::checkSolutions() {
    for (const auto& email : emails) {
        const std::string& name = email.first;
        const std::vector<std::vector<double>>& studentRoots = email.second;
        int correctCount = 0;
        for (int i =0; i<this->roots.size();++i) {
            if (studentRoots[i]==this->roots[i]){
                correctCount++;
            }

        }results[name] = correctCount;
    }
}

void Teacher::publishResults(const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << std::setw(20) << "Student Name" << std::setw(20) << "Correct Solutions" << std::endl;
        for (const auto& result : results) {
            file << std::setw(20) << result.first << std::setw(20) << result.second << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Could not open the file!" << std::endl;
    }
}
