#ifndef CLOUD
#define CLOUD
#include <iostream>
#include "KubernetesCluster.hpp"
#include "memory"
using namespace std;
void display(const KubernetesCluster& cluster);
void deployPods(KubernetesCluster& cluster, std::vector<std::unique_ptr<Pod>>& pods);
void saveClusterMetrics(const KubernetesCluster& cluser,const string& filename);
void forEachContainer(const KubernetesCluster& cluster, const function<void(const Container&)>& func);
#endif
