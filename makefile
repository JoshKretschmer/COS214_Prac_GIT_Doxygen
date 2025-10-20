# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -MMD -MP   # -g for debugging, -Wall for warnings, -MMD -MP for dependency files

# Target executable name
TARGET = $(notdir $(CURDIR))

# Source files and object files
SRC = $(wildcard *.cpp)       # All .cpp files in the current directory
OBJ = $(SRC:.cpp=.o)          # .o files for each .cpp file

# Default rule to build the target
all: $(TARGET)

# Rule to link all object files into the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ)

# Pattern rule for compiling .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build artifacts
clean:
	rm -f $(OBJ) $(TARGET) $(OBJ:.o=.d)

# Run with Valgrind
valgrind: $(TARGET)
	valgrind ./$(TARGET)

# Debug with gdb
debug: $(TARGET)
	gdb ./$(TARGET)

# Include generated dependency files
-include $(OBJ:.o=.d)


