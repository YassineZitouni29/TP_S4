CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC = main.cpp Movies.cpp Movie.cpp
TARGET = main

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)