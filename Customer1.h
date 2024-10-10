#ifndef CUSTOMER1_H
#define CUsTOMER1_H
#include <iostream>
#include <vector>
#include "Customer.h"

class Customer1 : public Customer{
    private:

    public:
        Customer1();
        void setToppingOrder();
        void setBaseTip();
        void setOvenTime();
        void setNumCuts();
};

#endif
