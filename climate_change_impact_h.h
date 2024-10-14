//
// Created by Ellie Sheppard on 9/10/24.
//

#ifndef CLIMATE_CHANGE_IMPACT_H
#define CLIMATE_CHANGE_IMPACT_H

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>


class ClimateChangeImpact {
private:
    std::string country, region, crop_type, adaptation_strategies;
    int id, year, extreme_weather_events;
    double total_precipitation_mm, co2_emissions_mt, irrigation_access_percent, pesticide_use_kg_per_ha,
    fertilizer_use_kg_per_ha, soil_health_index, economic_impact_million_usd, crop_yield_mt_per_ha, average_temperature_c;
public:
    ClimateChangeImpact()
    {
        id = 0;
        country = "null";
        region = "null";
        crop_type = "null";
        adaptation_strategies = "null";
        year = 0;
        extreme_weather_events = 0;
        total_precipitation_mm = 0.0;
        co2_emissions_mt = 0.0;
        irrigation_access_percent = 0.0;
        pesticide_use_kg_per_ha = 0.0;
        fertilizer_use_kg_per_ha = 0.0;
        soil_health_index = 0.0;
        economic_impact_million_usd = 0.0;
        crop_yield_mt_per_ha = 0.0;
        average_temperature_c = 0.0;
    }
    ClimateChangeImpact(int id, const std::string& country, const std::string& region, const std::string& crop_type, const std::string& adaptation_strategies,
    int year, int extreme_weather_events, double total_precipitation_mm, double co2_emissions_mt, double irrigation_access_percent,
    double pesticide_use_kg_per_ha, double fertilizer_use_kg_per_ha, double soil_health_index, double economic_impact_million_usd, double average_temperature_c)
    {
        this->id = id;
        this->country = country;
        this->region = region;
        this->crop_type = crop_type;
        this->adaptation_strategies = adaptation_strategies;
        this->year = year;
        this->extreme_weather_events = extreme_weather_events;
        this->total_precipitation_mm = total_precipitation_mm;
        this->co2_emissions_mt = co2_emissions_mt;
        this->irrigation_access_percent = irrigation_access_percent;
        this->pesticide_use_kg_per_ha = pesticide_use_kg_per_ha;
        this->fertilizer_use_kg_per_ha = fertilizer_use_kg_per_ha;
        this->soil_health_index = soil_health_index;
        this->economic_impact_million_usd = economic_impact_million_usd;
        this->crop_yield_mt_per_ha = crop_yield_mt_per_ha;
        this->average_temperature_c = average_temperature_c;
    }
    int getId() {
        return id;
    }
    std::string getCountry() const {
        return country;
    }
    std::string getRegion() const {
        return region;
    }
    std::string getCrop_type() const {
        return crop_type;
    }
    std::string getAdaptation_strategies() const {
        return adaptation_strategies;
    }
    int getYear() {
        return year;
    }
    int getExtreme_weather_events() {
        return extreme_weather_events;
    }
    double getTotal_precipitation_mm() {
        return total_precipitation_mm;
    }
    double getCo2_emissions_mt() {
        return co2_emissions_mt;
    }
    double getIrrigation_access_percent() {
        return irrigation_access_percent;
    }
    double getPesticide_use_kg_per_ha() {
        return pesticide_use_kg_per_ha;
    }
    double getFertilizer_use_kg_per_ha() {
        return fertilizer_use_kg_per_ha;
    }
    double getSoil_health_index() {
        return soil_health_index;
    }
    double getEconomic_impact_million_usd() {
        return economic_impact_million_usd;
    }
    double getCrop_yield_mt_per_ha() {
        return crop_yield_mt_per_ha;
    }
    double getAverage_temperature_c() {
        return average_temperature_c;
    }
    void setId(int id) {
        this->id = id;
    }
    void setCountry(std::string country) {
        this->country = country;
    }
    void setRegion(std::string region) {
        this->region = region;
    }
    void setCrop_type(std::string crop_type) {
        this->crop_type = crop_type;
    }
    void setAdaptation_strategies(std::string adaptation_strategies) {
        this->adaptation_strategies = adaptation_strategies;
    }
    void setYear(int year) {
        this->year = year;
    }
    void setExtreme_weather_events(int extreme_weather_events) {
        this->extreme_weather_events = extreme_weather_events;
    }
    void setTotal_precipitation_mm(double total_precipitation_mm) {
        this->total_precipitation_mm = total_precipitation_mm;
    }
    void setCo2_emissions_mt(double co2_emissions_mt) {
        this->co2_emissions_mt = co2_emissions_mt;
    }
    void setIrrigation_access_percent(double irrigation_access_percent) {
        this->irrigation_access_percent = irrigation_access_percent;
    }
    void setPesticide_use_kg_per_ha(double pesticide_use_kg_per_ha) {
        this->pesticide_use_kg_per_ha = pesticide_use_kg_per_ha;
    }
    void setFertilizer_use_kg_per_ha(double fertilizer_use_kg_per_ha) {
        this->fertilizer_use_kg_per_ha =  fertilizer_use_kg_per_ha;
    }
    void setSoil_health_index(double soil_health_index) {
        this->soil_health_index = soil_health_index;
    }
    void setEconomic_impact_million_usd(double economic_impact_million_usd) {
        this->economic_impact_million_usd = economic_impact_million_usd;
    }
    void setCrop_yield_mt_per_ha(double crop_yield_mt_per_ha) {
        this->crop_yield_mt_per_ha = crop_yield_mt_per_ha;
    }
    void setAverage_temperature_c(double average_temperature_c) {
        this->average_temperature_c = average_temperature_c;
    }
    bool loadFile(const std::string& filename, std::vector<ClimateChangeImpact>& objs) {
       std::ifstream fin(filename);

        if(!fin) {
            return false;
        }

        std::string header;
        getline(fin, header);

        std::string country, region, crop_type, adaptation_strategies;
        int id, year, extreme_weather_events;
        double total_precipitation_mm, co2_emissions_mt, irrigation_access_percent, pesticide_use_kg_per_ha,
        fertilizer_use_kg_per_ha, soil_health_index, economic_impact_million_usd, crop_yield_mt_per_ha;
        char comma;

        while (true) {
            if (fin.peek() == '\n' || fin.peek() == EOF) {
                fin.ignore();
                if (fin.eof()) break;
                continue;
            }

            country = "null";
            id = 0;
            region = "null";
            crop_type = "null";
            adaptation_strategies = "null";
            year = 0;
            extreme_weather_events = 0;
            total_precipitation_mm = 0.0;
            co2_emissions_mt = 0.0;
            irrigation_access_percent = 0.0;
            pesticide_use_kg_per_ha = 0.0;
            fertilizer_use_kg_per_ha = 0.0;
            soil_health_index = 0.0;
            economic_impact_million_usd = 0.0;
            crop_yield_mt_per_ha = 0.0;
            average_temperature_c = 0.0;
            //Read in data
            fin >> id >> comma;
            fin >> year >> comma;
            std::getline(fin, country, ',');
            std::getline(fin, region, ',');
            std::getline(fin,crop_type,',');
            fin >> average_temperature_c >> comma;
            fin >> total_precipitation_mm >> comma;
            fin >> co2_emissions_mt >> comma;
            fin >> crop_yield_mt_per_ha >> comma;
            fin >> extreme_weather_events >> comma;
            fin >> irrigation_access_percent >> comma;
            fin >> pesticide_use_kg_per_ha >> comma;
            fin >> fertilizer_use_kg_per_ha >> comma;
            fin >> soil_health_index >> comma;
            std::getline(fin, adaptation_strategies, ',');
            fin >> economic_impact_million_usd;

            double ratio = (irrigation_access_percent/extreme_weather_events);

            std:: cout << "Country: " << country << ", Year: " << year << ", Ratio: " << ratio << " | ";

            ClimateChangeImpact impact(id, country, region, crop_type, adaptation_strategies, year, extreme_weather_events,
                total_precipitation_mm, co2_emissions_mt, irrigation_access_percent, pesticide_use_kg_per_ha,
                fertilizer_use_kg_per_ha, soil_health_index, economic_impact_million_usd, average_temperature_c);
            objs.push_back(impact);
        }
        return true;
    }
#endif //CLIMATE_CHANGE_IMPACT_H

};

