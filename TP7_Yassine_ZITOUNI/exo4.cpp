#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Object{
    string name;
    int quantity;
    public:
        Object(string Name, int Quantity): name{Name}, quantity{Quantity} {};
        string giveName(){
            return name;
        }
        int giveQuantity(){
            return quantity;
        }
};
class Inventaire{
    vector<Object*> list;
    public: 
        void addElement(string name, int quantity);
        void showInventaire();
        ~Inventaire(){
            for (size_t i=0; i<list.size(); ++i){
                delete list.at(i);
            }
            cout<<"Espace memoire libere"<<endl;
        }
};
int main(){
    Inventaire Inventaire1;
    Inventaire1.addElement("pomme", 3);
    Inventaire1.addElement("epee", 1);
    Inventaire1.showInventaire();
}
void Inventaire::addElement(string name, int quantity){
    Object* myObject = new Object(name, quantity);
    list.push_back(myObject);
    cout<< "Ajout de "<< name << " (x"<< quantity<<")" << endl;
}
void Inventaire::showInventaire(){
    cout<<"Inventaire"<<endl;
    for (size_t i=0; i<list.size(); ++i){
        cout<<"- "<<list.at(i)->giveName()<<" : " << list.at(i)->giveQuantity()<<endl;
    }
}