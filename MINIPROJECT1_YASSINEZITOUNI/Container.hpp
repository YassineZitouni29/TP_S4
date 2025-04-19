#ifndef CONTAINER
#define CONTAINER
#include <iostream>
#include "Ressource.hpp"
class Container: public Resource{
    private:
        string image;
    public:
        Container(string id, string image, double cpu, double memory);
        void start() override;
        void stop() override;
        string get_id();
        double get_cpu();
        double get_memory();
        string getMetrics() const override;
        friend ostream& operator<<(ostream& os, const Container& c);
};
#endif