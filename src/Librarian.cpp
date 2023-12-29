#include "Librarian.h"
#include "Member.h"
#include "Book.h"
#include <iostream>

// Global member vector
std::vector<Member> globalMembers;
extern std::vector<Book> globalBooks;

Librarian::Librarian(int staffID, const std::string &name, const std::string &address, const std::string &email, int salary)
    : Person(), staffID(staffID), salary(salary) {
    setName(name);
    setAddress(address);
    setEmail(email);
}

void Librarian::addMember() {
    int memberID;
    std::string name, address, email;
    
    // Get member details from user input
    std::cout << "Enter member ID: ";
    std::cin >> memberID;
    std::cin.ignore(); // Clear the newline character

    std::cout << "Enter member's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter member's address: ";
    std::getline(std::cin, address);

    std::cout << "Enter member's email: ";
    std::getline(std::cin, email);

    // Create a new Member object and add it to the global vector
    Member newMember(memberID, name, address, email);
    globalMembers.push_back(newMember);

    std::cout << "New member added successfully.\n";
}

void Librarian::issueBook(int memberID, int bookID) {
    Member* member = nullptr;
    Book* book = nullptr;
    /// Find the member by memberID
    for (auto& m : globalMembers) {
        if (m.getMemberID() == std::to_string(memberID)) {
            member = &m;
            break;
        }
    }

    // Find the book by bookID
    for (auto& b : globalBooks) {
        if (b.getBookID() == std::to_string(bookID)) {
            book = &b;
            break;
        }
    }

    std::cout << "adding book" << bookID << "for user " << memberID ;
}

void Librarian::returnBook(int memberID, int bookID) {
    // process the return of a book from a member
}

void Librarian::displayBorrowedBooks(int memberID) {
    // display all books borrowed by a member
}

void Librarian::calcFine(int memberID) {
    // calculate the fine for a member's overdue books
}

// Getter for StaffID
int Librarian::getStaffID() {
    return staffID;
}

// Setter for StaffID
void Librarian::setStaffID(int newStaffID) {
    staffID = newStaffID;
}

// Getter for Salary
int Librarian::getSalary() {
    return salary;
}

// Setter for Salary
void Librarian::setSalary(int newSalary) {
    salary = newSalary;
}
