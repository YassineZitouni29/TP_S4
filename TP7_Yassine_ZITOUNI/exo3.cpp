#include "iostream"
#include "string"
using namespace std; 
class Joueur{
    private:
        string name;
        int score;
    public:
        void display_information(){
            cout <<"Joueur : "<< name <<endl;;
            cout<< "Score : " << score<<endl;
        }
        Joueur(string Name, int Score): name{Name},score{Score} {
            cout<<"Constructor called"<<endl;
        };
        ~Joueur(){
            cout<<"Destructor called"<<endl;
        }
};
int main(){
    Joueur* joueur2 = new Joueur ("Yassine", 30);
    joueur2->display_information();
    delete joueur2;
}