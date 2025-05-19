#include "Server.hpp"
#include <iostream>
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
    return "[Server: id:" + id + "CPU " + to_string(cpu)+" , Memory, "+ to_string(memory) + " available_CPU "+
     to_string(available_CPU) + " , Available Memory " + to_string(available_MEMORY);
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
