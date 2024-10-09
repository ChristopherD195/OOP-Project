#include "Pizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"

#include <iostream>
#include <vector>

Pizza::Pizza() {
    ovenDuration = 0;
    radius = 400;
    crustThickness = 50;
}
int Pizza::getOvenDuration() {return ovenDuration;}
float Pizza::getRadius() {return radius;}
float Pizza::getCrustThickness() {return crustThickness;}

bool Pizza::addToppings(int toppingType) {
    switch (toppingType) {
    case 1: {
        Topping* pineapple = new Pineapple();
        this->toppings.push_back(pineapple);
        std::cout << "Topping added successfully" << std::endl;
        break;
    } case 2: {
        Topping* olive = new Olive();
        this->toppings.push_back(olive);
        std::cout << "Topping added successfully" << std::endl;
        break;
    } default:
        std::cout << "This topping does not exist. Please try again." << std::endl;
        return false;
        break;
    }
    return true;
}

bool Pizza::removeToppingFromPizza(int toppingType) {
    std::string toppingString = "";
    switch (toppingType) {
    case 1: {
        toppingString = "pineapple";
        break;
    } case 2: {
        toppingString = "olive";
        break;
    } default:
        std::cout << "This topping does not exist. Please try again." << std::endl;
        return false;
        break;
    }

    int element = -1;
    for (std::size_t i = 0; i < toppings.size(); i++) {
        std::cout << "Checking element" << i << " of toppings" << std::endl;
        if (toppings[i] && toppings[i]->getToppingType() == toppingString) {
            std::cout << "Topping " << i << " is the same" << std::endl;
            element = static_cast<int>(i);;
            break;
        } else {
            std::cout << "Topping" << i << " is not the same" << std::endl;
        }
    }
    if (element >= 0) {
        toppings.erase(toppings.begin() + element);
        std::cout << "Topping erased" << std::endl;
        return true;
    }
    std::cout << "Could not erase this topping" << std::endl;
    return false;
}
const std::vector<Topping*>& Pizza::getToppings() const { return this->toppings;}
Pizza::~Pizza () {
    for (Topping* topping : toppings) {
    delete topping; // Free each dynamically allocated topping
    }
    toppings.clear();
}
// void::setOvenDuration() {}
// void setCutting() {}