#include <iostream>
#include <sstream>
#include <string>
using namespace std;

bool isValidIP(string ip) {
    stringstream ss(ip);
    string part;
    int count = 0;

    while (getline(ss, part, '.')) {
        if (part.empty()) return false;

        for (char c : part) {
            if (!isdigit(c)) return false;
        }

        int num = stoi(part);

        if (num < 0 || num > 255)
            return false;

        count++;
    }

    return count == 4;
}

int main() {
    string ip;

    cout << "Enter IPv4 address: ";
    cin >> ip;

    if (isValidIP(ip))
        cout << "Valid IPv4 address.\n";
    else
        cout << "Invalid IPv4 address.\n";

    return 0;
}
