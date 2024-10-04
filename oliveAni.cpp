#include "EllipseShape.h"

int main () {
    //draw basic shape of olive as trapezoid
    EllipseShape olive;

    //set initial size of olive
    olive.setRadius(sf::Vector2f(10,5));
    olive.setFillColor(sf::Color(102,0,51,100));
    olive.setOutlineThickness(10);
    olive.setOutlineColor(sf::Color(102,0,51));

    //set an empty vector to hold all olives created
    std::vector<EllipseShape> oliveS;


    //create a window
    sf::RenderWindow window(sf::VideoMode(800, 800),"olive Topping");
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

                //change the position of olive to where mouse clicks
                olive.setPosition(mousePos); 

                //change the rotation
                olive.setRotation(rand()/(RAND_MAX/360));

                //add it to vector
                oliveS.push_back(olive);
            }
        }

        //set background colour to mustard yellow heehee
        window.clear(sf::Color(229, 204, 0));

        //draw all olives
        for (const auto& olive : oliveS) {
            window.draw(olive);
        }
        window.display();
    }

}

//tested. colours might be changed