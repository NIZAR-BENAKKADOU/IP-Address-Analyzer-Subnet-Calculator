# 🌐 IP Address Analyzer & Subnet Calculator

A command-line C++ tool that analyzes IPv4 addresses and performs subnet calculations.

## Features

- **IP Address Analysis** — Determines the class (A–E) and displays the default subnet mask with CIDR notation.
- **Network Calculations** — Computes the network address, broadcast address, first/last usable host, and total usable host count using the default class mask.
- **Subnetting** — Given a required number of hosts, calculates the optimal subnet mask, new network/broadcast addresses, and valid host range.
- **Input Validation** — Validates IPv4 input and ensures host requirements don't exceed class limits.

## How to Compile & Run

### Compile

```bash
g++ -o network network.cpp
```

### Run

```bash
./network
```

## Example Usage

```
  =========================================
     IP Address Analyzer & Subnet Calculator
  =========================================

  Enter an IPv4 address (e.g. 192.168.1.10): 192.168.1.10

  +=========================================+
  |  IP ADDRESS ANALYSIS                    |
  +=========================================+
  | IP Address          : 192.168.1.10      |
  | Class               : Class C           |
  | Default Mask        : 255.255.255.0 /24 |
  +-----------------------------------------+

  +=========================================+
  |  DEFAULT NETWORK CALCULATIONS           |
  +=========================================+
  | Network Address     : 192.168.1.0       |
  | Broadcast Address   : 192.168.1.255     |
  | First Host          : 192.168.1.1       |
  | Last Host           : 192.168.1.254     |
  | Total Usable Hosts  : 253               |
  +-----------------------------------------+

  Enter the required number of hosts: 50

  +=========================================+
  |  SUBNETTING RESULTS                     |
  +=========================================+
  | Required Hosts      : 50                |
  | Subnet Mask         : 255.255.255.192 /26|
  | Usable Hosts        : 62                |
  | Network Address     : 192.168.1.0       |
  | Broadcast Address   : 192.168.1.63      |
  | First Host          : 192.168.1.1       |
  | Last Host           : 192.168.1.62      |
  +-----------------------------------------+
```

## Project Structure

```
network/
└── network.cpp    # Main source file (single-file program)
```

## Requirements

- A C++ compiler with C++11 support or later (e.g. `g++`, `clang++`, or MSVC)

## Author

Nizar
