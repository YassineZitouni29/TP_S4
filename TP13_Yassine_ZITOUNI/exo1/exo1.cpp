#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Additionneur{
    private:
        int val;
    public:
        Additionneur(int val): val(val){};
        void operator()(int x){
            cout<<(x+val)<<" ";
        }
};
int main(){
    vector<int> tab = {1, 8, 9};
    Additionneur add20(20);
    for_each(tab.begin(), tab.end(), add20);
}