//
// Created by Argyris Gkioumous on 27/5/26.
//

#ifndef UNIVERSITY_REGISTRAR_TUI_MEMBER_H
#define UNIVERSITY_REGISTRAR_TUI_MEMBER_H

#include <string>

class Member {
protected:
    std::string name;
    std::string gender;

public:
    Member(std::string n, std::string g);
    virtual ~Member();

    std::string getName() const;
    std::string getGender() const;

    void setName(std::string n);
    void setGender(std::string g);

    virtual void printDetails() const = 0;

    virtual std::string getType() const = 0;
    virtual std::string getSpecificAttribute() const = 0;
};


#endif //UNIVERSITY_REGISTRAR_TUI_MEMBER_H