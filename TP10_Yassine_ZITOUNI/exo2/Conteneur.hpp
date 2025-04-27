#ifndef CONTENEUR
#define CONTENEUR
#include <vector>
#include <iostream>
template<typename T>
class Conteneur{
    private:
        std::vector<T> containers;
        int capacite_maximal;
    public:
        Conteneur(int capacite);
        void ajouter(T cible);
        T obtenir(int i);
};
#include "Conteneur.tpp"
#endif