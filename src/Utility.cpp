#include "Utility.h"

int Utility::globalDay = 1; // Initialize the global day to 1.

int Utility::getDay()
{
    return globalDay; // Return the current global day.
}

void Utility::incrementDay()
{
    ++globalDay; // Increment the global day by one.
}

// REFERENCE https://www.hackerearth.com/practice/notes/validating-user-input-in-c/#:~:text=When%20the%20user%20input%20is,statement%20to%20test%20its%20status.&text=From%20the%20above%20example%2C%20the,ignore()%2C%20etc.
int Utility::getIntegerInput(const std::string &prompt)
{
    int choice;
    while (true)
    {
        std::cout << prompt;
        std::cin >> choice;

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input, please enter an integer. ";
        }
        else
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return choice;
        }
    }
}