#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>

// Constants
const sf::Vector2f pizzaCentre(400.f, 400.f); // Center of the pizza
const int radius = 350;//radius of outer brim of pizza inc. crust

//function to create a unit vector
sf:: Vector2f unitVector (sf::Vector2f click) {
    //calculate the length from the click to the centre
    float length = std::sqrt(click.x*click.x + click.y*click.y);
    //return unit vector
    return sf::Vector2f(click.x/length,click.y/length);
}

//generate a random value between min and max
float random(float min, float max) {
    float value = min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max - min)));
    return value;
}
int main () {
    //create the game window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Pizza Cutting");

    //draw a circle as the pizza, with const centre, const radius, red and yellow
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


    //create a vector container to store cutting lines
    std::vector<sf::VertexArray> cutLines;

    while(window.isOpen()==1) {//when window is open
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        
            // The escape key was pressed
            if (event.type == sf::Event::MouseButtonPressed ) {
                //create a vector to store mouse position
                sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);

                //create a unit vector pointing to the same direction
                sf::Vector2f vector = mousePosition - pizzaCentre;
                sf::Vector2f direction = unitVector(vector);

                //draw a line between centre and mouse click
                sf::VertexArray cut(sf::Lines, 2);
                cut[0].position = center;
                cut[1].position = center + sf::Vector2f(direction.x * radius,direction.y*radius);
                
                cut[0].color = sf::Color::Black;
                cut[1].color = sf::Color::Black;

                cutLines.push_back(cut);//add new cuts to the cut line vector
            }
        
        window.clear(sf::Color(153, 76, 0));
        window.draw(circle);
        window.draw(cheese);
        //draw all cutting lines
        for (const auto& cut : cutLines) {
            window.draw(cut);
        }
        window.display();
        }
    }
}