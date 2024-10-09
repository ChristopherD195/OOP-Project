#include "Pizza.h"
#include "Topping.h"
#include "FruitOrVeg.h"
#include "Pineapple.h"
#include "Olive.h"

#include <iostream>
#include <vector>

int main() {
    Pizza pizza;
    bool toppingExists = false;
    while (!(toppingExists)) {
        int toppingType = 0;
        std::cout << "Please select a topping type ('1' for pineapple, '2' for olive)" << std::endl;
        std::cin >> toppingType;
        toppingExists = pizza.addToppings(toppingType);
    }
    
    return 0;
}