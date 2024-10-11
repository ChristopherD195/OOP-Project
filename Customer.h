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
        int ovenDuration;
        int numCuts;
        float tipRating;
        float baseTip;
    public:
        Customer();
        time_t getArrivalTime() {return (time(0)-arrivalTime);}
        void setWaitingTime();
        time_t getWaitingTime() {return waitingTime;}
        virtual void setToppingOrder() = 0;
        std::vector<int> getToppingOrder() {return toppingOrder;}
        int getOvenDuration() {return ovenDuration;}
        virtual void setOvenDuration() = 0;
        int getNumCuts() {return numCuts;}
        virtual void setNumCuts() = 0;
        virtual void setBaseTip() = 0;
        float getBaseTip() {return baseTip;}
        float getTipRating() {return tipRating;}
        //virtual void feedback();
        //int feedback_calculation(float);
};

#endif