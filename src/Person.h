#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person
{
private:
    std::string name;
    std::string address;
    std::string email;

public:
    std::string getName() const;
    void setName(const std::string &name);

    std::string getAddress() const;
    void setAddress(const std::string &address);

    std::string getEmail() const;
    void setEmail(const std::string &email);
};

#endif // PERSON_H