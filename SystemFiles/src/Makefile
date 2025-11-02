# Compiler and flags
CXX := g++
CXXFLAGS := -g -std=c++11 -Wall -Werror
LDFLAGS := -g -std=c++11

# Auto-detect all .cpp files
SOURCES := $(filter-out TerminalMain.cpp UnitTestingMain.cpp, $(wildcard *.cpp))
OBJECTS := $(SOURCES:.cpp=.o)
EXEC := main

# Default target
all: $(EXEC)

# Link all object files
$(EXEC): $(OBJECTS)
	$(CXX) $(LDFLAGS) $^ -o $@

# Compile each .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(EXEC)
	./$(EXEC)

# Debug with gdb
debug: $(EXEC)
	gdb ./$(EXEC)

# Check for memory leaks
valgrind: $(EXEC)
	valgrind --leak-check=full ./$(EXEC)

# Build for coverage testing
coverage: CXXFLAGS += --coverage
coverage: LDFLAGS += --coverage
coverage: clean $(EXEC)
	./$(EXEC)
	gcov -f -m -r -j *.cpp

# Create submission zip
zipfile:
	zip uxxxxxxxx.zip *.cpp *.h Makefile

# Clean up
clean:
	rm -f $(EXEC) *.o *.gcov *.gcda *.gcno

.PHONY: all run debug valgrind coverage zipfile clean