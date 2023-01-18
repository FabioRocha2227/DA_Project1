//
// Created by nmls1 on 21/04/2022.
//

#include <map>
#include <iostream>
#include "company.h"


Company::Company() {}

int Company::cenario1(std::vector<Truck> trucks, std::vector<Package> packages){
    int res = 0;

    for(int i = 0; i < packages.size(); i++){
        int j;
        for(j = 0; j < res; j++){
            if(trucks[j].getMaxWeight() >= packages[i].getWeight() && trucks[j].getMaxVolume() >= packages[i].getVolume()){
                trucks[j].setMaxWeight(trucks[j].getMaxWeight() - packages[i].getWeight());
                trucks[j].setMaxVolume(trucks[j].getMaxVolume() - packages[i].getVolume());
                break;
            }

        }
        if(j == res){
            trucks[j].setMaxWeight(trucks[j].getMaxWeight() - packages[i].getWeight());
            trucks[j].setMaxVolume(trucks[j].getMaxVolume() - packages[i].getVolume());
            res++;
        }
    }
    return res;
}

int Company::cenario2(std::vector<Truck> trucks, std::vector<Package> packages) {
    int weightT, volT, reward = 0, cost = 0,profitTotal = 0;

    for (int i = 0; i < trucks.size() && !packages.empty(); i++)
    {
        weightT = trucks[i].getMaxWeight();
        volT = trucks[i].getMaxVolume();
        reward = 0;
        while (!packages.empty())
        {
            Package package = packages.back();
            packages.pop_back();
            if (weightT - package.getWeight() >= 0 && volT - package.getVolume() >= 0)
            {
                reward += package.getReward();
                weightT -= package.getWeight();
                volT -= package.getVolume();
            }
            else
            {
                packages.push_back(package);
                break;
            }
        }
        cost = trucks[i].getCost();
        if(reward - cost > 0){
            profitTotal += reward - cost;
        }else{
            break;
        }
    }
    return profitTotal;
}

int Company::cenario3(std::vector<Package> packages) {
    std::multimap<int,Package> mapa;
    int timeCounter = 0;
    int packageCounter = 0;
    for (int i = 0; i < packages.size(); i++)
    {
        mapa.insert(std::pair<int,Package>(packages[i].getDuration(), packages[i]));
    }
    auto mapIndex = mapa.begin();
    while (timeCounter <= 8 * 3600)
    {
        timeCounter += mapIndex->first;
        if(timeCounter >= 8*3600){
            timeCounter -= mapIndex->first;
            break;
        }
        packageCounter++;
        mapIndex++;
        if(mapIndex == mapa.end()) break;
    }
    return packageCounter;
}
