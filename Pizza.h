#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include <iostream>
#include <vector>

class Pizza {
    private:
        std::vector <Topping*> toppings;
        int ovenDuration;
        float radius;
        float crustThickness;
    public:
        Pizza();
        int getOvenDuration();
        float getRadius();
        float getCrustThickness();
        // virtual void setOvenDuration();
        // virtual void setCutting();
        bool addToppings(int toppingType);
        bool removeToppingFromPizza(int toppingType);
        std::vector <Topping*> getToppings();
        ~Pizza();
};
#endif