#include <iostream>
#include <string>
#include <vector>

struct LoginAttempt {
    std::string username;
    std::string ip;
    bool successful;
};

int main() {
    std::vector<LoginAttempt> logs = {
        {"admin", "192.168.1.10", false},
        {"admin", "192.168.1.10", false},
        {"admin", "192.168.1.10", false},
        {"vansh", "192.168.1.15", true},
        {"root", "10.0.0.5", false},
        {"root", "10.0.0.5", false},
        {"root", "10.0.0.5", false},
        {"root", "10.0.0.5", false}
    };

    const int threshold = 3;

    std::cout << "=====================================\n";
    std::cout << "       NETWORK SECURITY ANALYZER\n";
    std::cout << "=====================================\n\n";

    for (std::size_t i = 0; i < logs.size(); ++i) {
        int failedAttempts = 0;

        for (std::size_t j = 0; j < logs.size(); ++j) {
            if (logs[i].ip == logs[j].ip && !logs[j].successful) {
                ++failedAttempts;
            }
        }

        if (failedAttempts >= threshold) {
            std::cout << "[ALERT] Suspicious activity detected!\n";
            std::cout << "Username : " << logs[i].username << '\n';
            std::cout << "IP       : " << logs[i].ip << '\n';
            std::cout << "Failures : " << failedAttempts << "\n\n";
        }
    }

    std::cout << "Analysis completed.\n";

    return 0;
}
