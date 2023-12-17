#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <chrono>
#include "Member.h"

enum class bookType {
    ScienceFiction,
    Satire,
    Drama,
    ActionAndAdventure,
    Romance,
    Mystery,
    Horror,
    Health,
    Guide,
    Diaries,
    Comics,
    Journals,
    Biographies,
    Fantasy,
    History,
    Science,
    Art
};

class Book {
private:
    int bookID;
    std::string bookName;
    std::string authorFirstName;
    std::string authorLastName;
    bookType type;
    std::chrono::system_clock::time_point dueDate;
    Member *borrower;

public:
    Book(int bookID, const std::string &bookName, const std::string &authorFirstName, const std::string &authorLastName);

    std::string getBookID() const;
    std::string getBookName() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    std::chrono::system_clock::time_point getDueDate() const;
    void setDueDate(const std::chrono::system_clock::time_point &dueDate);
    void returnBook();
    void borrowBook();

};

#endif // BOOK_H