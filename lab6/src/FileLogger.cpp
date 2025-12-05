#include "../include/FileLogger.hpp"
#include <iostream>

FileLogger::FileLogger(const std::string& filename) {
    log_file_.open(filename, std::ios::app);
    if (!log_file_.is_open()) {
        std::cerr << "Warning: Could not open log file: " << filename << std::endl;
    }
}

FileLogger::~FileLogger() {
    if (log_file_.is_open()) {
        log_file_.close();
    }
}

void FileLogger::onKill(const std::string& killer, const std::string& victim) {
    if (log_file_.is_open()) {
        log_file_ << killer << " killed " << victim << std::endl;
        log_file_.flush();
    }
}

