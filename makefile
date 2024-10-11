# Compiler and flags
CXX = g++ -std=c++11
CXXFLAGS = -g -Wall -I/opt/homebrew/Cellar/sfml/2.6.1/include -I/opt/homebrew/Cellar/sfml/2.6.1/include/SFML/Graphics
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Target executable
TARGET = mushroomAni

# Source files
SRC = mushroomAni.cpp

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(LIBS)

# Clean target
clean:
	rm -f $(TARGET)