#include "Logger.h"


vector<string> Logger::logMessages;


void Logger::log(const string& message) {
    logMessages.push_back(message);
}

void Logger::printLogs() {
    for (const auto& log : logMessages) {
        std::cout << log << std::endl;
    }
}
