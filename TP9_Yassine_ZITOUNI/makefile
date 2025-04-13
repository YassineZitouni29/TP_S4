CXX = g++
CXXFLAGS = -Wall -std=c++17 -g

# Source files
SRC = main.cpp \
      account.cpp \
      account_util.cpp \
      saving_account.cpp \
      trust_account.cpp \
      checkin_account.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
TARGET = program

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean
