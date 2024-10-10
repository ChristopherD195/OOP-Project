#pragma once

class Efficiency
{
protected:
    double cuttingEfficiency;
    double toppingsEfficiency;
    double ovenDurationEfficiency;
    float extraTip;//extra Tip based on execution of the pizza
public:
    //default constructer--set to zero
    Efficiency(): cuttingEfficiency(0.0), toppingsEfficiency(0.0), ovenDurationEfficiency(0.0), extraTip(0.0) {}
    ~Efficiency(){};

    //set and get each data member
    void setCuttingEfficiency(double cuttingEfficiency);
    double getCuttingEfficiency();

    void setToppingsEfficiency(double toppingsEfficiency);
    double getToppingsEfficiency();

    void setOvenDurationEfficiency(double ovenDurationEfficiency);
    double getOvenDurationEfficiency();

    void setExtraTip();
    float getExtraTip();
};