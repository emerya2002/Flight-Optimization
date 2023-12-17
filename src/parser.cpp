#include "parser.h"
#include <iostream>
#include <fstream>
#include <sstream>

namespace parser {

// Reads in data from a five column CSV file 
// TODO: Change to take 5 columns, called start, end, price, hours, and minutes
// Function to parse CSV and return vector of Flights
vector<Flight> parse_csv(const string& filename) {
    vector<Flight> flights;

	// open csv file
	ifstream file(filename);
	if (!file.is_open()) {
		cerr << "Unable to open file. File name is: " << filename << endl;
		return flights;
	}

	// read each line of the csv file
	string line;
	while(getline(file, line)) {
		stringstream ss(line); // creates a ss object and gives it content of line
		Flight flight;

		// Extract data from the line separated by commas
		if (getline(ss, flight.start, ',') && getline(ss, flight.end, ',')){
			getline(ss, line, ',');
			try {
				// Convert string values to appropriate types
				flight.price = stoi(line);
				getline(ss, line, ',');
				flight.hours = stoi(line);
				getline(ss, line, ',');
				flight.minutes = stoi(line);

				// Add the flight to the vector
				flights.push_back(flight);
			} 
			catch (const invalid_argument& e) {
				cerr << "Error converting string to numeric value: " << e.what() << endl;
				// Handle the error, e.g., set default values for flight
			}
		}
	}
	file.close();
    return flights;
}

// Define test function
void test() {
	cout << "Hello from Parser.cpp" << endl;
}

} // namespace parser
