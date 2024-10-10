#ifndef CUSTOMER_A_H
#define CUsTOMER_A_H
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
