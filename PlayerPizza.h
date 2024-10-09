#ifndef PLAYERPIZZA_H
#define PLAYERPIZZA_H
#include "Pizza.h"
#include <iostream>
#include <ctime>
#include <vector>
class PlayerPizza : public Pizza {
    private:
        std::time_t ovenStartTime;
        int ovenDuration;
        bool isCut;
        bool isBaked;
        bool isTopped;
        float tips;
    protected:
        //std::vector<int> cutAngle;
    public:
        PlayerPizza();
        void setOvenStartTime();
        void setOvenDuration();
        int getOvenDuration();
        bool getIsCut();
        bool getIsBaked();
        bool getIsTopped();
        void setIsCut(bool isCut);
        void setIsBaked(bool isBaked);
        void setIsTopped(bool isTopped);
        //void cutPizza();
};

#endif