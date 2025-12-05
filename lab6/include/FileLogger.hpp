#pragma once
#include "Observer.hpp"
#include <fstream>
#include <string>

// Observer для записи событий в файл
class FileLogger : public Observer {
private:
    std::ofstream log_file_;

public:
    FileLogger(const std::string& filename = "log.txt");
    ~FileLogger();
    
    void onKill(const std::string& killer, const std::string& victim) override;
};

