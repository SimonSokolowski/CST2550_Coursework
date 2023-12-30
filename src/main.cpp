#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Librarian.h"
#include "Member.h"
#include "Book.h"

std::vector<Book> globalBooks; // Global vector to store books

Librarian getLibrarianDetails()
{
    int staffID;
    std::string name, address, email;
    int salary;

    std::cout << "Please enter the librarian's details:\n";
    std::cout << "Enter staff ID: ";
    std::cin >> staffID;
    std::cin.ignore(); // To consume the newline character left by std::cin

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter address: ";
    std::getline(std::cin, address);

    std::cout << "Enter email: ";
    std::getline(std::cin, email);

    std::cout << "Enter salary: ";
    std::cin >> salary;

    return Librarian(staffID, name, address, email, salary);
}

// Check for quotes and temporarily replaces commas with another character
std::stringstream processLine(const std::string &line)
{
    std::stringstream linestream;
    bool inQuotes = false;
    for (char c : line)
    {
        if (c == '\"')
        {
            inQuotes = !inQuotes;
        }
        else if (c == ',' && inQuotes)
        {
            c = '|'; // Temporarily replace commas with another character
        }
        linestream << c;
    }
    return linestream;
}

void populateBooks()
{
    // REFERENCE: https://cplusplus.com/doc/tutorial/files/
    // I learnt from and used the code in the above link to read from
    // a file input by the user.

    std::string line;
    std::string fileName;

    std::cout << "Enter book collection filename:" << std::endl;
    std::cin >> fileName;

    // Construct the relative path to the books directory
    std::string relativePath = "../books/" + fileName;

    std::ifstream myfile(relativePath);
    bool isFirstLine = true;

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (isFirstLine)
            { // Skip the first line (column headers)
                isFirstLine = false;
                continue;
            }

            // Book titles sometimes contain commas, which confuse the code (comma separated values are used)

            std::stringstream linestream = processLine(line);

            int bookID, pageCount;
            std::string bookName, authorFirstName, authorLastName, bookType;
            std::string value;

            getline(linestream, value, ',');
            bookID = std::stoi(value);
            std::cout << "Book ID: " << bookID << std::endl;

            getline(linestream, bookName, ',');

            // Replace the temporary character back to a comma if it's in the title
            std::replace(bookName.begin(), bookName.end(), '|', ',');

            getline(linestream, value, ',');
            pageCount = std::stoi(value);
            getline(linestream, authorFirstName, ',');
            getline(linestream, authorLastName, ',');
            getline(linestream, bookType);

            // REFERENCE: Above code for reading csv file and pushing to vector is
            // loosely based on fiji885's comment on Apr 14, 2019
            // https://cplusplus.com/forum/beginner/252267/

            // Remove trailing newline or other characters
            bookType.erase(std::remove(bookType.begin(), bookType.end(), '\n'), bookType.end());
            bookType.erase(std::remove(bookType.begin(), bookType.end(), '\r'), bookType.end());

            // Create a new Book object with the values and add it to the vector
            Book tempBook(bookID, bookName, authorFirstName, authorLastName);

            globalBooks.push_back(tempBook);
            std::cout << "Library has been populated with books from " << fileName << std::endl;
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file\n";
    }
}

int currentDay = 1;  // Global variable to track the current day

void advanceDay() {
    currentDay++;
    std::cout << "The day has advanced to day: " << currentDay << std::endl;
}

int main()
{
    populateBooks();

    for (const Book &book : globalBooks)
    {
        std::cout << "Book ID: " << book.getBookID() << "\n";
    }

    std::cout << "\n";
    std::cout << "Welcome to the Library System\n";

    Librarian librarian = getLibrarianDetails();

    librarian.addMember();
    librarian.issueBook(2,2);
    librarian.issueBook(2,6);
    librarian.displayBorrowedBooks(2);
    

    // Display the librarian's staff ID as a confirmation
    // std::cout << "Librarian's Staff ID: " << librarian.getStaffID() << "\n";

    return 0;
}