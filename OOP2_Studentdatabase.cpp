#include <iostream>
#include <string>
using namespace std;

class Student;

class Display {
public:
    void showStudentDetails(const Student& student);
};

class Student {
private:
    string name;
    int rollNumber;
    string studentClass;
    char division;
    string dateOfBirth;
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

    static int studentCount;

public:
    // Default constructor
    Student() : rollNumber(0), division(' '), bloodGroup("Unknown") {
        name = "Unknown";
        studentClass = "Unknown";
        dateOfBirth = "Unknown";
        contactAddress = "Unknown";
        telephoneNumber = "Unknown";
        drivingLicenseNo = "Unknown";
        studentCount++;
    }

    // Parameterized constructor
    Student(string n, int roll, string cls, char div, string dob, string bg, string addr, string tel, string dl) {
        name = n;
        rollNumber = roll;
        studentClass = cls;
        division = div;
        dateOfBirth = dob;
        bloodGroup = bg;
        contactAddress = addr;
        telephoneNumber = tel;
        drivingLicenseNo = dl;
        studentCount++;
    }

    // Copy constructor
    Student(const Student& other) {
        name = other.name;
        rollNumber = other.rollNumber;
        studentClass = other.studentClass;
        division = other.division;
        dateOfBirth = other.dateOfBirth;
        bloodGroup = other.bloodGroup;
        contactAddress = other.contactAddress;
        telephoneNumber = other.telephoneNumber;
        drivingLicenseNo = other.drivingLicenseNo;
        studentCount++;
    }

    // Destructor
    ~Student() {
        studentCount--;
    }

    // Static member function
    static int getStudentCount() {
        return studentCount;
    }

    // Inline setter function
    inline void setData(string n, int roll, string cls, char div, string dob, string bg, string addr, string tel, string dl) {
        name = n;
        rollNumber = roll;
        studentClass = cls;
        division = div;
        dateOfBirth = dob;
        bloodGroup = bg;
        contactAddress = addr;
        telephoneNumber = tel;
        drivingLicenseNo = dl;
    }

    // Friend class
    friend class Display;

    // Print function
    void printDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << studentClass << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dateOfBirth << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No.: " << drivingLicenseNo << endl;
    }
};

int Student::studentCount = 0;

void Display::showStudentDetails(const Student& student) {
    student.printDetails();
}

int main() {
    Student* students[100];
    int count = 0;
    int choice;

    do {
        cout << "\n--- Student Database Menu ---\n";
        cout << "1. Add New Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Display Total Students\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, cls, dob, bg, addr, tel, dl;
                int roll;
                char div;

                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Roll Number: ";
                cin >> roll;
                cout << "Enter Class: ";
                cin >> cls;
                cout << "Enter Division: ";
                cin >> div;
                cout << "Enter Date of Birth (YYYY-MM-DD): ";
                cin >> dob;
                cout << "Enter Blood Group: ";
                cin >> bg;
                cout << "Enter Contact Address: ";
                cin.ignore();
                getline(cin, addr);
                cout << "Enter Telephone Number: ";
                cin >> tel;
                cout << "Enter Driving License No.: ";
                cin >> dl;

                students[count++] = new Student(name, roll, cls, div, dob, bg, addr, tel, dl);
                cout << "Student added successfully!\n";
                break;
            }
            case 2: {
                if (count == 0) {
                    cout << "No students to display.\n";
                } else {
                    Display display;
                    for (int i = 0; i < count; ++i) {
                        cout << "\n--- Student " << (i + 1) << " ---\n";
                        display.showStudentDetails(*students[i]);
                    }
                }
                break;
            }
            case 3: {
                cout << "Total Students: " << Student::getStudentCount() << endl;
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice! Please try again.\n";
                break;
            }
        }
    } while (choice != 4);

    // Clean up dynamically allocated memory
    for (int i = 0; i < count; ++i) {
        delete students[i];
    }

    return 0;
}
