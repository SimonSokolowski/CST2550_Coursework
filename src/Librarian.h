#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include "Person.h"
#include "Book.h"

class Librarian : public Person
{
private:
    int staffID;
    int salary;

public:
    Librarian(int staffID, const std::string &name, const std::string &address, const std::string &email, int salary);

    void addMember();
    void issueBook(int memberID, int bookID);
    void returnBook(int memberID, int bookID);
    void displayBorrowedBooks(int memberID);
    void calcFine(int memberID);

    int getStaffID();
    void setStaffID(int staffID);
    int getSalary();
    void setSalary(int salary);
};

#endif // LIBRARIAN_H