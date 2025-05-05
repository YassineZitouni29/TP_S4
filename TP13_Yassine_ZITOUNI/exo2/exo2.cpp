#include <iostream>
#include <vector>
#include<functional>
using namespace std;

void filtrer(const vector<int>& vec, function<bool(int)> predicat) {
    for (int x : vec) {
        if (predicat(x)) {
            cout << x << " ";
        }
    }
    cout << endl;
}
int main() {
    vector<int> valeurs = {10, 15, 20, 25, 30, 50, 75};


    cout << "x > 20 : ";
    filtrer(valeurs, [](int x) { return x > 20; });

    cout << "x % 2 == 0 : ";
    filtrer(valeurs, [](int x) { return x % 2 == 0; });

    return 0;
}