#include "GlobalDay.h"

int GlobalDay::globalDay = 1; // Initialize the global day to 1.

int GlobalDay::getDay()
{
    return globalDay; // Return the current global day.
}

void GlobalDay::incrementDay()
{
    ++globalDay; // Increment the global day by one.
}
