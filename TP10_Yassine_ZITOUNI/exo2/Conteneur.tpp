#include "Conteneur.hpp"
template<typename T>
void Conteneur<T>::ajouter(T cible){
    if (containers.size()<capacite_maximal){
        containers.push_back(cible);
    }else{
        std::cerr<<"Capacite depasee"<<std::endl;
    }
}
template<typename T>
Conteneur<T>::Conteneur(int capacite):capacite_maximal(capacite){};
template<typename T>
T Conteneur<T>::obtenir(int i){
    if (i<capacite_maximal){
        return containers.at(i);
    }
}