CXX          = g++
CXXFLAGS     = -g --coverage -pthread -Wall -Iinc
GCOVFLAGS    = -f -m -r -j
DEMO_TARGET  = DemoMain
TEST_TARGET  = UnitTestingMain
COMMON_SRC   = $(filter-out src/DemoMain.cpp src/UnitTestingMain.cpp, $(wildcard src/*.cpp))
DEMO_SRC     = src/DemoMain.cpp $(COMMON_SRC)
TEST_SRC     = src/UnitTestingMain.cpp $(COMMON_SRC)
DEMO_OBJ     = $(DEMO_SRC:.cpp=.o)
TEST_OBJ     = $(TEST_SRC:.cpp=.o)
HDRS         = $(wildcard inc/*.h)
GCOV_FILES   = $(COMMON_SRC:.cpp=.cpp.gcov)

all: $(DEMO_TARGET) $(TEST_TARGET)

$(DEMO_TARGET): $(DEMO_OBJ)
	$(CXX) $(CXXFLAGS) -o $(DEMO_TARGET) $(DEMO_OBJ)

$(TEST_TARGET): $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJ)

%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run_demo: $(DEMO_TARGET)
	./$(DEMO_TARGET)

run_tests: $(TEST_TARGET)
	./$(TEST_TARGET)

coverage: run_tests
	gcov $(GCOVFLAGS) $(COMMON_SRC)

memory_tests: $(TEST_TARGET)
	valgrind --leak-check=full ./$(TEST_TARGET)

demo_tests: $(DEMO_TARGET)
	valgrind --leak-check=full ./$(DEMO_TARGET)

clean:
	rm -f $(DEMO_OBJ) $(TEST_OBJ) $(DEMO_TARGET) $(TEST_TARGET) src/*.gcda src/*.gcno src/*.gcov src/*.gcov.json.gz

.PHONY: all run_demo run_tests coverage memory_tests demo_tests clean