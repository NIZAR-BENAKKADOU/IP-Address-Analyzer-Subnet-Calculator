#ifndef SUBNET_H
#define SUBNET_H

#include <cstdint>

// Returns the default classful subnet mask
uint32_t getDefaultMask(char ipClass);

// Converts a subnet mask to its CIDR prefix length
int maskToCIDR(uint32_t mask);

// Returns the network address (IP & mask)
uint32_t calculateNetwork(uint32_t ip, uint32_t mask);

// Returns the broadcast address (IP | ~mask)
uint32_t calculateBroadcast(uint32_t ip, uint32_t mask);

// Calculates usable host count (2^n - 2)
uint32_t calculateHostCount(uint32_t mask);

// Finds the smallest subnet mask accommodating the required host count
uint32_t subnetForHosts(int requiredHosts, int& cidrOut);

#endif
