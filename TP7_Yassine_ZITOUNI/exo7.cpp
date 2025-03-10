#include <iostream>
using namespace std;
class SharedPtr{
    private:
        int* ptr;
        int reference;
    public:
        SharedPtr(int* Ptr){
            ptr = Ptr;
            reference=1;
            cout<<"Creation d'un shared ptr"<<endl;
            cout<<"Nombre de references "<<reference<<endl;
        }
        ~SharedPtr(){
            reference--;
            cout<<"Destruction du pointerur\nNombre de references : "<< reference<<endl;
            if (reference==0){
                delete ptr;
                cout<<"Object destruit"<<endl;
            }
        }
        SharedPtr(const SharedPtr& copie) : ptr(copie.ptr), reference(copie.reference) {
            (reference)++;
            std::cout << "Creation d'une copie\n";
            std::cout << "Nombre de references : " << reference << "\n";
        }
};
int main(){
    SharedPtr ptr1(new int(2));
    SharedPtr ptr2= ptr1;
    return 0;
}