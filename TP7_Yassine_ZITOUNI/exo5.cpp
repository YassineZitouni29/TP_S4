#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Etudiant{
    private:
        string name;
        vector<float> grades;
        float avg;
    public:
        Etudiant(string Name){
            name = Name;
        };
        void addGrade(float grade){
            grades.push_back(grade);
        }
        void average(){
            float summ = 0;
            for (auto it = grades.begin(); it!=grades.end(); ++it){
                summ+=(*it);
            }
            avg = summ/grades.size();
        }
        void displayInformation(){
            this->average();
            cout<<"Name :"<<name<<endl;
            cout<<"Grades : ";
            auto it = grades.begin();
            for (it; it!=grades.end()-1; ++it){
                cout<< *it<<" ,";
            }
            cout<<(*it);
            cout<<"\nThe average is : "<<avg<<endl;
        }
};
int main(){
    Etudiant etudiant1("Yassine");
    etudiant1.addGrade(14);
    etudiant1.addGrade(15);
    etudiant1.addGrade(13);
    etudiant1.displayInformation();
}