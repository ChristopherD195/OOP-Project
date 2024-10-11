#include <cmath>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Shape.hpp>

int main() {
    //draw basic shape of pineapple as trapezoid
    sf::ConvexShape pineapple;
    pineapple.setPointCount(4);

    //set initial position of pineapple
    pineapple.setPoint(0, sf::Vector2f(0, 0));
    pineapple.setPoint(1, sf::Vector2f(50, 0));
    pineapple.setPoint(2, sf::Vector2f(40, 100));
    pineapple.setPoint(3, sf::Vector2f(10, 100));
    pineapple.setFillColor(sf::Color::Yellow);
    pineapple.setOutlineThickness(10);
    pineapple.setOutlineColor(sf::Color(153,76,0));

    //set an empty vector to hold all pineapples created
    std::vector<sf::ConvexShape> pineappleS;


    //create a window
    sf::RenderWindow window(sf::VideoMode(800, 800),"Pineapple Topping");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (event.type == sf::Event::MouseButtonPressed) {
                //create a vector to save mouse position
                sf::Vector2f mousePos(event.mouseButton.x,event.mouseButton.y);

                //change the position of pineapple to where mouse clicks
                pineapple.setPosition(mousePos); 

                //change the rotation
                pineapple.setRotation(rand()/(RAND_MAX/360));

                //add it to vector
                pineappleS.push_back(pineapple);
            }
        }

        //set background colour to mustard yellow heehee
        window.clear(sf::Color(229, 204, 0));

        //draw all pineapples
        for (const auto& pineapple : pineappleS) {
            window.draw(pineapple);
        }
        window.display();
    }

}
//tested. All good!