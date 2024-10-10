#ifndef CUSTOMER_A_H
#define CUSTOMER_A_H
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
        void feedback();
        int feedback_calculation();
};

#endif
