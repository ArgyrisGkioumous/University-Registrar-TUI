//
// Created by Argyris Gkioumous on 27/5/26.
//

#ifndef UNIVERSITY_REGISTRAR_TUI_PROFESSOR_H
#define UNIVERSITY_REGISTRAR_TUI_PROFESSOR_H

#include "Member.h"
#include <string>

class Professor : public Member {
private:
    std::string department;

public:
    Professor(std::string n, std::string g, std::string d);
    ~Professor() override; //virtual destructor

    std::string getDepartment() const;
    void setDepartment(std::string d);

    std::string getType() const override {
        return "PROFESSOR";
    }

    std::string getSpecificAttribute() const override {
        return department;
    }

    void printDetails() const override;

    void sendEmail(std::string message);
};

#endif //UNIVERSITY_REGISTRAR_TUI_PROFESSOR_H