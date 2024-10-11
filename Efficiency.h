#pragma once
#include <vector>
class Efficiency
{
protected:
    float cuttingEfficiency;
    float toppingsEfficiency;
    float ovenDurationEfficiency;
    float extraTip;//extra Tip based on execution of the pizza
public:
    //default constructer--set to zero
    Efficiency(): cuttingEfficiency(0.0), toppingsEfficiency(0.0), ovenDurationEfficiency(0.0), extraTip(0.0) {}
    ~Efficiency(){};

    //set and get each data member
    void setCuttingEfficiency(int playerCutting, int customerCutting);
    float getCuttingEfficiency();

    void setToppingsEfficiency(const std::vector<int>& playerTopping, const std::vector<int>& customerTopping, int typesOfToppings);
    float getToppingsEfficiency();

    void setOvenDurationEfficiency(int playerOvenDuration, int customerOvenDuration);
    float getOvenDurationEfficiency();

    void setExtraTip();
    float getExtraTip();
};