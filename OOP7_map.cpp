#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Create a map to store state populations
    map<string, int> statePopulations;

    // Predefined data for states and their populations
    statePopulations["California"] = 39538223;
    statePopulations["Texas"] = 29145505;
    statePopulations["Florida"] = 21538187;
    statePopulations["New York"] = 20201249;
    statePopulations["Pennsylvania"] = 13002700;

    string stateName;

    while (true) {
        cout << "\nEnter the name of a state (or type 'exit' to quit): ";
        getline(cin, stateName);

        // Exit condition
        if (stateName == "exit") {
            cout << "Exiting program..." << endl;
            break;
        }

        // Search for the state in the map
        auto it = statePopulations.find(stateName);
        if (it != statePopulations.end()) {
            cout << "Population of " << stateName << ": " << it->second << endl;
        } else {
            cout << "State not found in the records." << endl;
        }
    }

    return 0;
}
