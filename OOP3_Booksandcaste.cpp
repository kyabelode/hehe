#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Publication {
protected:
    string title;
    float price;

public:
    // Default constructor
    Publication() : title(""), price(0.0) {}

    // Method to input data for Publication
    virtual void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter price: ";
        cin >> price;
        if (price < 0) throw invalid_argument("Price cannot be negative.");
    }

    // Method to display data for Publication
    virtual void putData() const {
        cout << "Title: " << title << endl;
        cout << "Price: $" << price << endl;
    }

    // Virtual destructor
    virtual ~Publication() {}
};

class Book : public Publication {
private:
    int pageCount;

public:
    // Default constructor
    Book() : pageCount(0) {}

    // Method to input data for Book
    void getData() override {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
        if (pageCount < 0) throw invalid_argument("Page count cannot be negative.");
    }

    // Method to display data for Book
    void putData() const override {
        Publication::putData();
        cout << "Page Count: " << pageCount << " pages" << endl;
    }

    // Destructor
    ~Book() {}
};

class Tape : public Publication {
private:
    float playingTime;

public:
    // Default constructor
    Tape() : playingTime(0.0) {}

    // Method to input data for Tape
    void getData() override {
        Publication::getData();
        cout << "Enter playing time (in minutes): ";
        cin >> playingTime;
        if (playingTime < 0) throw invalid_argument("Playing time cannot be negative.");
    }

    // Method to display data for Tape
    void putData() const override {
        Publication::putData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }

    // Destructor
    ~Tape() {}
};

int main() {
    Book book;
    Tape tape;

    try {
        cout << "Enter details for book:\n";
        book.getData();

        cout << "Enter details for tape:\n";
        tape.getData();
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        // Reset data members to zero values
        book = Book();
        tape = Tape();
    }

    cout << "\nDisplaying book details:\n";
    book.putData();

    cout << "\nDisplaying tape details:\n";
    tape.putData();

    return 0;
}
