#include <iostream>
#include "Container.hpp"
#include "Ressource.hpp"
#include "sstream"
#include "iomanip"
Container::Container(string id, string image, double cpu, double memory): Resource(id, cpu, memory), image(image){}
void Container::start(){
    active = true;
}
void Container::stop(){
    active = false;
}
string Container::getMetrics() const{
    return "[Container: id "+ id + " : CPU " + to_string(cpu) + ", Memory " + to_string(memory) + ", Image " + image + "]";
}
ostream& operator<<(ostream& os, const Container& c){
    os<<"[Container: id"<<c.id <<": CPU"<< c.cpu<<", Memory "<<c.memory<<", Image]"<<c.image<<endl;
    return os;
}
string Container::get_id(){
    return id;
}
double Container::get_cpu(){
    return cpu;
}
double Container::get_memory(){
    return memory;
}
string Container::getMetrics() const{
    ostringstream oss;
    oss<<left<<
    "[container: "<<setw(5)<< id<<
    "| "<<setw(5)<<cpu<<" cpu"<<
    ", "<<setw(6)<<memory<<" memory"
    ", "<<image<<" image"<<endl;
    return oss.str();
}
