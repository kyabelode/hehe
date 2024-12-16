/*Write C++ program using STL for sorting and searching user defined records
 such as personal records (Name, DOB, Telephone number etc) using vector container. */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Define a structure for personal records
struct PersonalRecord {
    string name;
    string dob; // Date of Birth
    string phone;

    // Overload < operator for sorting by name
    bool operator<(const PersonalRecord& other) const {
        return name < other.name;
    }
};

// Function to display records
void displayRecords(const vector<PersonalRecord>& records) {
    for (const auto& record : records) {
        cout << "Name: " << record.name << ", DOB: " << record.dob << ", Phone: " << record.phone << endl;
    }
}

// Function to search for a record by name
void searchRecord(const vector<PersonalRecord>& records, const string& name) {
    auto it = find_if(records.begin(), records.end(), [&name](const PersonalRecord& record) {
        return record.name == name;
    });

    if (it != records.end()) {
        cout << "Record found: Name: " << it->name << ", DOB: " << it->dob << ", Phone: " << it->phone << endl;
    } else {
        cout << "Record not found." << endl;
    }
}

int main() {
    vector<PersonalRecord> records;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Display Records\n";
        cout << "3. Sort Records by Name\n";
        cout << "4. Search Record by Name\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                PersonalRecord record;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, record.name);
                cout << "Enter DOB (dd-mm-yyyy): ";
                getline(cin, record.dob);
                cout << "Enter Phone: ";
                getline(cin, record.phone);
                records.push_back(record);
                break;
            }
            case 2: {
                if (records.empty()) {
                    cout << "No records to display." << endl;
                } else {
                    cout << "\nDisplaying Records:\n";
                    displayRecords(records);
                }
                break;
            }
            case 3: {
                if (records.empty()) {
                    cout << "No records to sort." << endl;
                } else {
                    sort(records.begin(), records.end());
                    cout << "Records sorted by name." << endl;
                }
                break;
            }
            case 4: {
                if (records.empty()) {
                    cout << "No records to search." << endl;
                } else {
                    string name;
                    cout << "Enter name to search: ";
                    cin.ignore();
                    getline(cin, name);
                    searchRecord(records, name);
                }
                break;
            }
            case 5: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    } while (choice != 5);

    return 0;
}
