# Compiler settings
CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

# Program's name
EXEC = LibrarySystem

# Source files
SOURCES = main.cpp Librarian.cpp Member.cpp Book.cpp Utility.cpp Person.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for building object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule
clean:
	rm -f $(OBJECTS) $(EXEC)
