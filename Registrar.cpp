//
// Created by Argyris Gkioumous on 27/5/26.
//

#include "Registrar.h"
#include "Professor.h"
#include <iostream>
#include <sstream>
#include <fstream>

Registrar::Registrar() {}

Registrar::~Registrar() {
    for (Member* m : members) {
        delete m;
    }
    members.clear();
}

void Registrar::addMember(Member* m) {
    members.push_back(m);
}

void Registrar::addCourse(const Course& c) {
    courses.push_back(c);
}

void Registrar::printAllMembers() const {
    if (members.empty()) {
        std::cout << "Δεν υπάρχουν εγγεγραμένα μέλη." << std::endl;
        return;
    }
    std::cout << "\n --- Λίστα Μελών Πανεπιστημίου ---" << std::endl;
    for (const Member* m: members) {
        m->printDetails();
    }
}

void Registrar::printAllCourses() const {
    if (courses.empty()) {
        std::cout << "Δεν υπάρχουν καταχωρημένα μαθήματα." << std::endl;
        return;
     }
    std::cout <<"\n ---Λίστα Μαθημάτων ---" << std::endl;
    for (const auto& c:courses) {
        c.printCourseInfo();
    }
}

void Registrar::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Σφάλμα: Αδυναμία ανοίγματος του αρχείου για αποθήκευση!" << std::endl;
        return;
    }

    for (const auto& c : courses) {
        file << "COURSE," << c.getCourseName() << "," << c.getCourseCode() << "\n";
    }
    
    for (Member* m : members) {
        if (m != nullptr) {
            file << m->getType() << ","
                 << m->getName() << ","
                 << m->getGender() << ","
                 << m->getSpecificAttribute() << "\n";
        }
    }

    std::cout << "Τα δεδομένα αποθηκεύτηκαν επιτυχώς στο αρχείο: " << filename << std::endl;
    file.close();
}

void Registrar::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ειδοποίηση: Το αρχείο " << filename << " δεν βρέθηκε. Θα δημιουργηθεί νεο κατα την αποθήκευση" << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        std::getline(ss, type, ',');

        if (type == "COURSE") {
            std::string name, code;
            std::getline(ss, name, ',');
            std::getline(ss, code, ',');
            courses.push_back(Course(name, code));
        }
    }
    std::cout << "Τα δεδομένα φορτώθηκαν επιτυχώς!" << std::endl;
    file.close();
}
