#include <iostream>
#include <string>
#include <vector>
#include "Librarian.h"
#include "Member.h"

int main() {
    std::vector<Member> members; // Vector to store members

    // Prompt the user to create a Librarian object
    std::cout << "Welcome to the Library System" << std::endl;
    std::cout << "Please enter the librarian's details:" << std::endl;

    int staffID;
    std::string name, address, email;
    int salary;

    std::cout << "Enter staff ID: ";
    std::cin >> staffID;
    std::cin.ignore(); // To consume the newline character left by std::cin

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter address: ";
    std::getline(std::cin, address);

    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    std::cout << "Enter salary: ";
    std::cin >> salary;

    // Create the Librarian object with the entered details
    Librarian librarian(staffID, name, address, email, salary);

    librarian.getStaffID();

    // Now the librarian can perform operations like adding members, issuing books, etc.
    // ...

    return 0;
}
