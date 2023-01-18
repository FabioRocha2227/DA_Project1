//
// Created by nmls1 on 13/04/2022.
//

#include "carrinhas.h"

#include "encomendas.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <map>

Truck::Truck() {}

Truck::Truck(int maxVol, int maxWeight, int cost) {
    this->maxVol = maxVol;
    this->maxWeight = maxWeight;
    this->cost = cost;
}

//Getters
int Truck::getMaxVolume() const {
    return maxVol;
}

int Truck::getMaxWeight() const {
    return maxWeight;
}

int Truck::getCost() const {
    return cost;
}

std::vector<Truck>Truck::getTrucks() const{
    return trucks;
}

//Setters
void Truck::setMaxVolume(int maxVol) {
    this->maxVol = maxVol;
}

void Truck::setMaxWeight(int maxWeight) {
    this->maxWeight = maxWeight;
}

void Truck::setCost(int cost) {
    this->cost = cost;
}

//Functions
void Truck::readTrucks() {
    int maxVol, maxWeight, cost;
    char sep;
    std::string str;

    std::ifstream fin("../data/carrinhas");

    std::getline(fin, str);

    while (fin >> maxVol >> maxWeight >> cost){
        Truck truck(maxVol, maxWeight, cost);
        trucks.push_back(truck);
    }

    fin.close();
}



bool Truck::compareBySizeAndVolumeTruck(const Truck &t1, const Truck &t2) {
    return t1.maxWeight + t1.maxVol > t2.maxWeight + t2.maxVol;
}

bool Truck::compare_sRatio(const Truck &lhs, const Truck &rhs){
    float sRatio1 = (float)lhs.getCost() / (float)lhs.getMaxWeight() + (float)lhs.getCost() / (float)lhs.getMaxVolume();
    float sRatio2 = (float)rhs.getCost() / (float)rhs.getMaxWeight() + (float)rhs.getCost() / (float)rhs.getMaxVolume();
    return (sRatio1 < sRatio2);
}

void Truck::sortTrucks() {
    std::sort(trucks.begin(), trucks.end(), [this](Truck& t1, Truck& t2){return compareBySizeAndVolumeTruck(t1, t2);});
}

void Truck::sortTrucks2(){
    sort(trucks.begin(), trucks.end(), [this](Truck& t1, Truck& t2){return compare_sRatio(t1, t2);});
}