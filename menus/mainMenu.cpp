//
// Created by nmls1 on 22/04/2022.
//

#include <iostream>
#include "mainMenu.h"
#include "../src/company.h"

MainMenu::MainMenu() {}

void MainMenu::display() {
    Package package;
    Truck truck;
    Company company;
    package.readPackages();
    truck.readTrucks();

    char c;

    std::cout << "DA_project\n\n\n";
    std::cout << "[1] Cenario1\n"
              << "[2] Cenario2\n"
              << "[3] Cenario3\n";
    std::cin >> c;

    switch (c) {
        case '1':
            package.sortPackages();
            truck.sortTrucks();
            std::cout << "Objetivo:\n";
            std::cout << "O objetivo principal e minimizar o numero de estafetas para a entrega de todos os pedidos ou do maior numero de pedidos, num dia.\n\n";
            std::cout << "Solucao:\n";
            std::cout << "So precisamos de " << company.cenario1(truck.getTrucks(), package.getPackages()) << " carrinhas para distribuir todas as encomendas\n";
            break;
        case '2':
            package.sortPackages2();
            truck.sortTrucks2();
            std::cout << "Objetivo:\n";
            std::cout << "O objetivo principal e maximizar o lucro da empresa (diferenca entre a receita total e o custo total)\n"
                         "para a entrega de todos os pedidos ou do maior numero de pedidos, num dia, pelos estafetas\n"
                         "selecionados.\n\n";
            std::cout << "Solucao:\n";
            std::cout << "O lucro maximo e " << company.cenario2(truck.getTrucks(), package.getPackages()) << ".\n";
            break;
        case '3':
            std::cout << "Objetivo:\n";
            std::cout << "O objetivo principal e minimizar o tempo medio previsto das entregas expresso a serem realizadas\n"
                         "num dia.\n\n";
            std::cout << "Solucao:\n";
            std::cout << "Podemos entregar " << company.cenario3(package.getPackages()) << " encomendas num dia\n";
            break;
    }
}