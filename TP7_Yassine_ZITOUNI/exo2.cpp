#include "iostream"
#include "string"
using namespace std; 
class Joueur{
    private:
        string name;
        int score;
    public:
        void display_information(){
            cout <<"The name of the player is : "<< name <<endl;;
            cout<< "The score of the player " <<name << " is : " << score<<endl;
        }
        Joueur(string Name, int Score): name{Name},score{Score} {};
        ~Joueur(){
            cout<<"object deleted"<<endl;
        }
};
int main(){
    Joueur* joueur1 = new Joueur ("Yakodasan", 40);
    Joueur* joueur2 = new Joueur ("Yassine", 30);
    joueur1->display_information();
    joueur2->display_information();
    delete joueur1;
    delete joueur2;
    return 0;
}