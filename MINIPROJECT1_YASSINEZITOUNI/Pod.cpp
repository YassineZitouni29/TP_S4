#include <iostream>
#include "Pod.hpp"
Pod::Pod(string name, std::unordered_map<std::string, std::string> labels):name(name),labels(labels){}
void Pod::addContainer(std::unique_ptr<Container> container){
    if (labels.find(container->get_id()) != labels.end()) return;

    containers.push_back(std::move(container));
    auto& movedPod = containers.back();
    labels[movedPod->get_id()] = movedPod->getMetrics();
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
string Pod::getMetrics() const{
    string res;
    for (auto i=containers.begin(); i!=containers.end();++i){
        res+= (*i)->getMetrics();
        res +="\n";
    }
    return res;
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