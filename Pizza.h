#ifndef PIZZA_H
#define PIZZA_H
#include "Topping.h"
#include <iostream>
#include <vector>

class Pizza {
    private:
        std::vector <Topping*> toppings;
        float radius;
        float crustThickness;
    public:
        Pizza();
        float getRadius();
        float getCrustThickness();
        virtual void setOvenStartTime() = 0;
        virtual void setOvenDuration() = 0;
        virtual int getOvenDuration() = 0;
        // //virtual void setCutting();
        bool addToppings(int toppingType);
        bool removeToppingFromPizza(int toppingType);
        const std::vector<Topping*>& getToppings() const;
        ~Pizza();
};
#endif