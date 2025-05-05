#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Livre {
    public:
    string title;
    int pages;
    Livre(const string& t, int p) : title(t), pages(p) {}
};
ostream& operator<<(ostream& os, const Livre& livre) {
    os << livre.title << " - " << livre.pages << " pages";
    return os;
}

int main() {
    vector<Livre> bibliotheque = {
        Livre("C++ Moderne", 350),
        Livre("Apprendre Python", 500),
        Livre("Algorithmique", 450)
    };

    
    sort(bibliotheque.begin(), bibliotheque.end(),
        [](const Livre& a, const Livre& b) {
            return a.title < b.title;
        }
    );

    cout << "- Tri par titre :" << endl;
    for (const auto& livre : bibliotheque) {
        cout << livre << endl;
    }

    cout << endl;


    sort(bibliotheque.begin(), bibliotheque.end(),
        [](const Livre& a, const Livre& b) {
            return a.pages > b.pages;
        }
    );

    cout << "- Tri par nombre de pages décroissant :" <<endl;
    for (const auto& livre : bibliotheque) {
        cout << livre << endl;
    }

    return 0;
}