#ifndef BOOK_H
#define BOOK_H

#include <string>
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
    int dueDate;
    Member *borrower;

public:
    Book(int bookID, const std::string &bookName, const std::string &authorFirstName, const std::string &authorLastName);

    std::string getBookID() const;
    std::string getBookName() const;
    std::string getAuthorFirstName() const;
    std::string getAuthorLastName() const;
    int getDueDate() const;
    void setDueDate(const int dueDate);
    void returnBook();
    void borrowBook();

};

#endif // BOOK_H