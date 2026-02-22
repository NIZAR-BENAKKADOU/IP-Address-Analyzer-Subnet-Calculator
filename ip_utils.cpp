#include "ip_utils.h"
#include <sstream>

std::string ipToString(uint32_t ip) {
    return std::to_string((ip >> 24) & 0xFF) + "." +
           std::to_string((ip >> 16) & 0xFF) + "." +
           std::to_string((ip >> 8)  & 0xFF) + "." +
           std::to_string( ip        & 0xFF);
}

bool parseIPAddress(const std::string& input, uint32_t& result) {
    int octets[4];
    char dots[3];

    std::istringstream iss(input);

    for (int i = 0; i < 4; i++) {
        if (!(iss >> octets[i])) return false;
        if (octets[i] < 0 || octets[i] > 255) return false;
        if (i < 3) {
            if (!(iss >> dots[i])) return false;
            if (dots[i] != '.') return false;
        }
    }

    std::string leftover;
    if (iss >> leftover) return false;

    result = (static_cast<uint32_t>(octets[0]) << 24) |
             (static_cast<uint32_t>(octets[1]) << 16) |
             (static_cast<uint32_t>(octets[2]) <<  8) |
              static_cast<uint32_t>(octets[3]);
    return true;
}

char getIPClass(uint32_t ip) {
    uint8_t firstOctet = (ip >> 24) & 0xFF;

    if (firstOctet <= 127) return 'A';
    if (firstOctet <= 191) return 'B';
    if (firstOctet <= 223) return 'C';
    if (firstOctet <= 239) return 'D';
    return 'E';
}
