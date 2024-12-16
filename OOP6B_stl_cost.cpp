#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Structure to represent an Item
struct Item {
    int code;
    string name;
    double cost;
    int quantity;

    // Overload the << operator for easy output
    friend ostream& operator<<(ostream& os, const Item& item) {
        os << "Code: " << item.code << ", Name: " << item.name
           << ", Cost: " << item.cost << ", Quantity: " << item.quantity;
        return os;
    }
};

// Function to display all items
void displayItems(const vector<Item>& items) {
    for (const auto& item : items) {
        cout << item << endl;
    }
}

int main() {
    vector<Item> items;

    // Adding sample items
    items.push_back({101, "Pen", 1.5, 100});
    items.push_back({102, "Notebook", 3.0, 50});
    items.push_back({103, "Pencil", 0.5, 200});
    items.push_back({104, "Eraser", 0.75, 150});

    cout << "Initial List of Items:\n";
    displayItems(items);

    // Sorting items by cost
    sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
        return a.cost < b.cost;
    });

    cout << "\nItems Sorted by Cost:\n";
    displayItems(items);

    // Searching for an item by code
    int searchCode;
    cout << "\nEnter item code to search: ";
    cin >> searchCode;

    auto it = find_if(items.begin(), items.end(), [searchCode](const Item& item) {
        return item.code == searchCode;
    });

    if (it != items.end()) {
        cout << "Item Found:\n" << *it << endl;
    } else {
        cout << "Item with code " << searchCode << " not found." << endl;
    }

    return 0;
}
