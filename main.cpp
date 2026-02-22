#include <iostream>
#include <string>
#include <limits>
#include "ip_utils.h"
#include "subnet.h"
#include "display.h"

using namespace std;

int main() {

    cout << endl;
    cout << "  =========================================" << endl;
    cout << "     IP Address Analyzer & Subnet Calculator" << endl;
    cout << "  =========================================" << endl;
    cout << endl;

    // Input validation
    uint32_t ip = 0;
    string ipInput;

    while (true) {
        cout << "  Enter an IPv4 address (e.g. 192.168.1.10): ";
        getline(cin, ipInput);

        if (parseIPAddress(ipInput, ip)) break;

        cout << "  [ERROR] Invalid IPv4 address. Please try again." << endl << endl;
    }

    // IP classification
    char ipClass = getIPClass(ip);
    uint32_t defaultMask = getDefaultMask(ipClass);

    printHeader("IP ADDRESS ANALYSIS");
    printRow("IP Address", ipInput);
    printRow("Class", string("Class ") + ipClass);

    if (ipClass == 'D') {
        printRow("Type", "Multicast");
        printSeparator();
        cout << endl << "  [INFO] Class D addresses are multicast addresses." << endl;
        cout << "         Subnet calculations are not applicable." << endl;
        return 0;
    }
    if (ipClass == 'E') {
        printRow("Type", "Reserved");
        printSeparator();
        cout << endl << "  [INFO] Class E addresses are reserved for experimental use." << endl;
        cout << "         Subnet calculations are not applicable." << endl;
        return 0;
    }

    string defaultMaskStr = ipToString(defaultMask);
    int defaultCIDR = maskToCIDR(defaultMask);
    printRow("Default Mask", defaultMaskStr + " /" + to_string(defaultCIDR));
    printSeparator();

    // Default network calculations
    uint32_t network   = calculateNetwork(ip, defaultMask);
    uint32_t broadcast  = calculateBroadcast(ip, defaultMask);
    uint32_t firstHost  = network + 1;
    uint32_t lastHost   = broadcast - 1;
    uint32_t totalHosts = calculateHostCount(defaultMask);

    printHeader("DEFAULT NETWORK CALCULATIONS");
    printRow("Network Address", ipToString(network));
    printRow("Broadcast Address", ipToString(broadcast));
    printRow("First Host", ipToString(firstHost));
    printRow("Last Host", ipToString(lastHost));
    printRow("Total Usable Hosts", to_string(totalHosts));
    printSeparator();

    // Custom subnetting
    int requiredHosts = 0;

    while (true) {
        cout << endl;
        cout << "  Enter the required number of hosts: ";

        if (cin >> requiredHosts && requiredHosts > 0) {
            if (requiredHosts > static_cast<int>(totalHosts)) {
                cout << "  [ERROR] Required hosts (" << requiredHosts
                     << ") exceeds the maximum available hosts ("
                     << totalHosts << ") for this class." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }

        cout << "  [ERROR] Please enter a valid positive integer." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int newCIDR = 0;
    uint32_t newMask       = subnetForHosts(requiredHosts, newCIDR);
    uint32_t newNetwork    = calculateNetwork(ip, newMask);
    uint32_t newBroadcast  = calculateBroadcast(ip, newMask);
    uint32_t newFirstHost  = newNetwork + 1;
    uint32_t newLastHost   = newBroadcast - 1;
    uint32_t newUsable     = calculateHostCount(newMask);

    printHeader("SUBNETTING RESULTS");
    printRow("Required Hosts", to_string(requiredHosts));
    printRow("Subnet Mask", ipToString(newMask) + " /" + to_string(newCIDR));
    printRow("Usable Hosts", to_string(newUsable));
    printRow("Network Address", ipToString(newNetwork));
    printRow("Broadcast Address", ipToString(newBroadcast));
    printRow("First Host", ipToString(newFirstHost));
    printRow("Last Host", ipToString(newLastHost));
    printSeparator();

    cout << endl << "  Program completed successfully." << endl << endl;

    return 0;
}
