#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <limits>
#include <string>

class Utility
{
private:
    static int globalDay;

public:
    static int getIntegerInput(const std::string &prompt); // Input validation function.
    static int getDay();                                   // Getter to retrieve the current global day.
    static void incrementDay();                            // Function to increment the day by one.
};

#endif // UTILITY_H
