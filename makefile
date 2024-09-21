# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -I/opt/homebrew/Cellar/sfml/2.6.1/include -I/opt/homebrew/Cellar/sfml/2.6.1/include/SFML/Graphics
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Target executable
TARGET = game

# Source files
SRC = cutting.cpp

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(LIBS)

# Clean target
clean:
	rm -f $(TARGET)