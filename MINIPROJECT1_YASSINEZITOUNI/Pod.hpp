#ifndef POD
#define POD
#include <iostream>
#include "Container.hpp"
#include "memory"
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Pod{
    private:
        string name;
        vector<unique_ptr<Container>> containers;
        unordered_map<string, string> labels;
    public:    
        Pod(std::string name, std::unordered_map<std::string, std::string> labels = {});
        void addContainer(unique_ptr<Container> container);
        bool removeContainer(const std::string& id);
        void deploy();
        string getMetrics() const;
        friend ostream& operator<<(std::ostream& os, const Pod& p);
        const vector<unique_ptr<Container>>& getContainers() const; 
        string get_name();
};
#endif