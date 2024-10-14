//
// Created by Ellie Sheppard on 9/10/24.
//
#include <vector>
#include <iostream>
#include "climate_change_impact.h"
int main() {
    std::vector<ClimateChangeImpact> impacts;
    std::string filename = "/Users/elliesheppard/Project1-eesheppa/climate_change_impact_on_agriculture_2024.csv";
    ClimateChangeImpact ccimpact;
    if (ccimpact.loadFile(filename, impacts)) {
        std::cout << "testing file name. Loading file: " << filename << std::endl;
        std::cout << impacts.size()
        << " records read from file" << std::endl;
        ClimateChangeImpact lastImpact = impacts.back();
        std::string lastCountry = lastImpact.getCountry();
        std::cout << "The last country read was " << lastCountry << std::endl;
    }
    else {
        std::cout << "Something went wrong." <<std::endl;
    }
    return 0;

}