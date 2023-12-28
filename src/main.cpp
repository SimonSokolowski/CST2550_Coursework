#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Librarian.h"
#include "Member.h"
#include "Book.h"

std::vector<Book> globalBooks; // Global vector to store books

Librarian getLibrarianDetails()
{
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

void populateBooks()
{

    // REFERENCE: https://cplusplus.com/doc/tutorial/files/
    // I learnt from and used the code in the above link to read from
    // a file input by the user.

    std::string line;
    std::string fileName;

    std::cout << "Enter book collection filename: ";
    std::cin >> fileName;

    // Construct the relative path to the books directory
    std::string relativePath = "../books/" + fileName;

    std::ifstream myfile(relativePath);

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::cout << line << '\n';
        }
        myfile.close();
    }

    else {
        std::cout << "Unable to open file\n";
    }
}

int main()
{
    populateBooks();

    std::cout << "Welcome to the Library System\n";

    Librarian librarian = getLibrarianDetails();

    librarian.addMember();

    // Display the librarian's staff ID as a confirmation
    // std::cout << "Librarian's Staff ID: " << librarian.getStaffID() << "\n";

    return 0;
}