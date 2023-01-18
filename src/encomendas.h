//
// Created by nmls1 on 13/04/2022.
//

#ifndef DA_PROJECT_ENCOMENDAS_H
#define DA_PROJECT_ENCOMENDAS_H

#include <vector>

class Package {
private:
    int volume;
    int weight;
    int reward;
    int duration;
    std::vector<Package> packages;

public:
    Package();
    Package(int volume,  int weight, int reward, int duration);

    ///Getter para o Volume de uma encomenda
    ///@return Volume da encomenda
    int getVolume() const;

    ///Getter para o Peso de uma encomenda
    ///@return Peso da encomenda
    int getWeight() const;

    ///Getter para a recomepnsa de uma encomenda
    ///@return Recompensa da encomenda
    int getReward() const;

    ///Getter para a duracao de entrega de uma encomenda
    ///@return duracao de entrega da encomenda
    int getDuration() const;

    ///Getter para o vetor de todas as encomenda
    ///@return Vetor com todas as encomenda
    std::vector<Package>getPackages() const;

    ///Setter para o Volume de uma encomenda
    ///@param Novo volume a atribuir a essa encomenda
    void setVolume(int volume);

    ///Setter para o Peso de uma encomenda
    ///@param Novo Peso a atribuir a essa encomenda
    void setWeight(int weight);

    ///Setter para a recompensa de uma encomenda
    ///@param Nova recompensa a atribuir a essa encomenda
    void setReward(int reward);

    ///Setter para a duracao de entrega de uma encomenda
    ///@param Nova durcao de entrega a atribuir a essa encomenda
    void setDuration(int duration);

    /// Lê as encomendas de um ficheiro
    void readPackages();

    ///Ordena as encomendas por (Peso + Volume)
    void sortPackages();

    ///Ordena as encomendas por Ratio
    void sortPackages2();

    ///Compara duas encomendas por (Peso + Volume)
    ///@param p1 - primeira encomenda a ser comparada
    ///@param p2 - segunda encomenda a ser comparada
    ///@return true caso encomenda 1 tenha maior(Peso + volume) do que a encomenda 2
    bool compareBySizeAndVolume(const Package &p1, const Package &p2);

    ///Compara duas encomendas por ratio
    ///@param p1 - primeira encomenda a ser comparada
    ///@param p2 - segunda encomenda a ser comparada
    ///@return true caso encomenda 1 tenha maior ratio do que a encomenda 2
    bool compare_fRatio(const Package& lhs, const Package& rhs);
};


#endif //DA_PROJECT_ENCOMENDAS_H
