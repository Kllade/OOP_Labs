#pragma once
#include "Observer.hpp"
#include <iostream>
#include <string>

// Observer для вывода событий на экран
class ConsoleLogger : public Observer {
public:
    void onKill(const std::string& killer, const std::string& victim) override {
        std::cout << "[BATTLE] " << killer << " killed " << victim << std::endl;
    }
};

