#include <vector>
#include <string>
#include <iostream>
#include "parser.h"
#include "recommender.h"

using namespace std;

void test_headers() {
    parser::test();
    recommender::test();
}

int main(int argc, char *argv[]) {
    test_headers();

    string airline_name = argv[1];
    string airline_file = "data/airlines/" + airline_name + ".csv";
    vector<parser::Flight> flights = parser::parse_csv(airline_file);

    // Call the recommend_flights function
    vector<recommender::Recommendation> recommendations = recommender::recommend_flights(flights);

    // Test parser
    //for (const auto& flight: flights) {
     //  cout << "Start:" << flight.start << ", End:" << flight.end << ", Price: $" << flight.price << ", Hours:" << flight.hours << ", Min:" << flight.minutes << endl;
    // }

    // opening linear output file
    ofstream output_file("FlightAnalysis.txt");
    cout << "** Flights outputted to output file **" << endl;

    // Print the recommended flights
    output_file << "I WANT EK" << endl << endl;
    output_file << "Recommended flights for " << airline_name << " airlines:" << endl << endl;
    for (const auto& recommendation : recommendations) {
      output_file << "Dates: " << recommendation.flight.start << " until " << recommendation.flight.end << ", Price: $" << recommendation.flight.price
         << ", #Days: " << recommendation.days_difference << endl;
    }
}
