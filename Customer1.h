#ifndef CUSTOMER1_H
#define CUsTOMER1_H
#include "Customer.h"
#include <vector>
#include <iostream>

class Customer1 : public Customer{
    private:


    public:
        Customer1();
        void setToppingOrder();
        void setBaseTip();
        void setOvenTime(int ovenTime);
        void setNumCuts(int numCuts);
        
};

#endif
