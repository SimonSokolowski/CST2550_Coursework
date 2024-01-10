#include "Librarian.h"
#include "Member.h"
#include "Book.h"
#include "Utility.h"
#include <iostream>
#include <algorithm>

// Global member vector
std::vector<Member> globalMembers;
extern std::vector<Book> globalBooks;

Librarian::Librarian(int staffID, const std::string &name, const std::string &address, const std::string &email, int salary)
    : Person(), staffID(staffID), salary(salary)
{
    setName(name);
    setAddress(address);
    setEmail(email);
}

void Librarian::addMember()
{
    int memberID;
    std::string name, address, email;

    // Get member details from user input
    memberID = Utility::getIntegerInput("Enter Member ID: ");

    std::cout << "Enter member's name: ";
    std::getline(std::cin, name);

    std::cout << "Enter member's address: ";
    std::getline(std::cin, address);

    std::cout << "Enter member's email: ";
    std::getline(std::cin, email);

    // Create a new Member object and add it to the global vector
    Member newMember(memberID, name, address, email);
    globalMembers.push_back(newMember);

    std::cout << "\n";
    std::cout << "New member added successfully.\n";
}

void Librarian::issueBook(int memberID, int bookID)
{
    Member *member = nullptr;
    Book *book = nullptr;
    /// Find the member by memberID
    for (auto &m : globalMembers)
    {
        if (m.getMemberID() == std::to_string(memberID))
        {
            member = &m;
            break;
        }
    }

    // Find the book by bookID
    for (auto &b : globalBooks)
    {
        if (b.getBookID() == std::to_string(bookID))
        {
            book = &b;
            break;
        }
    }

    // If both member and book are found, add the book to the member's loaned books
    if (member != nullptr && book != nullptr)
    {
        // Set the due date for the book as current global day plus 3
        book->setDueDate(Utility::getDay() + 3);

        member->setBooksBorrowed(book); // Add the book to the member's borrowed books
        std::cout << "\n";
        std::cout << "Book " << bookID << " issued to member " << memberID << ".\n";
        std::cout << "The due date is day " << book->getDueDate() << ".\n";
    }
    else
    {
        std::cout << "\n";
        if (member == nullptr)
            std::cout << "Member ID " << memberID << " not found.\n";
        if (book == nullptr)
            std::cout << "Book ID " << bookID << " not found.\n";
    }
}

void Librarian::returnBook(int memberID, int bookID)
{
    Member *member = nullptr;
    Book *book = nullptr;
    /// Find the member by memberID
    for (auto &m : globalMembers)
    {
        if (m.getMemberID() == std::to_string(memberID))
        {
            member = &m;
            break;
        }
    }

    // Find the book by bookID
    for (auto &b : globalBooks)
    {
        if (b.getBookID() == std::to_string(bookID))
        {
            book = &b;
            break;
        }
    }

    // If both member and book are found, attempt to remove the book from the member's borrowed books
    if (member != nullptr && book != nullptr)
    {
        // Retrieve a reference to the users' collection of loaned books
        auto &booksLoaned = member->getBooksBorrowed();
        auto bookIter = std::find(booksLoaned.begin(), booksLoaned.end(), book);
        if (bookIter != booksLoaned.end())
        {
            calcFine(memberID);
            booksLoaned.erase(bookIter); // Remove the book from the vector
            std::cout << "Book " << bookID << " returned successfully by member " << memberID << ".\n";
            std::cout << "The book was returned on day " << Utility::getDay() << ".\n";
                }
        else
        {
            std::cout << "Book " << bookID << " not found in member " << memberID << "'s borrowed books.\n";
        }
    }
    else
    {
        if (member == nullptr)
            std::cout << "Member ID " << memberID << " not found.\n";
        if (book == nullptr)
            std::cout << "Book ID " << bookID << " not found.\n";
    }
}

void Librarian::displayBorrowedBooks(int memberID)
{
    Member *member = nullptr;
    /// Find the member by memberID
    for (auto &m : globalMembers)
    {
        if (m.getMemberID() == std::to_string(memberID))
        {
            member = &m;
            break;
        }
    }

    // If the member is found, display their borrowed books
    if (member != nullptr)
    {
        std::vector<Book *> borrowedBooks = member->getBooksBorrowed();
        if (borrowedBooks.empty())
        {
            std::cout << "Member " << memberID << " has no borrowed books.\n";
        }
        else
        {
            std::cout << "Member " << memberID << " has borrowed the following books:\n";
            for (Book *book : borrowedBooks)
            {
                if (book != nullptr)
                {
                    // Assuming Book class has methods like getTitle() to get book details
                    std::cout << "Book ID: " << book->getBookID()
                              << ", Title: " << book->getBookName() << "\n";
                }
            }
        }
    }
    else
    {
        std::cout << "No member found with ID " << memberID << ".\n";
    }
}

void Librarian::calcFine(int memberID)
{
    Member *member = nullptr;
    // Find the member by memberID
    for (auto &m : globalMembers)
    {
        if (m.getMemberID() == std::to_string(memberID))
        {
            member = &m;
            break;
        }
    }

    // If member is found, calculate fines
    if (member != nullptr)
    {
        auto &borrowedBooks = member->getBooksBorrowed();
        int totalFine = 0;
        int currentDay = Utility::getDay();

        for (Book *book : borrowedBooks)
        {
            int dueDate = book->getDueDate();
            if (currentDay > dueDate) // Book is overdue
            {
                int daysLate = currentDay - dueDate;
                totalFine += daysLate; // Assuming the fine is 1 unit per day late
            }
        }

        // Output the total fine for the member
        if (totalFine > 0)
        {
            std::cout << "Member " << memberID << " has a total fine of " << totalFine << " for late books.\n";
        }
        else
        {
            std::cout << "Member " << memberID << " has no fines for late books.\n";
        }
    }
    else
    {
        std::cout << "Member ID " << memberID << " not found.\n";
    }
}

// Getter for StaffID
int Librarian::getStaffID()
{
    return staffID;
}

// Setter for StaffID
void Librarian::setStaffID(int newStaffID)
{
    staffID = newStaffID;
}

// Getter for Salary
int Librarian::getSalary()
{
    return salary;
}

// Setter for Salary
void Librarian::setSalary(int newSalary)
{
    salary = newSalary;
}
