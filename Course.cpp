//
// Created by Argyris Gkioumous on 27/5/26.
//

#include "Course.h"
#include <iostream>

Course::Course(std::string name, std::string code)
    : courseName(name), courseCode(code) {}

Course::~Course() {}

std::string Course::getCourseName() const {
    return courseName;
}

std::string Course::getCourseCode() const {
    return courseCode;
}

void Course::setCourseName(std::string name) {
    courseName = name;
}

void Course::setCourseCode(std::string code) {
    courseCode = code;
}

void Course::printCourseInfo() const {
    std::cout << "Μάθημα: " << courseName
              << " | Κωδικός: " << courseCode << std::endl;
}
