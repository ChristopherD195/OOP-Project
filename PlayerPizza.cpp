#include "Pizza.h"
#include "PlayerPizza.h"
#include <iostream>
#include <ctime>
#include <vector>
PlayerPizza::PlayerPizza() : Pizza() {
    this->isCut = false;
    this->isBaked = false;
    this->isTopped = false;
    this->tips = 0;
    this->ovenDuration = 0;
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
void PlayerPizza::setIsCut(bool isCut) {
    this->isCut = isCut;
}
void PlayerPizza::setIsBaked(bool isBaked) {
    this->isBaked = isBaked;
}
void PlayerPizza::setIsTopped(bool isTopped) {
    this->isTopped = isTopped;
}