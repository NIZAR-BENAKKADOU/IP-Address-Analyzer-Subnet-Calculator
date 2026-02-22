# IP Address Analyzer & Subnet Calculator

A command-line tool built in C++ that performs IPv4 address analysis, classful network calculations, and custom subnetting.

## Features

- **IP Classification** — Identifies the network class (A–E) and default subnet mask
- **Network Calculations** — Computes network address, broadcast address, valid host range, and total usable hosts
- **Custom Subnetting** — Calculates the optimal subnet mask for a given number of required hosts
- **Input Validation** — Rejects malformed addresses and out-of-range values

## Project Structure

```
├── main.cpp          Entry point and program flow
├── ip_utils.h/.cpp   IP parsing, conversion, and classification
├── subnet.h/.cpp     Subnet mask, CIDR, and network calculations
├── display.h/.cpp    Table formatting and output helpers
└── README.md
```

## Build & Run

**Compile:**
```bash
g++ -std=c++17 -o network.exe main.cpp ip_utils.cpp subnet.cpp display.cpp
```

**Run:**
```bash
./network.exe
```

## Example Output

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
  | Total Usable Hosts  : 254               |
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

## Technologies

- **Language:** C++17
- **Libraries:** Standard Library only (`<iostream>`, `<sstream>`, `<cstdint>`, `<iomanip>`)

## Author

**NIZAR BENAKKADOU**

## License

This project is open source and available under the [MIT License](LICENSE).
