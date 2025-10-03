# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Source files
SRCS = main.cpp Plant.cpp Inventory.cpp PlantIterator.cpp Customer.cpp Order.cpp \
       PriceBasedRecommendation.cpp CategoryBasedRecommendation.cpp \
       NurseryMediator.cpp Discussion.cpp Memento.cpp CareTaker.cpp SystemState.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = nursery_system

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all run clean
