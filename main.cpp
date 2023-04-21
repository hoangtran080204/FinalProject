#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;


int main()
{
    // Open the CSV file
    std::ifstream file("SpotifyFeatures.csv");

    // Check if the file is open
    if (!file.is_open()) {
        std::cout << "Failed to open file" << std::endl;
        return 1;
    }

    // Read the CSV file row by row and split each row into columns
    std::string line;
    std::getline(file, line); // skip the first line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::vector<std::string> columns;
        std::string column;
        while (std::getline(ss, column, ',')) {
            columns.push_back(column);
        }
        if(columns[0] == "Rap")
        // Print the first and third column of the row
        std::cout << columns[2] << ", " << columns[4] << std::endl;
    }

    return 0;
}
