// recommender.cpp
#include "recommender.h"

namespace recommender {

int calculate_days_difference(const parser::Flight& flight1, const parser::Flight& flight2) {
    // Convert string start dates to std::chrono::system_clock::time_point
    std::tm tm1 = {};
    std::tm tm2 = {};
    std::istringstream iss1(flight1.start);
    std::istringstream iss2(flight2.start);

    iss1 >> std::get_time(&tm1, "%Y-%m-%d");
    iss2 >> std::get_time(&tm2, "%Y-%m-%d");

    auto tp1 = std::chrono::system_clock::from_time_t(std::mktime(&tm1));
    auto tp2 = std::chrono::system_clock::from_time_t(std::mktime(&tm2));

    // Calculate the duration between the two time points
    auto duration = tp2 - tp1;

    // Convert duration to days
    int days_difference = std::chrono::duration_cast<std::chrono::days>(duration).count();

    return days_difference;
}

// Function to recommend flights based on criteria
std::vector<Recommendation> recommend_flights(const std::vector<parser::Flight>& flights) {
    std::vector<Recommendation> recommendations;

    // Iterate through all pairs of flights and check the criteria
    for (size_t i = 0; i < flights.size(); ++i) {
        for (size_t j = i + 1; j < flights.size(); ++j) {
            // Calculate the difference in days
            int days_difference = calculate_days_difference(flights[i], flights[j]);

            // Check the criteria: difference in days more than 3
            if (days_difference > 3) {
                // Create a Recommendation struct and add it to the vector
                Recommendation recommendation;
                recommendation.flight = flights[i];
                recommendation.days_difference = days_difference;
                recommendations.push_back(recommendation);
            }
        }
    }

    // Sort the recommendations by price (cheapest to highest)
    std::sort(recommendations.begin(), recommendations.end(),
              [](const Recommendation& a, const Recommendation& b) {
                  return a.flight.price < b.flight.price;
              });

    return recommendations;
}

// Define test function
void test() {
    std::cout << "Hello from recommender." << std::endl;
}

} // namespace recommender
