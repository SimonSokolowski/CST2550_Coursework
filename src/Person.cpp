#include "Person.h"

// Getter for Name
std::string Person::getName() const {
    return name;
}

// Setter for Name
void Person::setName(const std::string &newName) {
    name = newName;
}

// Getter for Address
std::string Person::getAddress() const {
    return address;
}

// Setter for Address
void Person::setAddress(const std::string &newAddress) {
    address = newAddress;
}

// Getter for Email
std::string Person::getEmail() const {
    return email;
}

// Setter for Email
void Person::setEmail(const std::string &newEmail) {
    email = newEmail;
}