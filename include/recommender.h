// recommender.h
#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include "parser.h" // Include the parser header for the Flight struct
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <sstream>

namespace recommender {

// Define a struct to represent a Recommendation
struct Recommendation {
    parser::Flight flight;
    int days_difference;
};

// Declare the function to recommend flights
std::vector<Recommendation> recommend_flights(const std::vector<parser::Flight>& flights);

// Declare the test function
void test();

} // namespace recommender

#endif // RECOMMENDER_H
