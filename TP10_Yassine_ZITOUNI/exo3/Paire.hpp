#ifndef PAIRE
#define PAIRE
#include <iostream>
#include "PaireBase.hpp"
using namespace std;
template<typename T, typename S>
class Paire: public PaireBase{
    private:
        T premier;
        S second;
    public:
        Paire(T premier, S second): premier(premier), second(second){};
        void afficher() override{
            if constexpr (is_same<T, bool>::value && is_same<S, bool>::value){
                cout<< "Premier: "<<(premier ? "True" : "false")<< "Second: "<<  (second ? "True": "false" )<<endl;
            }else if constexpr (is_same<T, bool>::value){
                cout<< "Premier: "<<(premier ? "True" : "false")<<"Second: "<<second<<endl;
            }else if constexpr (is_same<S, bool>::value){
                cout<< "Premier: "<<premier <<" Second: "<<(second ? "True" : "false")<<endl;
            }else{
                cout<<"Premier: "<<premier<<" Second: "<<second<<endl;
            }
        }
};
template<typename T>
class Paire<T, int>: public PaireBase{
    private:
        T premier;
        int second;
    public:
    Paire(T premier, int second): premier(premier), second(second){};
    void afficher() override{
        cout<<"This is for ints \t"<<"Premier: "<<premier<<" Second: "<<second<<endl;
    }
};
#endif