#include "Book.h"

Book::Book(int bookID, const std::string &bookName, const std::string &authorFirstName, const std::string &authorLastName)
    : bookID(bookID), bookName(bookName), authorFirstName(authorFirstName), authorLastName(authorLastName) {
}

// Getter for bookID
int Book::getBookID() const {
    return bookID;
}

// Getter for bookName
std::string Book::getBookName() const {
    return bookName;
}

// Getter for authorFirstName
std::string Book::getAuthorFirstName() const {
    return authorFirstName;
}

// Getter for authorLastName
std::string Book::getAuthorLastName() const {
    return authorLastName;
}

// Getter for date
std::chrono::system_clock::time_point Book::getDueDate() const {
    return dueDate;
}

// Setter for date
void Book::setDueDate(const std::chrono::system_clock::time_point &newDueDate) {
    dueDate = newDueDate;
}

