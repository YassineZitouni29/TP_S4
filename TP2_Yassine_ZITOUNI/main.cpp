#include <iostream>
#ifndef EXO
#define EXO 3
#endif

#if EXO == 1
int main(){
#define PI 3.14  // define PI
#ifdef DEBUG  //check if the macro DEBUG is defined
    std::cout<<"It's defined";  //if so i display this message
#endif
return 0;
}
#elif EXO == 2
int main(int argc, char* argv[]){  
    for (int i=1; i<argc; ++i){  // I iterate over the argument given by the user
        std::cout<<"Argument "<<i <<": "<<argv[i]<<std::endl;  // I display each of them
    }
    return 0;
}
#elif EXO == 3
int main(){
    using namespace std;
    int variable;
    std::cin >> variable;  // I take the variable given
    std::cout << "the variable is "<< variable<<std::endl; //with std::cout
    cout<< "the variable is "<< variable<< std::endl;  //without
    return 0;
}
#elif EXO == 4
int main(){
    int var1; // the first variable is an integer
    float var2; // the second variable is a float
    std::cin>> var1 >> var2;  // I take both of them
    std::cout << "the entered variables are " << var1 << " et " <<var2 <<std::endl;  // I display
    return 0;
}
#endif
