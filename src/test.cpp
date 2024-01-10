#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Librarian.h"
#include "Member.h"
#include "Book.h"
#include "Utility.h"
#include <vector>
#define TESTING
#include "main.cpp"

extern std::vector<Member> globalMembers;
extern std::vector<Book> globalBooks;

void setupTestEnvironment() {
    // Clear existing members and books
    globalMembers.clear();
    globalBooks.clear();

    // Add a test member
    Member testMember(1, "Test Name", "Test Address", "test@email.com");
    globalMembers.push_back(testMember);

    // Add a test book
    Book testBook(1, "Test Book", "Author First", "Author Last");
    globalBooks.push_back(testBook);
}

TEST_CASE("Librarian Class Tests", "[Librarian]") {
    setupTestEnvironment(); // Setup test environment
    Librarian librarian(1, "Test Librarian", "123 Library Lane", "librarian@example.com", 3000);

    SECTION("Issue Book Test") {
        // Issue a book to the test member
        librarian.issueBook(1, 1);

        // Check if the book was issued
        REQUIRE(!globalMembers.front().getBooksBorrowed().empty());
    }

    SECTION("Return Book Test") {
        // First issue a book
        librarian.issueBook(1, 1);
        // Attempt to return book
        librarian.returnBook(1, 1);

        // Check if the book was returned
        REQUIRE(globalMembers.front().getBooksBorrowed().empty());
    }

}

TEST_CASE("Calculate Fine Test", "[Librarian]") {
    setupTestEnvironment();
    Librarian librarian(1, "Test Librarian", "123 Library Lane", "librarian@example.com", 3000);

    // Issue a book and set the due date in the past
    librarian.issueBook(1, 1);
    Book& borrowedBook = *globalMembers.front().getBooksBorrowed().front();
    borrowedBook.setDueDate(Utility::getDay() - 5); // Set due date to 5 days ago

    // Redirect std::cout to a stringstream
    std::stringstream buffer;
    std::streambuf* prevCoutbuf = std::cout.rdbuf(buffer.rdbuf());

    // Calculate fine
    librarian.calcFine(1);

    // Reset std::cout to its original buffer
    std::cout.rdbuf(prevCoutbuf);

    // Extract and verify the output
    std::string output = buffer.str();
    std::string expectedOutput = "Member 1 has a total fine of 5 for late books.";
    REQUIRE(output.find(expectedOutput) != std::string::npos);
}
