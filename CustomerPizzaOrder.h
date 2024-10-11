#ifndef CUSTOMERPIZZAORDER_H
#define CUSTOMERPIZZAORDER_H
#include <iostream>
#include <vector>
#include "Pizza.h"
#include "Customer.h"
#include "Customer_a.h"

class CustomerPizza : Pizza{
    private:
        int numCuts;
        float baseTip;
        int ovenDuration;
        std::vector<int> toppingOrder;
    public:
        CustomerPizza(float baseTips);
        void setOvenDuration(Customer& customer);
        void setToppingOrder(Customer& customer);
        void setNumCuts(Customer& customer);
        int getNumCuts(){return numCuts;}
        std::vector<int> getToppingOrder(){return toppingOrder;}
};


#endif