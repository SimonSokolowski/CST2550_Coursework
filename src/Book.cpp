#include "Book.h"
#include <string>

Book::Book(int bookID, const std::string &bookName, const std::string &authorFirstName, const std::string &authorLastName)
    : bookID(bookID), bookName(bookName), authorFirstName(authorFirstName), authorLastName(authorLastName) {
}

// Getter for bookID
std::string Book::getBookID() const {
    return std::to_string(bookID);
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
int Book::getDueDate() const {
    return dueDate;
}

// Setter for date
void Book::setDueDate(const int newDueDate) {
    dueDate = newDueDate;
}

