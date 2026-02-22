#ifndef IP_UTILS_H
#define IP_UTILS_H

#include <string>
#include <cstdint>

// Converts a 32-bit IP to dotted-decimal string
std::string ipToString(uint32_t ip);

// Parses and validates an IPv4 address, storing its 32-bit form in 'result'
bool parseIPAddress(const std::string& input, uint32_t& result);

// Determines the classful network class (A-E) from the first octet
char getIPClass(uint32_t ip);

#endif
