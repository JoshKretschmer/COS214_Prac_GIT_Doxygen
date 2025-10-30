makeCXX = g++
CXXFLAGS = -g --coverage -pthread -Wall
GCOVFLAGS = -f -m -r -j

TARGET = main

SRCS = $(filter-out DemoMain.cpp, $(wildcard *.cpp))
OBJS = $(SRCS:.cpp=.o)
GCOV_FILES = $(SRCS:.cpp=.cpp.gcov)

HDRS = $(wildcard *.h)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

coverage: run
	gcov $(GCOVFLAGS) $(SRCS)

clean:
	rm -f $(OBJS) $(TARGET) *.gcda *.gcno *.gcov *.gcov.json.gz

.PHONY: all run coverage clean