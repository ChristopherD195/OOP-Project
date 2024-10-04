#ifndef PIZZA_H
#define PIZZA_H
#include <iostream>
#include <vector>

class Pizza {
    private:
        //std::vector <Topping*> toppings;
        int ovenDuration;
        std::string base;
        float radius;
        float crustThickness;
    public:
        Pizza();
        int getOvenDuration();
        virtual void setOvenDuration();
        bool addToppings(Topping*);
        bool removeToppingFromPizza(Topping->getToppingType());
        Topping** getTopping();
        //virtual void setCutting(???);
        //getCutting() ???
};
#endif