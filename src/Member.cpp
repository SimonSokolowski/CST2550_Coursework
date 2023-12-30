#include "Member.h"
#include "Person.h"
#include "Book.h"
#include <string>

Member::Member(int memberID, const std::string &name, const std::string &address, const std::string &email)
    : Person(), memberID(memberID) {
    setName(name);
    setAddress(address);
    setEmail(email);
}

// Getter for MemberID
std::string Member::getMemberID() const {
    return std::to_string(memberID);  // Convert integer memberID to string
}

// Setter for borrowing books
void Member::setBooksBorrowed(Book *book) {
    booksLoaned.push_back(book);
}

// Getter for borrowing books
std::vector<Book*>& Member::getBooksBorrowed() {
    return booksLoaned;
}
 