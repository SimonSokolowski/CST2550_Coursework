#include "Person.h"

std::string Person::getName() const {
    return name;
}

void Person::setName(const std::string &newName) {
    name = newName;
}

std::string Person::getAddress() const {
    return address;
}

void Person::setAddress(const std::string &newAddress) {
    address = newAddress;
}

std::string Person::getEmail() const {
    return email;
}

void Person::setEmail(const std::string &newEmail) {
    email = newEmail;
}