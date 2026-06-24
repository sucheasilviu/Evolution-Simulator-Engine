#pragma once
#include <vector>
#include <iostream>
#include <string>

// FUNCȚIE SABLON
// pt a forta o valoare sa ramana in niste limite (ex: rata mutatie intre 0.0 si 1.0)
template <typename T>
T clampValue(T value, T minVal, T maxVal) {
    if (value < minVal) return minVal;
    if (value > maxVal) return maxVal;
    return value;
}

// CLASA SABLON
// pt a stoca istoricul oricarei metrici pe parcursul generatiilor
template <typename T>
class MetricsTracker {
private:
    std::vector<T> history;
public:
    void addRecord(const T& record) {
        history.push_back(record);
    }

    void printHistory(const std::string& metricName) const {
        std::cout << "-> Istoric " << metricName << ": [ ";
        for (const auto& val : history) {
            std::cout << val << " ";
        }
        std::cout << "]\n";
    }
};