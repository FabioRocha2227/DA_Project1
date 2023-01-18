//
// Created by nmls1 on 21/04/2022.
//

#ifndef DA_PROJECT_COMPANY_H
#define DA_PROJECT_COMPANY_H


#include "carrinhas.h"

class Company {
public:
    Company();

    ///Procura a combinação que minimiza o número de estafetas
    /// @param trucks - vetor que contem todas as carrinhas disponiveis
    /// @param packages - vetor que contem todas as encomendas para serem entregues
    /// @return menor número de estafetas para entregar todas as encomendas
    int cenario1(std::vector<Truck> trucks, std::vector<Package> packages);

    ///Procura a combinação que garente lucro máximo à empresa
    /// @param trucks - vetor que contem todas as carrinhas disponiveis
    /// @param packages - vetor que contem todas as encomendas para serem entregues
    /// @return lucro máximo possível
    int cenario2(std::vector<Truck> trucks, std::vector<Package> packages);

    ///Procura a combinação que maximiza as encomendas expresso entregues num dia
    /// @param packages - vetor que contem todas as encomendas para serem entregues
    /// @return máximo de encomendas possível
    int cenario3(std::vector<Package> packages);

    ///Avalia qual o maior inteiro
    ///@param a - primeiro número para comparar
    ///@param b - segundo número para comparar
    ///@return o maior dos dois números
    int max1(int a, int b);


};


#endif //DA_PROJECT_COMPANY_H
