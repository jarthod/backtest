CXX=g++
CXXFLAGS=-g -std=c++0x -W -Wall -O5 -pedantic
BIN=backtest

SRC=$(wildcard *.cpp)
OBJ=$(SRC:%.cpp=%.o)

all: $(OBJ)
	$(CXX) -o $(BIN) $^

clean:
	rm -f *.o
	rm -f $(BIN)

re: clean all