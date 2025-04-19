#ifndef SERVER
#define SERVER
#include "Ressource.hpp"
#include <string>
using namespace std;
class Server: public Resource{
    private:
        double available_CPU;
        double available_MEMORY;
    public:
        Server(std::string id, double cpu, double memory);
        bool allocate(double cpu, double memory);
        void start() override;
        void stop() override;
        string getMetrics() const override;
        friend ostream& operator<<(std::ostream& os, const Server& s);
        double get_available_cpu();
        double get_available_memory();
};
#endif