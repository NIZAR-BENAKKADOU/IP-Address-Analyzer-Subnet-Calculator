#include "subnet.h"

uint32_t getDefaultMask(char ipClass) {
    switch (ipClass) {
        case 'A': return 0xFF000000;  // 255.0.0.0       /8
        case 'B': return 0xFFFF0000;  // 255.255.0.0     /16
        case 'C': return 0xFFFFFF00;  // 255.255.255.0   /24
        default:  return 0x00000000;
    }
}

int maskToCIDR(uint32_t mask) {
    int cidr = 0;
    while (mask & 0x80000000) {
        cidr++;
        mask <<= 1;
    }
    return cidr;
}

uint32_t calculateNetwork(uint32_t ip, uint32_t mask) {
    return ip & mask;
}

uint32_t calculateBroadcast(uint32_t ip, uint32_t mask) {
    return ip | (~mask);
}

uint32_t calculateHostCount(uint32_t mask) {
    uint32_t hostBits = ~mask;
    if (hostBits <= 1) return 0;
    return hostBits - 1;
}

uint32_t subnetForHosts(int requiredHosts, int& cidrOut) {
    int hostBits = 1;
    while (((1 << hostBits) - 2) < requiredHosts) {
        hostBits++;
        if (hostBits > 30) break;
    }
    cidrOut = 32 - hostBits;

    uint32_t mask = 0xFFFFFFFF;
    mask <<= hostBits;
    return mask;
}
