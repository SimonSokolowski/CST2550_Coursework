#ifndef GLOBALDAY_H
#define GLOBALDAY_H

class GlobalDay {
private:
    static int globalDay;

public:
    GlobalDay();

    static int getDay(); // Getter to retrieve the current global day.
    static void incrementDay(); // Function to increment the day by one.
};

#endif // GLOBALDAY_H
