#pragma once
#include <string>

// Observer интерфейс для паттерна Observer
class Observer {
public:
    virtual ~Observer() = default;
    virtual void onKill(const std::string& killer, const std::string& victim) = 0;
};

