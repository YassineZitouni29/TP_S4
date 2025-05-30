#include <iostream>
#include "Pod.hpp"
#include "iomanip"
#include "sstream"
Pod::Pod(string name, std::unordered_map<std::string, std::string> labels):name(name),labels(labels){}
void Pod::addContainer(std::unique_ptr<Container> container){
    if (labels.find(container->get_id()) != labels.end()) return;

    containers.push_back(std::move(container));
    auto& movedPod = containers.back();
    labels[movedPod->get_id()] = movedPod->getMetrics();
}
string Pod::getMetrics() const{
    ostringstream oss;
    for (auto i=containers.begin(); i!=containers.end();++i){
        oss<<" └─ "<<(*i)->getMetrics();
    }
    return oss.str();
}
bool Pod::removeContainer(const string& id){
    for (auto i=containers.begin(); i!=containers.end();++i){
        if ((*i)->get_id() == id){
            labels.erase((*i)->get_id());
            containers.erase(i);
            return true;
        }
    }
    return false;
}
void Pod::deploy(){
    for (auto i=containers.begin(); i!=containers.end(); ++i){
        (*i)->start();
    }
}
ostream& operator<<(ostream& os, const Pod& p){
    os<<p.name<<" "<<p.getMetrics()<<endl;
    return os;
}
const vector<unique_ptr<Container>>& Pod::getContainers() const{
    return containers;
}
string Pod::get_name(){
    return name;
}
