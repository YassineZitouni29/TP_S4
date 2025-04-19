#ifndef KUBERNETESCLUSTER_HPP
#define KUBERNETESCLUSTER_HPP
using namespace std;
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Server.hpp"
#include "Pod.hpp"
class KubernetesCluster {
    private:
        vector<shared_ptr<Server>> nodes;
        vector<unique_ptr<Pod>> Pods;
    public:    
        void addNode(std::shared_ptr<Server> node);
        bool removePod(const std::string& name);
        void deployPod(unique_ptr<Pod> pod);
        bool schedulePod(Pod& pod);
        Pod* getPod(const std::string& name) const;
        std::string getMetrics() const;
        friend ostream& operator<<(ostream& os, KubernetesCluster& cluster);
};
#endif