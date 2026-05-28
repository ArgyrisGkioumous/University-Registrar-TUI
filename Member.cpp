//
// Created by Argyris Gkioumous on 27/5/26.
//

#include "Member.h"
#include <iostream>

Member::Member(std::string n, std::string g) : name(n), gender(g) {}

Member::~Member() {}

std::string Member::getName() const {
    return name;
}

std::string Member::getGender() const {
    return gender;
}

void Member::setName(std::string n) {
    name = n;
}

void Member::setGender(std::string g) {
    gender =g;
}