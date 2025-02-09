#include <iostream>
#ifndef EXO
#define EXO 3
#endif

#if EXO == 1
int main(){
#define PI 3.14
#ifdef DEBUGG
    std::cout<<"It's defined";
#endif
return 0;
}
#elif EXO == 2
int main(int argc, char* argv[]){
    for (int i=1; i<argc; ++i){
        std::cout<<"Argument "<<i <<": "<<argv[i]<<std::endl;
    }
    return 0;
}
#elif EXO == 3
int main(){
    using namespace std;
    int variable;
    std::cin >> variable;
    std::cout << "the variable is "<< variable<<std::endl;
    cout<< "the variable is "<< variable<< std::endl;
    return 0;
}
#elif EXO == 4
int main(){
    int var1; 
    float var2;
    std::cin>> var1 >> var2;
    std::cout << "the entered variables are " << var1 << " et " <<var2 <<std::endl;
    return 0;
}
#endif
