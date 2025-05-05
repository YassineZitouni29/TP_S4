#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    vector<int> values = {10,12,15,17};
    transform(values.begin(),values.end(),values.begin(),[](int x){return x+5;});
    for (int x : values) {
        std::cout << x << " ";
    }
    
}