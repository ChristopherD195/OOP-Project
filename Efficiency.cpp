#include "Efficiency.h"
#include <iostream>
#include <cmath>//for abs funcitons
#include <algorithm>  //to control the range of efficiency

// Set cutting efficiency
void Efficiency::setCuttingEfficiency(int playerCutting, int customerCutting) {
    if (customerCutting != 0) {//non zero
        float diff = std::abs(static_cast<float>(playerCutting - customerCutting)) / customerCutting;
        cuttingEfficiency = 1.0f - diff;  // any diff will reduce efficiency
    } else if (playerCutting==0.0){
        cuttingEfficiency = 1.0f; // If customer&player Cutting is 0, cutting efficiency is set to 1
    }else {
        cuttingEfficiency = 0.0f;//if player cutting is non zero when customer cutting is zero, set efficiency to 0
    }
    cuttingEfficiency = std::max(0.0f,std::min(1.0f,cuttingEfficiency)); // Ensure the value is between 0 and 1
    setExtraTip(); // Update the extra tip when cutting efficiency is set
}

// Get cutting efficiency
float Efficiency::getCuttingEfficiency() {
    return cuttingEfficiency;
}

// Set toppings efficiency
void Efficiency::setToppingsEfficiency(const std::vector<Topping*>& playerTopping,  const std::vector<int>& customerTopping) {
    float totalEfficiency = 0.0f;
    std::vector<int>playerCount = {0,0,0,0};
    int totalTypeOrdered =0;
    
    //record number of toppings in each category, stored in an int vector
    for (std::vector<Topping*>::size_type i = 0; i < playerTopping.size(); i++) {
        if (playerTopping.at(i)->getToppingType() =="pepperoni") {
            playerCount[0]++;
        }else if(playerTopping.at(i)->getToppingType() =="chicken") {
            playerCount[1]++;
        } else if(playerTopping.at(i)->getToppingType() =="pineaaple") {
            playerCount[2]++;
        } else if (playerTopping.at(i)->getToppingType() =="olive") {
            playerCount[3]++;
        }
    }

    // For loop to compare player and customer
    for (int i = 0; i < 4; i++)
    {
         if (customerTopping.at(i) != 0) {
            float diff = std::abs(static_cast<float>(playerCount[i] - customerTopping[i])) / customerTopping[i];
            totalEfficiency += (1.0f - diff); // Normalize and sum the differences
            totalTypeOrdered++;//one more type ordered
        } else {
            totalEfficiency += 0.0f; // If customerTopping is 0, treat as 0 efficiency for that topping
        }
    }
    
    toppingsEfficiency = totalEfficiency /totalTypeOrdered; // Get the average efficiency for 4 types of toppings
    toppingsEfficiency = std::max(0.0f,std::min(1.0f,toppingsEfficiency)); // Ensure it is between 0 and 1
    setExtraTip(); // Update the extra tip when toppings efficiency is set
}

// Get toppings efficiency
float Efficiency::getToppingsEfficiency() {
    return toppingsEfficiency;
}

// Set oven duration efficiency
void Efficiency::setOvenDurationEfficiency(int playerOvenDuration, int customerOvenDuration) {
    if (customerOvenDuration != 0) {
        float diff = std::abs(static_cast<float>(playerOvenDuration - customerOvenDuration)) / customerOvenDuration;
        ovenDurationEfficiency = 1.0f - diff; // set between 0 and 1
    } else {
        ovenDurationEfficiency = 0.0f; // If customer oven duration is 0, set efficiency to 0
    }
    ovenDurationEfficiency = std::max(0.0f,std::min(1.0f,ovenDurationEfficiency)); // Ensure the value is between 0 and 1
    setExtraTip(); // Update the extra tip when oven duration efficiency is set
}

// Get oven duration efficiency
float Efficiency::getOvenDurationEfficiency() {
    return ovenDurationEfficiency;
}

// Get extra tip
float Efficiency::getExtraTip() {
    return extraTip;
}

// Update extra tip based on overall efficiency
void Efficiency::setExtraTip() {
    // Calculate the average of all efficiencies
    float totalEfficiency = (cuttingEfficiency + toppingsEfficiency + ovenDurationEfficiency) / 3.0f;

    // Set extra tip - max limit (10.0 max tip if efficiency is perfect)
    extraTip = totalEfficiency * 10.0f;
    extraTip = std::max(0.0f,std::min(extraTip,10.0f)); // Ensure the extra tip is between 0 and 10
}
