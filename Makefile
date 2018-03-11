CC = g++
CXXFLAGS = -std=c++11 -Wall -g
SRC = $(wildcard *.cpp)
TAR = $(SRC:.cpp=)

all: $(TAR)

hamming: hamming_code
	$(CC) hamming_code.cpp -o hamming_code

clean:
	rm -f $(TAR)