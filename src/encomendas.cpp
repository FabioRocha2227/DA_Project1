//
// Created by nmls1 on 13/04/2022.
//

#include "encomendas.h"
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

Package::Package() {}

Package::Package(int volume, int weight, int reward, int duration) {
    this->volume = volume;
    this->weight = weight;
    this->reward = reward;
    this->duration = duration;
}

//Getters
int Package::getVolume() const{
    return volume;
}

int Package::getWeight() const {
    return weight;
}

int Package::getReward() const {
    return reward;
}

int Package::getDuration() const {
    return duration;
}

std::vector<Package>Package::getPackages() const {
    return packages;
}

//Setters
void Package::setVolume(int volume) {
    this->volume = volume;
}

void Package::setWeight(int weight) {
    this->weight = weight;
}

void Package::setReward(int reward) {
    this->reward = reward;
}

void Package::setDuration(int duration) {
    this->duration = duration;
}

//Functions
void Package::readPackages() {
    int volume, weight, reward, duration;
    char sep;
    std::string str;

    std::ifstream fin("../data/encomendas");

    std::getline(fin, str);

    while (fin >> volume  >> weight  >> reward  >> duration){
        Package package(volume, weight, reward, duration);
        packages.push_back(package);
    }

    fin.close();

    int sumvol=0, sumw=0;
    for(auto i : packages){
        sumvol += i.getVolume();
        sumw += i.getWeight();
    }
}

bool Package::compareBySizeAndVolume(const Package &p1, const Package &p2) {
    return p1.weight + p1.volume > p2.weight + p2.volume;
}

bool Package::compare_fRatio(const Package& lhs, const Package& rhs){
    float fRatio1 = (float)lhs.getReward()/(float)lhs.getWeight() + (float)lhs.getReward()/(float)lhs.getVolume();
    float fRatio2 = (float)rhs.getReward()/(float)rhs.getWeight() + (float)rhs.getReward()/(float)rhs.getVolume();
    return (fRatio1 < fRatio2);
}

void Package::sortPackages() {
    std::sort(packages.begin(), packages.end(), [this](Package& p1, Package& p2){return compareBySizeAndVolume(p1, p2);});

}

void Package::sortPackages2(){
    std::sort(packages.begin(), packages.end(), [this](Package& p1, Package& p2){return compare_fRatio(p1, p2);});
}