#include "Librarian.h"
#include <iostream>

Librarian::Librarian(int staffID, const std::string &name, const std::string &address, const std::string &email, int salary)
    : Person(), staffID(staffID), salary(salary) {
    setName(name);
    setAddress(address);
    setEmail(email);
}

void Librarian::addMember() {
    // add a new member to the library system
}

void Librarian::issueBook(int memberID, int bookID) {
    // issue a book to a member
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
