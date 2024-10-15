#ifndef CUSTOMERPIZZA_H
#define CUSTOMERPIZZA_H

#include <iostream>
#include <vector>
#include "Pizza.h"      
#include "Efficiency.h"
class CustomerPizza : public Pizza {
    private:
        int numCuts;
        float baseTip;
        std::vector<int> toppingOrder;
        int ovenDuration;
        int ovenStartTime;

    public:
        // Constructor
        CustomerPizza();

        // Getters
        int getNumCuts() ;
        float getBaseTip() ;
        std::vector<int>& getToppingOrder() ;

        // Overriding pure virtual functions from Pizza class
        void setOvenStartTime() override;   // Override required
        void setOvenDuration(int duration);  // Override to set oven duration
        int getOvenDuration() override;         // Override to get oven duration

        // Setters (Used when the player has a save file)
        void setNumCuts(int numCuts);
        void setBaseTip(float baseTip);
        void setToppingOrder(std::vector<int> toppingOrder);

        // randomly generate orders (Used when the player doesnt have a save file/is making a new customer)
        void updateNumCuts();
        void updateBaseTip();
        void updateToppingOrder();
        void updateOvenDuration();

        void reaction(Efficiency rating);
        int feedback_calculation(float);
    
};

#endif