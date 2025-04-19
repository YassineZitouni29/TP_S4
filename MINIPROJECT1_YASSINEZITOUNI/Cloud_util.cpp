#include "Cloud_util.hpp"
#include "iostream"
void display(const KubernetesCluster& cluster){
    cout<<cluster.getMetrics();
}
void deployPods(KubernetesCluster& cluster, vector<unique_ptr<Pod>>& pods){
    for (auto& pod:pods){
        cluster.deployPod(std::move(pod));
    }
}