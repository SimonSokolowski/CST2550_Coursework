#ifndef MEMBER_H
#define MEMBER_H

#include "Person.h"
#include <vector>
#include <string>

// Forward declaration
class Book;

class Member : public Person {
private:
    int memberID;
    std::vector<Book*> booksLoaned;

public:
    Member(int memberID, const std::string &name, const std::string &address, const std::string &email);

    std::string getMemberID() const;
    
    std::vector<Book*>& getBooksBorrowed();
    void setBooksBorrowed(Book *book);
};

#endif // MEMBER_H