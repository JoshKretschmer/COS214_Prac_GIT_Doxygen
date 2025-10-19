# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g

# Source files
SRCS = main.cpp Command.cpp Customer.cpp Inventory.cpp Iterator.cpp Memento.cpp NurseryMediator.cpp Observer.cpp Order.cpp Plant.cpp PlantCare.cpp PlantDecorator.cpp PlantFactory.cpp PlantState.cpp PurchaseAbstraction.cpp PurchaseFacade.cpp PurchaseImplementor.cpp Request.cpp Staff.cpp

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
