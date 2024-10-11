#include "PlayerPizza.h"

PlayerPizza::PlayerPizza() : Pizza(), ovenDuration(0), isCut(false), isBaked(false), isTopped(false), tips(0)  {
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
float PlayerPizza::getTips() {return this->tips;}
void PlayerPizza::setIsCut(bool isCut) {
    this->isCut = isCut;
}
void PlayerPizza::setIsBaked(bool isBaked) {
    this->isBaked = isBaked;
}
void PlayerPizza::setIsTopped(bool isTopped) {
    this->isTopped = isTopped;
}