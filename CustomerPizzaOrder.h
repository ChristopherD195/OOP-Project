#ifndef CUSTOMERPIZZAORDER_H
#define CUSTOMERPIZZAORDER_H
#include <iostream>
#include <vector>
#include "Pizza.h"
#include "Customer.h"

class CustomerPizza : Pizza{
    private:
        int numCuts;
        float baseTip;
        int ovenDuration;
        std::vector<int> toppingOrder;
    public:
        CustomerPizza(float baseTips);
        void setOvenDuration();
        void setToppingOrder();
        std::vector<int> getToppingOrder(){return toppingOrder;}
        int getNumCuts(){return numCuts;}
        void setNumCuts();
};


#endif