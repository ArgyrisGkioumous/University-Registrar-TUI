//
// Created by Argyris Gkioumous on 27/5/26.
//

#ifndef UNIVERSITY_REGISTRAR_TUI_REGISTRAR_H
#define UNIVERSITY_REGISTRAR_TUI_REGISTRAR_H

#include "Member.h"
#include "Course.h"
#include <vector>
#include <string>

class Registrar {
private:
    std::vector<Member*> members;
    std::vector<Course> courses;

public:
    Registrar();
    ~Registrar();

    void addMember(Member* m);
    void addCourse(const Course& c);

    void printAllMembers() const;
    void printAllCourses() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif //UNIVERSITY_REGISTRAR_TUI_REGISTRAR_H