#include "Cloud_util.hpp"
#include "iostream"
#include "fstream"
void display(const KubernetesCluster& cluster){
    cout<<cluster.getMetrics();
}
void deployPods(KubernetesCluster& cluster, vector<unique_ptr<Pod>>& pods){
    for (auto& pod:pods){
        cluster.deployPod(std::move(pod));
    }
}
void saveClusterMetrics(const KubernetesCluster& cluster, const string& filename){
    ofstream outputfile(filename);
    if (!outputfile){
        throw FileException("Ce fichier ne peut pas etre ouvert pour l'instant");
    }else{
        outputfile<< cluster.getMetrics()<<endl;
        outputfile.close();
        cout<<"Les metriques ont ete sauvgardés avec succes"<<endl;
    }
}
void forEachContainer(const KubernetesCluster& cluster, const std::function<void(const Container&)>& func) {
    for (auto& pod : cluster.Pods) {
        if (pod) {  
            for (const auto& container : pod->getContainers()) {
                if (container) { 
                    func(*container);  
                }
            }
        }
    }
}
