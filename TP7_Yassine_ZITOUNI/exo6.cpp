#include "iostream"
#include <fstream>
#include <string>
using namespace std;

class Fichier {
private:
    fstream* flux;
    string nomFichier;

public:
    Fichier(string nom): nomFichier(nom), flux(new fstream){};
    void sauvegarder(const string& texte) {
        flux->open(nomFichier, ios::app); // Ouvrir en mode écriture
        if (flux->is_open()) {
            cout << "Sauvegarde des donnees...\n";
            *flux << texte;
            *flux<< '\n';
            flux->close();
        }
    }
    // Méthode pour afficher le contenu du fichier
    void charger() {
        flux->open(nomFichier, ios::in); // Ouvrir en mode lecture
        if (flux->is_open()) {
            cout << "Lecture des donnees..."<<endl;
            string ligne;
            cout << "Contenu du fichier :"<<endl;
            while (getline(*flux, ligne)) {
                cout << ligne << endl;
            }
            flux->close();
        }
    }
    ~Fichier() {
        delete flux;
        std::cout << "Memoire du flux liberee"<<endl;
    }
};
int main() {
    Fichier fichier("test.txt");
    fichier.sauvegarder("yassine");
    fichier.sauvegarder("Bonjour, ceci est un test.");
    fichier.charger();
    return 0;
}
