# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# All .cpp source files
SRC = main.cpp \
      Cloud_util.cpp \
      Container.cpp \
      KubernetesCluster.cpp \
      Pod.cpp \
      Ressource.cpp \
      Server.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Executable name
TARGET = program

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJ) $(TARGET)

# Optional: run the program after building
run: all
	./$(TARGET)
