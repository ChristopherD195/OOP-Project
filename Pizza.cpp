#include "Pizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"

#include <iostream>
#include <vector>

Pizza::Pizza() {
    ovenDuration = 0;
    radius = 5.5;
    crustThickness = 2;
}
int Pizza::getOvenDuration() {return ovenDuration;}
float Pizza::getRadius() {return radius;}
float Pizza::getCrustThickness() {return crustThickness;}

bool Pizza::addToppings(int toppingType) {
    switch (toppingType) {
    case 1:
        Topping* pineapple = new Pineapple();
        toppings.push_back(pineapple);
        std::cout << "Topping added successfully" << std::endl;
        break;
    case 2:
        Topping* olive = new Olive();
        toppings.push_back(olive);
        std::cout << "Topping added successfully" << std::endl;
        break;
    default:
        std::cout << "This topping does not exist. Please try again." << std::endl;
        return false;
        break;
    }
    return true;
}

bool Pizza::removeToppingFromPizza(std::string toppingType) {
    int element = 0;;
    for (std::size_t i = 0; i < toppings.size(); i++) {
        std::cout << "Checking element" << i << " of toppings" << std::endl;
        if (toppings[i]->getToppingType() == toppingType) {
            std::cout << "Topping" << i << " is the same" << std::endl;
            element = i;
        } else {
            std::cout << "Topping" << i << " is not the same" << std::endl;
        }
    }
    toppings.erase(toppings.begin() + element);
    if (element < toppings.size()) {
        return true;
    }
    std::cout << "Could not erase this topping" << std::endl;
    return false;
}
std::vector <Topping*> Pizza::getToppings() {return toppings;}
Pizza::~Pizza () {}
// void::setOvenDuration() {}
// void setCutting() {}