//
// Created by Argyris Gkioumous on 27/5/26.
//

#ifndef UNIVERSITY_REGISTRAR_TUI_COURSE_H
#define UNIVERSITY_REGISTRAR_TUI_COURSE_H

#include <string>

class Course {
private:
    std::string courseName;
    std::string courseCode;

public:
    Course(std::string name, std::string code);
    ~Course();

    std::string getCourseName() const;
    std::string getCourseCode() const;

    void setCourseName(std::string name);
    void setCourseCode(std::string code);

    void printCourseInfo() const;
};

#endif //UNIVERSITY_REGISTRAR_TUI_COURSE_H