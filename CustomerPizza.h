#ifndef CUSTOMERPIZZA_H
#define CUSTOMERPIZZA_H
#include <iostream>
#include <vector>
#include "Pizza.h"
//
class CustomerPizza : public Pizza{         
    private:
        int numCuts;
        float baseTip;
        std::vector<int> toppingOrder;
        int ovenDuration;
        int ovenStartTime;

        // time_t arrivalTime = time(0);
        // time_t waitingTime = 0;
    public:
        CustomerPizza();
        int getNumCuts();
        float getBaseTip();
        const std::vector<int>& getToppingOrder() const;
        int getOvenDuration();

        void setOvenStartTime();
        void setNumCuts();
        void setBaseTip();
        void setToppingOrder();
        void setOvenDuration();
};
#endif