#include "Efficiency.h"
#include <iostream>
#include <string>

//check test conditions and display result
void checkCondition(bool condition,std::string testName) {
    if (condition) {
        std::cout << "|PASSED| " << testName << std::endl;
    } else {
        std::cout << "|FAILED| " << testName << std::endl;
    }
}

int main() {
    Efficiency pizzaEfficiency;

    std::cout << "Running Boundary Case and Error Handling Tests...\n";

    // Test 1: Perfect performance (cutting, toppings, oven Duration all 100%)
    pizzaEfficiency.setCuttingEfficiency(1.0);
    pizzaEfficiency.setToppingsEfficiency(1.0);
    pizzaEfficiency.setOvenDurationEfficiency(1.0);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 1.0, "Perfect Cutting Efficiency");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 1.0, "Perfect Toppings Efficiency");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 1.0, "Perfect Oven Duration Efficiency");
    checkCondition(pizzaEfficiency.getExtraTip() == 10.0, "Max Extra Tip for Perfect Performance");

    // Test 2: Worst performance (cutting, toppings, oven Duration all 0%)
    pizzaEfficiency.setCuttingEfficiency(0.0);
    pizzaEfficiency.setToppingsEfficiency(0.0);
    pizzaEfficiency.setOvenDurationEfficiency(0.0);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 0.0, "Worst Cutting Efficiency");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 0.0, "Worst Toppings Efficiency");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 0.0, "Worst Oven Duration Efficiency");
    checkCondition(pizzaEfficiency.getExtraTip() == 0.0, "No Extra Tip for Worst Performance");

    // Test 3: Mid-range performance (cutting, toppings, oven Duration all 50%)
    pizzaEfficiency.setCuttingEfficiency(0.5);
    pizzaEfficiency.setToppingsEfficiency(0.5);
    pizzaEfficiency.setOvenDurationEfficiency(0.5);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 0.5, "Okay Cutting Efficiency");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 0.5, "Okay Toppings Efficiency");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 0.5, "Okay Oven Duration Efficiency");
    checkCondition(pizzaEfficiency.getExtraTip() == 5.0, "Half Extra Tip50% Performance");

    // Test 4: Negative efficiency (invalid input)
    pizzaEfficiency.setCuttingEfficiency(-0.5);
    pizzaEfficiency.setToppingsEfficiency(-1.0);
    pizzaEfficiency.setOvenDurationEfficiency(-0.2);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == -0.5, "Negative Cutting Efficiency (Invalid)");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == -1.0, "Negative Toppings Efficiency (Invalid)");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == -0.2, "Negative Oven Duration Efficiency (Invalid)");
    checkCondition(pizzaEfficiency.getExtraTip() == 0.0, "No Extra Tip for Invalid Efficiency");

    // Test case 5: Efficiencies greater than 1.0 (invalid input)
    pizzaEfficiency.setCuttingEfficiency(1.5);
    pizzaEfficiency.setToppingsEfficiency(2.0);
    pizzaEfficiency.setOvenDurationEfficiency(3.0);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 1.5, "Cutting Efficiency > 1.0 (Invalid)");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 2.0, "Toppings Efficiency > 1.0 (Invalid)");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 3.0, "Oven Duration Efficiency > 1.0 (Invalid)");
    checkCondition(pizzaEfficiency.getExtraTip() == 10.0, "Max Extra Tip for > 1.0 Efficiency");

    std::cout << "All tests completed." << std::endl;
    return 0;
}
//success