#include <iostream>
using namespace std;

int main() {
    int port;

    cout << "====================================\n";
    cout << "      NETWORK PORT SCANNER\n";
    cout << "====================================\n";

    cout << "Enter port number (1-65535): ";
    cin >> port;

    if (port < 1 || port > 65535) {
        cout << "\n[!] Invalid port number.\n";
        return 0;
    }

    cout << "\nScanning port " << port << "...\n\n";

    switch (port) {
        case 21:
            cout << "[OPEN] FTP - Port 21\n";
            break;

        case 22:
            cout << "[OPEN] SSH - Port 22\n";
            break;

        case 23:
            cout << "[OPEN] Telnet - Port 23\n";
            break;

        case 25:
            cout << "[OPEN] SMTP - Port 25\n";
            break;

        case 53:
            cout << "[OPEN] DNS - Port 53\n";
            break;

        case 80:
            cout << "[OPEN] HTTP - Port 80\n";
            break;

        case 443:
            cout << "[OPEN] HTTPS - Port 443\n";
            break;

        case 3306:
            cout << "[OPEN] MySQL - Port 3306\n";
            break;

        case 8080:
            cout << "[OPEN] HTTP Proxy - Port 8080\n";
            break;

        default:
            cout << "[CLOSED/UNKNOWN] Port " << port << "\n";
    }

    cout << "\nScan completed.\n";

    return 0;
}
