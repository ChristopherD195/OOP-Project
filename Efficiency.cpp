#include "Efficiency.h"
#include <iostream>

//Set cutting efficiency
void Efficiency::setCuttingEfficiency(double cuttingEfficiency) {
    this->cuttingEfficiency = std::max(0.0, std::min(cuttingEfficiency, 1.0));//efficiency <=1.0
    setExtraTip(); // Update the extra Tip when cutting efficiency is set
}

//Get cutting efficiency
double Efficiency::getCuttingEfficiency() {
    return cuttingEfficiency;
}

//Set toppings efficiency
void Efficiency::setToppingsEfficiency(double toppingsEfficiency) {
    this->toppingsEfficiency = std::max(0.0, std::min(toppingsEfficiency, 1.0));;
    setExtraTip(); // Update the extra Tip when toppings efficiency is set
}

//Get toppings efficiency
double Efficiency::getToppingsEfficiency() {
    return toppingsEfficiency;
}

//Set oven Duration efficiency
void Efficiency::setOvenDurationEfficiency(double ovenDurationEfficiency) {
    this->ovenDurationEfficiency = std::max(0.0, std::min(ovenDurationEfficiency, 1.0));;
    setExtraTip(); // Update the extra Tip when oven Duration efficiency is set
}

//Get oven Duration efficiency
double Efficiency::getOvenDurationEfficiency() {
    return ovenDurationEfficiency;
}

//Get extra Tip
float Efficiency::getExtraTip() {
    return extraTip;
}

//Update ratings based on overall efficiency
void Efficiency::setExtraTip() {
    // Calculate the average efficiency each Duration an efficiency got updated
    double totalEfficiency = (cuttingEfficiency + toppingsEfficiency + ovenDurationEfficiency) / 3.0;

    // Set extra tip max limit (10 max Tip if efficiency is perfect)
    extraTip = static_cast<float>(totalEfficiency * 10.0);
}
