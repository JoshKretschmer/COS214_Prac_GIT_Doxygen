CXX          = g++
CXXFLAGS     = -g --coverage -pthread -Wall -Iinc
GCOVFLAGS    = -f -m -r -j
DEMO_TARGET  = DemoMain
TEST_TARGET  = UnitTestingMain
TERMINAL_TARGET = TerminalMain

COMMON_SRC   = $(filter-out src/DemoMain.cpp src/UnitTestingMain.cpp src/TerminalMain.cpp, $(wildcard src/*.cpp))
DEMO_SRC     = src/DemoMain.cpp $(COMMON_SRC)
TEST_SRC     = src/UnitTestingMain.cpp $(COMMON_SRC)
TERMINAL_SRC = src/TerminalMain.cpp $(COMMON_SRC)

DEMO_OBJ     = $(DEMO_SRC:.cpp=.o)
TEST_OBJ     = $(TEST_SRC:.cpp=.o)
TERMINAL_OBJ = $(TERMINAL_SRC:.cpp=.o)

HDRS         = $(wildcard inc/*.h)
GCOV_FILES   = $(COMMON_SRC:.cpp=.cpp.gcov)

all: $(DEMO_TARGET) $(TEST_TARGET) $(TERMINAL_TARGET)

$(DEMO_TARGET): $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(DEMO_OBJ)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

$(TERMINAL_TARGET): $(TERMINAL_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TERMINAL_TARGET) $(TERMINAL_OBJ)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run_demo: $(DEMO_TARGET)
	./$(DEMO_TARGET)

run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)

run_terminal: $(TERMINAL_TARGET)
	./$(TERMINAL_TARGET)

coverage: run_tests
	gcov $(GCOVFLAGS) $(COMMON_SRC)

memory_tests: $(TEST_TARGET)
	valgrind --leak-check=full ./$(TEST_TARGET)

demo_tests: $(DEMO_TARGET)
	valgrind --leak-check=full ./$(DEMO_TARGET)

terminal_tests: $(TERMINAL_TARGET)
	valgrind --leak-check=full ./$(TERMINAL_TARGET)

clean:
	rm -f $(DEMO_OBJ) $(TEST_OBJ) $(TERMINAL_OBJ) $(DEMO_TARGET) $(TEST_TARGET) $(TERMINAL_TARGET) src/*.gcda src/*.gcno src/*.gcov src/*.gcov.json.gz

.PHONY: all run_demo run_tests run_terminal coverage memory_tests demo_tests terminal_tests clean
