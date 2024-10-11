#include "Efficiency.h"
#include <iostream>
#include <string>
#include <vector>

// Check test conditions and display result
void checkCondition(bool condition, std::string testName) {
    if (condition) {
        std::cout << "|PASSED| " << testName << std::endl;
    } else {
        std::cout << "|FAILED| " << testName << std::endl;
    }
}

int main() {
    Efficiency pizzaEfficiency;

    std::cout << "Running Efficiency Tests...\n";

    // Test 1: Perfect performance (cutting, toppings, oven Duration all 100%)
    pizzaEfficiency.setCuttingEfficiency(10, 10);
    pizzaEfficiency.setToppingsEfficiency(std::vector<int>(2, 10), std::vector<int>(2, 10), 2);  // Two types of toppings, both perfectly matched
    pizzaEfficiency.setOvenDurationEfficiency(10, 10);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 1.0, "Perfect Cutting Efficiency");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 1.0, "Perfect Toppings Efficiency");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 1.0, "Perfect Oven Duration Efficiency");
    checkCondition(pizzaEfficiency.getExtraTip() == 10.0, "Max Extra Tip for Perfect Performance");

    // Test 2: Worst performance (cutting, toppings, oven Duration all 0%)
    pizzaEfficiency.setCuttingEfficiency(0, 5);
    pizzaEfficiency.setToppingsEfficiency(std::vector<int>(2, 0), std::vector<int>(2, 10), 2);  // Player missed all toppings
    pizzaEfficiency.setOvenDurationEfficiency(0, 10);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 0.0, "Worst Cutting Efficiency");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 0.0, "Worst Toppings Efficiency");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 0.0, "Worst Oven Duration Efficiency");
    checkCondition(pizzaEfficiency.getExtraTip() == 0.0, "No Extra Tip for Worst Performance");

    // Test 3: Mid-range performance (cutting, toppings, oven Duration all 50%)
    pizzaEfficiency.setCuttingEfficiency(5, 10);
    pizzaEfficiency.setToppingsEfficiency(std::vector<int>(2, 5), std::vector<int>(2, 10), 2);  // Player got 50% of toppings correct
    pizzaEfficiency.setOvenDurationEfficiency(5, 10);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 0.5, "Okay Cutting Efficiency");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 0.5, "Okay Toppings Efficiency");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 0.5, "Okay Oven Duration Efficiency");
    checkCondition(pizzaEfficiency.getExtraTip() == 5.0, "Half Extra Tip for 50% Performance");

    // Test 4: Negative efficiency (invalid input)
    pizzaEfficiency.setCuttingEfficiency(-5, 10);
    pizzaEfficiency.setToppingsEfficiency(std::vector<int>(2, -5), std::vector<int>(2, 10), 2);  // Negative topping efficiency should be clamped to 0
    pizzaEfficiency.setOvenDurationEfficiency(-2, 10);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 0.0, "Negative Cutting Efficiency (Invalid)");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 0.0, "Negative Toppings Efficiency (Invalid)");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 0.0, "Negative Oven Duration Efficiency (Invalid)");
    checkCondition(pizzaEfficiency.getExtraTip() == 0.0, "No Extra Tip for Invalid Efficiency");

    // Test 5: More cuts/ toppings/ oven time than required
    pizzaEfficiency.setCuttingEfficiency(15, 10);
    pizzaEfficiency.setToppingsEfficiency(std::vector<int>(2, 15), std::vector<int>(2, 10), 2);  // Player used too many toppings
    pizzaEfficiency.setOvenDurationEfficiency(15, 10);

    checkCondition(pizzaEfficiency.getCuttingEfficiency() == 0.5, "Okay Cutting Efficiency");
    checkCondition(pizzaEfficiency.getToppingsEfficiency() == 0.5, "OkayToppings Efficiency");
    checkCondition(pizzaEfficiency.getOvenDurationEfficiency() == 0.5, "Okay Oven Duration Efficiency");
    checkCondition(pizzaEfficiency.getExtraTip() == 5.0, "Half Extra Tip ");

    std::cout << "All tests completed." << std::endl;
    return 0;
}
