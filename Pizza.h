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
        // virtual void setOvenStartTime();
        // virtual void setOvenDuration();
        // virtual int getOvenDuration();
        // // virtual void setCutting();
        bool addToppings(int toppingType);
        bool removeToppingFromPizza(int toppingType);
        const std::vector<Topping*>& getToppings() const;
        ~Pizza();
};
#endif