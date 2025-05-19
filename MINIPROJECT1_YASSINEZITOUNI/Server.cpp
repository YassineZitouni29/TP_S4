#include "Server.hpp"
#include <iostream>
#include "iomanip"
#include "sstream"
Server::Server(string id,double cpu, double memory):Resource(id, cpu, memory), available_CPU(cpu), available_MEMORY(memory){}
void Server::start(){
    active = true;
}
void Server::stop(){
    active = false;
}
bool Server::allocate(double cpu,double memory){
    if (cpu<=available_CPU && memory<=available_MEMORY && this->active){
        available_CPU-=cpu;
        available_MEMORY-=memory;
        return true;
    }
    if (!this->active){
        throw AllocationException("Allocation Error: Serveur "+this->id+" est inactif");
    }else{
        throw AllocationException("Allocation Error: Serveur "+this->id+" :ressource insuffisante");
    }
}
string Server::getMetrics() const{
    ostringstream oss;
    oss<<left<<"[Server: "<<setw(8)<<id
    <<"| Total"<<setw(5)<<cpu<<" CPU"
    <<setw(6)<<memory<<" Memory"
    <<"| Free"<<setw(5)<<available_CPU<<"CPU"
    <<setw(6)<<available_MEMORY<<endl;
    return oss.str();
}
ostream& operator<<(std::ostream& os, const Server& s){
    os<<"[Server: id: "<<s.id<< "CPU "<<s.cpu<<", Memory, "<<s.memory<< " available_CPU "<<s.available_CPU<<
    " , Available Memory "<<s.available_MEMORY<<endl;
    return os;
}
double Server::get_available_memory(){
    return available_MEMORY;
}
double Server::get_available_cpu(){
    return available_CPU;
}
