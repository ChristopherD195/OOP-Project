#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>

int main() {
    // Create a convex shape for the mushroom
    sf::ConvexShape mushroom;
    
    //Define the number of points (vertices) for the mushroom shape
    mushroom.setPointCount(10);  // 6 for the cap and 4 for the stalk

    // Set points for the mushroom cap (semi-circle-like dome)
    mushroom.setPoint(0, sf::Vector2f(50, 0));   // Top center of the cap
    mushroom.setPoint(1, sf::Vector2f(90, 20));  // Upper right of the cap
    mushroom.setPoint(2, sf::Vector2f(110, 50)); // Middle right of the cap
    mushroom.setPoint(3, sf::Vector2f(90, 80));  // Lower right of the cap

    // Points for the left side of the cap
    mushroom.setPoint(4, sf::Vector2f(10, 80));   // Lower left of the cap
    mushroom.setPoint(5, sf::Vector2f(30, 50));   // Middle left of the cap
    mushroom.setPoint(6, sf::Vector2f(10, 20));   // Upper left of the cap
    
    // Set points for the stalk (rectangle under the cap)
    mushroom.setPoint(7, sf::Vector2f(70, 120));  // Bottom right of the stalk
    mushroom.setPoint(8, sf::Vector2f(50, 120));  // Bottom center of the stalk
    mushroom.setPoint(9, sf::Vector2f(30, 120));  // Bottom left of the stalk

    // Color the mushroom cap and stalk
    mushroom.setFillColor(sf::Color(255, 0, 0)); // Red for the cap
    mushroom.setOutlineThickness(2); // Add a border to the shape
    mushroom.setOutlineColor(sf::Color(139, 69, 19)); // Brown outline

    // Set an empty vector to hold all mushroom positions
    std::vector<sf::ConvexShape> mushrooms;

    // Create a window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Mushroom Topping");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                // Create a vector to save mouse position
                sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);

                // Create a new mushroom at the mouse position
                sf::ConvexShape newMushroom = mushroom;
                newMushroom.setPosition(mousePos.x - 50, mousePos.y - 30); // Offset for the shape's center
                newMushroom.setRotation(rand() % 360); // Random rotation for the mushroom

                // Add the new mushroom to the vector
                mushrooms.push_back(newMushroom);
            }
        }

        // Set background color to mustard yellow
        window.clear(sf::Color(229, 204, 0));

        // Draw all mushrooms
        for (const auto& mushroom : mushrooms) {
            window.draw(mushroom);
        }

        window.display();
    }

    return 0;
}