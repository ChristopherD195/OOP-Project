# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall -I/opt/homebrew/Cellar/sfml/2.6.1/include -I/opt/homebrew/Cellar/sfml/2.6.1/include/SFML/Graphics
LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.6.1/lib
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Target executable
TARGET = PlayerPizzaTester

# Source files
SRC = Pizza.cpp PlayerPizza.cpp Topping.cpp Meat.cpp FruitOrVeg.cpp Pepperoni.cpp Chicken.cpp Pineapple.cpp Olive.cpp ToppingTester.cpp

# Build target
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS) $(LIBS)

# Clean target
clean:
	rm -f $(TARGET)
