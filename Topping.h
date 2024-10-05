#pragma once
#include <string>

class Topping
{
protected:
    std::string toppingType;//name of topping
    int numTopping;//number of Topping
    int numToppingIncrease;//pieces of Topping in a serve,initially set to 0
    bool isRendered;
public:
    Topping();
    Topping(std::string toppingType,int numToppingIncrease);

    //set and get num of Topping
    int getNumTopping();
    void setNumTopping(int numTopping);
    
    //set and get type of topping
    std::string getToppingType();
    void setToppingType(std::string toppingType);

    //set and get numToppingIncrease
    int getNumToppingIncrease();
    void setNumToppingIncrease(int numToppingIncrease);


    //virtual function for activating sfml
    virtual void renderTopping()=0;

    virtual ~Topping();
};