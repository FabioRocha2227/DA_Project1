//
// Created by nmls1 on 13/04/2022.
//

#ifndef DA_PROJECT_CARRINHAS_H
#define DA_PROJECT_CARRINHAS_H

#include <vector>
#include "encomendas.h"

class Truck {
private:
    int maxVol;
    int maxWeight;
    int cost;
    std::vector<Truck> trucks;

public:
    Truck();
    Truck(int maxVol, int maxWeight, int cost);

    ///Getter para o Volume máaximo da carrinha
    ///@return volume da carrinha
    int getMaxVolume() const;

    ///Getter para o Peso máximo da carrinha
    ///@return Peso da carrinha
    int getMaxWeight() const;

    ///Getter para o Custo da carrinha
    ///@return Custo da carrinha
    int getCost() const;

    ///Getter para o vetor de todas as carrinha
    ///@return vetor com todas as carrinhas
    std::vector<Truck>getTrucks() const;

    ///Setter para o Volume de uma carrinha
    ///@param maxVol - Define novo volume máximo para a carrinha
    void setMaxVolume(int maxVol);

    ///Setter para o Peso máximo de uma carrinha
    ///@param maxWeight - Define novo Peso máximo para a carrinha
    void setMaxWeight(int maxWeight);

    ///Setter para o Custo de uma carrinha
    ///@param cost - Define novo custo de a carrinha

    void setCost(int cost);

    ///Lê as carrinhas de um ficheiro
    void readTrucks();
    ///Ordena as Carrinhas por (Peso + Volume)
    void sortTrucks();
    /// Ordena as Carrinha por Ratio
    void sortTrucks2();
    /*int binPacking(std::vector<Truck> trucks, std::vector<Package> packages);*/

    ///Compara duas carrinhas por (Peso + Volume)
    ///@param t1 - carrinha 1 para ser comparada
    ///@param t2 - carrinha 2 para ser comparada
    ///@return true se carrinha 1 ter maior (Peso + Volume) do que a carrinha 2
    bool compareBySizeAndVolumeTruck(const Truck& t1, const Truck& t2);

    ///Compara duas carrinhas por Ratio
    ///@param t1 - carrinha 1 para ser comparada
    ///@param t2 - carrinha 2 para ser comparada
    ///@return true se carrinha 1 ter um maior ratio
    bool compare_sRatio(const Truck &lhs, const Truck &rhs);

};


#endif //DA_PROJECT_CARRINHAS_H
