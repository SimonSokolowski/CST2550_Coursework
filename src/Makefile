# Compiler settings
CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic

# Program's name
EXEC = LibrarySystem
TEST_EXEC = TestLibrarySystem

# Source files
SOURCES = main.cpp Librarian.cpp Member.cpp Book.cpp Utility.cpp Person.cpp
TEST_SOURCES = test.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_OBJECTS) $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $^

# Rule for building object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

# Clean rule
clean:
	rm -f $(OBJECTS) $(EXEC) $(TEST_OBJECTS) $(TEST_EXEC)
