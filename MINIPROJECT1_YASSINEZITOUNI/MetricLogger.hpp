#ifndef METRIC_LOGGER_H
#define METRIC_LOGGER_H

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class MetricLogger {
public:
    static void logToStream(const T& obj, ostream& stream = cout,const string& prefix = "") {
        stream << prefix;
        if (!prefix.empty()) stream << " - ";
        stream << obj.getMetrics() << endl;
    } 
};
#endif 