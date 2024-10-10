#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <vector>
#include <ctime>
#include <iostream>

class Customer{
    protected:
        time_t arrivalTime;
        time_t waitingTime;
        std::vector<int> toppingOrder;
        int ovenTime;
        int numCuts;
        float tipRating;
        float baseTip;
    public:
        Customer();
        time_t getArrivalTime() {return arrivalTime;}

        void setWaitingTime();
        time_t getWaitingTime() {return waitingTime;}

        virtual void setToppingOrder() = 0;
        std::vector<int> getToppingOrder() {return toppingOrder;}

        int getOvenTime() {return ovenTime;}
        virtual void setOvenTime() = 0;

        int getNumCuts() {return numCuts;}
        virtual void setNumCuts() = 0;

        virtual void setBaseTip() = 0;
        float getBaseTip() {return baseTip;}

        float getTipRating() {return tipRating;}
};

#endif