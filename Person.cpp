#include "Person.h"

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string& newName) {
    name = newName;
}

