#include "Member.h"
#include "Person.h"

Member::Member(int memberID, const std::string &name, const std::string &address, const std::string &email)
    : Person(), memberID(memberID) {
    setName(name);
    setAddress(address);
    setEmail(email);
}

std::string Member::getMemberID() const {
    return std::to_string(memberID);  // Convert integer memberID to string
}

void Member::setBooksBorrowed(Book *book) {
    booksLoaned.push_back(book);
}

std::vector<Book*> Member::getBooksBorrowed() const {
    return booksLoaned;
}
 