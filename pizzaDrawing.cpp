#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>

//generate a random value between min and max
float random(float min, float max) {
    float value = min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
    return value;
}

int main() {
    //draw basic shape of pizza
    sf::CircleShape circle;
    circle.setRadius(300);
    circle.setOutlineColor(sf::Color(247,218,137));
    circle.setOutlineThickness(50);
    circle.setPosition(100, 100);
    circle.setPointCount(100);
    circle.setFillColor(sf::Color(255,51,51,255));
    sf::Vector2f center(400.f, 400.f);//centre of pizza

    //draw cheese
    sf::ConvexShape cheese;
    const int numPoint = 50;
    cheese.setPointCount(numPoint);
    float baseRadius = 280.f;

     //define random irregular shape of cheese by changing the radius randomly at each point
    for (int i = 0; i < numPoint; ++i) {
        float angle = 2 * 3.14159f * i / numPoint;  // circular angle  for each point
        float radiusOffset = random(-10.f, 10.f);     // Slightly randomize the radius for an irregular feel
        float radius = baseRadius + radiusOffset;
        
        //calculate the position of each vertex using polar coordinates
        float x = center.x + radius * std::cos(angle);
        float y = center.y + radius * std::sin(angle);
        
        //set each point of the shape& fill color
        cheese.setPoint(i, sf::Vector2f(x, y));
        cheese.setFillColor(sf::Color(255,236,194));
    }

    //create a window
    sf::RenderWindow window(sf::VideoMode(800, 800),"Pizza Cutting");
    window.draw(circle);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //set background colour
        window.clear(sf::Color(153, 76, 0));
        window.draw(circle);
        window.draw(cheese);
        window.display();
    }

}

//tested. Worked!