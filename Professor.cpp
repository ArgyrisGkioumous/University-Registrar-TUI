//
// Created by Argyris Gkioumous on 27/5/26.
//

#include "Professor.h"
#include <iostream>

Professor::Professor(std::string n, std::string g, std::string d)
    : Member(n,g), department(d) {}

Professor::~Professor() {}

std::string Professor::getDepartment() const {
    return department;
}

void Professor::setDepartment(std::string d) {
    department = d;
}

void Professor::printDetails() const {
    std::cout << "Καθηγητής: " << name
              << " | Φύλο: " << gender
              << " | Τμήμα: " << department << std::endl;
}

void Professor::sendEmail(std::string mesaage) {
    std::cout << "Ο Καθηγητής " << name << " στέλνει email: " << mesaage << std::endl;
}
