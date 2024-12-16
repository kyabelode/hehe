#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // File name
    string filename = "example.txt";

    // Writing to the file
    {
        ofstream outFile(filename); // Open file in write mode
        if (!outFile) {
            cerr << "Error: Could not create file " << filename << endl;
            return 1;
        }

        cout << "Writing to the file...\n";
        outFile << "Hello, this is a sample text file." << endl;
        outFile << "File handling in C++ is simple and efficient." << endl;

        outFile.close(); // Close the file
        cout << "Data written successfully.\n";
    }

    // Reading from the file
    {
        ifstream inFile(filename); // Open file in read mode
        if (!inFile) {
            cerr << "Error: Could not open file " << filename << endl;
            return 1;
        }

        cout << "Reading from the file...\n";
        string line;
        while (getline(inFile, line)) { // Read file line by line
            cout << line << endl;
        }

        inFile.close(); // Close the file
    }

    return 0;
}
