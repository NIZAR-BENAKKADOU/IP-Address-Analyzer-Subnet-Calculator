#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

// Prints a table separator line
void printSeparator();

// Prints a section header with a title
void printHeader(const std::string& title);

// Prints a labeled row inside the table
void printRow(const std::string& label, const std::string& value);

#endif
