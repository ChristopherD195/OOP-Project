#include "PlayerPizza.h"

PlayerPizza::PlayerPizza() : Pizza(), ovenDuration(0), numCuts(0), isCut(false), isBaked(false), isTopped(false), totalTips(0)  {
}
// Start oven time, created when pizza is placed in oven
void PlayerPizza::setOvenStartTime() {
    this->ovenStartTime = std::time(nullptr);
}
// Called when pizza is taken out of the oven
void PlayerPizza::setOvenDuration() {
    std::time_t current_time = std::time(nullptr);
    this->ovenDuration = current_time - this->ovenStartTime;
}

// return private members
int PlayerPizza::getOvenDuration() {return this->ovenDuration;}
bool PlayerPizza::getIsCut() {return this->isCut;}
bool PlayerPizza::getIsBaked() {return this->isBaked;}
bool PlayerPizza::getIsTopped() {return this->isTopped;}
float PlayerPizza::getTotalTips() {return this->totalTips;}

// Set Tips
void PlayerPizza::setTotalTips(float playerTip) {
    this->totalTips = playerTip;
}

// Bool setters are used to check if the next stage can go on
void PlayerPizza::setIsCut(bool isCut) {
    this->isCut = isCut;
}
void PlayerPizza::setIsBaked(bool isBaked) {
    this->isBaked = isBaked;
}
void PlayerPizza::setIsTopped(bool isTopped) {
    this->isTopped = isTopped;
}

// Adds player efficiency tips and customer tips
void PlayerPizza::updateTotalTips(float baseTip, float extraTip){
    this->totalTips += baseTip + extraTip;
};

// Sets number of cuts when the pizza is cut from the user
void PlayerPizza::setNumCuts(int cuts) {
    this->numCuts = cuts;
}

// Returns number of cuts
int PlayerPizza::getNumCuts() {return this->numCuts;}

// Called if the game is played again
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