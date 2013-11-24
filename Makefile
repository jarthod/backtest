CXX=g++
CXXFLAGS=-g -std=c++0x -W -Wall -O5 -pedantic
BIN=backtest

SRC=$(wildcard *.cpp strategies/*.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I.

clean:
	rm -f *.o
	rm -f $(BIN)

re: clean all test

test:
	$(CXX) $(CXXFLAGS) -I ./ tests/*.cpp -o unit_tests
	@echo -n "\033[31;01m"
	@valgrind -q --leak-check=full ./unit_tests
	@echo -n "\033[0m"
	@rm -f unit_tests