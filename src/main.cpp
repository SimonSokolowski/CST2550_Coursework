#include <iostream>
#include <string>
#include <vector>
#include "Librarian.h"
#include "Member.h"

// Global variable
std::vector<Member> members; // Vector to store members

Librarian getLibrarianDetails() {
    int staffID;
    std::string name, address, email;
    int salary;

    std::cout << "Please enter the librarian's details:\n";
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

    return Librarian(staffID, name, address, email, salary);
}

int main() {

    std::cout << "Welcome to the Library System\n";
    Librarian librarian = getLibrarianDetails();

    // Display the librarian's staff ID as a confirmation
    std::cout << "Librarian's Staff ID: " << librarian.getStaffID() << "\n";

    return 0;
}