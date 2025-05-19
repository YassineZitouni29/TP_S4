#include "KubernetesCluster.hpp"
#include <iostream>
void KubernetesCluster::addNode(shared_ptr<Server> node){
    nodes.push_back(node);
}
bool KubernetesCluster::removePod(const std::string& name){
    for (auto it=Pods.begin(); it!=Pods.end(); ++it){
        if ((*it)->get_name()==name){
            Pods.erase(it);
            return true;
        }
    }
    return false;
}
void KubernetesCluster::deployPod(std::unique_ptr<Pod> pod){
    double summ_cpu = 0, summ_memory = 0;
    for (const auto& container : pod->getContainers()) {
        summ_cpu += container->get_cpu();
        summ_memory += container->get_memory();
    }
    for (const auto& node : nodes) {
        try {
            node->allocate(summ_cpu, summ_memory);
            pod->deploy();
            Pods.push_back(std::move(pod));
            cout<<"Pod deploye avec success"<<endl;
            return;
        }catch(const AllocationException& e){
            continue;
        }
    }
    throw AllocationException("Aucun server n'est disponible pour deployer le Pod");
}

bool KubernetesCluster::schedulePod(Pod& pod){
    double summ_cpu = 0, summ_memory = 0;
    for (auto it=pod.getContainers().begin();it!=pod.getContainers().end();++it){
        summ_cpu+=(*it)->get_cpu();
        summ_memory+=(*it)->get_memory();
    }
    for (auto i = nodes.begin(); i!=nodes.end();++i){
        if ((*i)->get_available_cpu()>=summ_cpu && (*i)->get_available_memory() >=summ_memory) return true;
    }
    return false;
}
Pod* KubernetesCluster::getPod(const std::string& name) const {
    for (auto& pod : Pods) {
        if (pod->get_name() == name) {
            return pod.get();
        }
    }
    return nullptr;
}

string KubernetesCluster::getMetrics() const{
    string res;
    for (const auto& pod: Pods){
        res+=pod->getMetrics();
        res+="\n";
    }
    for (const auto& serve: nodes){
        res+=serve->getMetrics();
        res+='\n';
    }
    return res;
}
ostream& operator<<(ostream& os, KubernetesCluster& cluster){
    os<<cluster.getMetrics()<<endl;
    return os;
}
