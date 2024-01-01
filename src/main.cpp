#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include<limits>
#include "Librarian.h"
#include "Member.h"
#include "Book.h"
#include "Utility.h"

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
        }
        myfile.close();
    }
    else
    {
        std::cout << "Unable to open file\n";
    }
}

int main()
{
    populateBooks();

    std::cout << "Welcome to the Library System\n";
    std::cout << "The current day is: " << Utility::getDay() << "\n";

    Librarian librarian = getLibrarianDetails();
    int choice;
    bool running = true;

    while (running)
    {
        std::cout << "\nLibrary Management System\n";
        std::cout << "1. Add Member\n";
        std::cout << "2. Issue Book\n";
        std::cout << "3. Return Book\n";
        std::cout << "4. Display Member's Borrowed Books\n";
        std::cout << "5. Calculate Fine\n";
        std::cout << "6. Progress Day\n";
        std::cout << "7. Exit\n";
        
        choice = Utility::getIntegerInput("Please enter your choice: ");
    
        switch (choice)
        {
        case 1:
        {
            // Add Member
            librarian.addMember();
            break;
        }
        case 2:
        {
            // Issue Book
            int memberID, bookID;
            memberID = Utility::getIntegerInput("Enter Member ID to issue a book: ");
            bookID = Utility::getIntegerInput("Enter Book ID to issue: ");
            librarian.issueBook(memberID, bookID); // Call the function with the provided IDs
            break;
        }
        case 3:
        {
            // Return Book
            int memberID, bookID;
            memberID = Utility::getIntegerInput("Enter Member ID to return a book: ");
            bookID = Utility::getIntegerInput("Enter Book ID to return: ");
            librarian.returnBook(memberID, bookID); // Call the function with the provided IDs
            break;
        }
        case 4:
        {
            // Dispaly The Currently Borrowed Books
            int memberID;
            memberID = Utility::getIntegerInput("Enter Member ID to display their books: ");
            librarian.displayBorrowedBooks(memberID); // Call the function with the provided ID
            break;
        }
        case 5:
        {
            // Calculate Fine
            int memberID;
            memberID = Utility::getIntegerInput("Enter Member ID to calculate fines: ");
            librarian.calcFine(memberID); // Call the function with the provided ID
            break;
        }
        case 6:
        {
            // Progress Day
            Utility::incrementDay();

            // Display the new day
            std::cout << "After incrementing, the global day is: " << Utility::getDay() << std::endl;
        }
        case 7:
        {
            // Exit the program
            running = false;
            std::cout << "Exiting the Library Management System.\n";
            break;
        }
        default:
        {
            // Handle invalid choice
            std::cout << "Invalid choice. Please try again.\n";
            break;
        }
        }
    }

    return 0;
}