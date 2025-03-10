#include <iostream>
#include <string>
using namespace std;
class Joueur{
    string name;
    int score;
    public:
        void display_information(){
            cout <<"The name of the player is : "<< name <<endl;;
            cout<< "The score of the player " <<name << " is : " << score<<endl;
        }
        Joueur(string Name, int Score): name{Name},score{Score} {};
};
int main(){
    auto joueur1 = Joueur("Yassine", 7);
    Joueur joueur2("Taha", 20);
    Joueur* joueur3 = new Joueur("Zakariae", 10);
    Joueur* joueur4 = new Joueur("Adam", 30);
    joueur1.display_information();
    joueur2.display_information();
    joueur3->display_information();
    (*joueur4).display_information();
    delete joueur3;
    delete joueur4;
}