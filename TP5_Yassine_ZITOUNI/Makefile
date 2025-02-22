# Target executables
TARGETS = exo1 exo2 exo3 exo4 exo5 exo6


SRC1 = exo1.cpp
SRC2 = exo2.cpp
SRC3 = exo3.cpp
SRC4 = exo4.cpp
SRC5 = exo5.cpp
SRC6 = exo6.cpp

all: $(TARGETS)

exo1: $(SRC1)
	g++ $(SRC1) -o exo1

exo2: $(SRC2)
	g++ $(SRC2) -o exo2

exo3: $(SRC3)
	g++ $(SRC3) -o exo3

exo4: $(SRC4)
	g++ $(SRC4) -o exo4

exo5: $(SRC5)
	g++ $(SRC5) -o exo5

exo6: $(SRC6)
	g++ $(SRC6) -o exo6

# Clean rule to remove all executables
clean:
	rm -f $(TARGETS)