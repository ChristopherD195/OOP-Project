#include "PlayerPizza.h"

PlayerPizza::PlayerPizza() : Pizza(), ovenDuration(0), numCuts(0), isCut(false), isBaked(false), isTopped(false), totalTips(0)  {
    //create SFML Pizza
}
void PlayerPizza::setOvenStartTime() {
    this->ovenStartTime = std::time(nullptr);
}
void PlayerPizza::setOvenDuration() {
    std::time_t current_time = std::time(nullptr);
    this->ovenDuration = current_time - this->ovenStartTime;
}

int PlayerPizza::getOvenDuration() {return this->ovenDuration;}

bool PlayerPizza::getIsCut() {return this->isCut;}
bool PlayerPizza::getIsBaked() {return this->isBaked;}
bool PlayerPizza::getIsTopped() {return this->isTopped;}
float PlayerPizza::getTotalTips() {return this->totalTips;}

void PlayerPizza::setTotalTips(float playerTip) {
    this->totalTips = playerTip;
}

void PlayerPizza::setIsCut(bool isCut) {
    this->isCut = isCut;
}
void PlayerPizza::setIsBaked(bool isBaked) {
    this->isBaked = isBaked;
}
void PlayerPizza::setIsTopped(bool isTopped) {
    this->isTopped = isTopped;
}

void PlayerPizza::updateTotalTips(float baseTip, float extraTip){
    this->totalTips += baseTip + extraTip;
};

void PlayerPizza::setNumCuts(int cuts) {
    this->numCuts = cuts;
}

int PlayerPizza::getNumCuts() {return this->numCuts;}

void PlayerPizza::reset(){
    this->ovenDuration = 0;
    this->numCuts = 0;
    this->isCut = false;
    this->isBaked = false;
    this->isTopped = false;
    this->totalTips = 0;
    toppings.clear();
    toppings.shrink_to_fit();
}