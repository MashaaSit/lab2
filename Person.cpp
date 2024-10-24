#include "Person.h"

void Person::readCoefficientsFromFile(const std::string &filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Could not open the file!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        double a, b, c;
        ss >> a >> b >> c;
        coefficients.push_back({a, b, c});
    }
    file.close();
}
