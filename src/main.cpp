#include <vector>
#include <string>
#include <iostream>
#include "parser.h"

using namespace std;

void test_headers() {
    parser::test();
}

int main(int argc, char *argv[]) {
    test_headers();

    string airline_name = argv[1];
    string airline_file = "data/airlines/" + airline_name + ".csv";
    vector<parser::Flight> flights = parser::parse_csv(airline_file);

    // Test parser
    for (const auto& flight: flights) {
        cout << "Price:" << flight.price << endl;
    }
}
