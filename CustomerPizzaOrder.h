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
    public:
        CustomerPizza(float baseTips);
        void setOvenDuration();
        void setToppingOrder();
        std::vector<int> getToppingOrder();
        int getNumCuts();
        void setNumCuts();

};


#endif