// File for parsing in stocks and variables from csv files in regression/data/
#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

namespace parser {

// Define a struct to represent a Flight
struct Flight {
    string start;
	string end;
    int price;
    int hours;
    int minutes;
}; // struct Flight

// Declare main parser function
vector<Flight> parse_csv(const std::string& filename);

// Declare test function
void test();

} // namespace parser

#endif