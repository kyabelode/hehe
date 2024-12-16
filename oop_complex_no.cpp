#include <iostream>
using namespace std;

class Complex;

istream& operator>>(istream& in, Complex& c);
ostream& operator<<(ostream& out, const Complex& c);

class Complex {
private:
    double real;  // Real part
    double imag;  // Imaginary part

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Parameterized constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Overload operator+ to add two complex numbers
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload operator* to multiply two complex numbers
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Declare friend functions
    friend istream& operator>>(istream& in, Complex& c);
    friend ostream& operator<<(ostream& out, const Complex& c);
};

istream& operator>>(istream& in, Complex& c) {
    cout << "Enter the real part: ";
    in >> c.real;
    cout << "Enter the imaginary part: ";
    in >> c.imag;
    return in;
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real;
    if (c.imag >= 0) {
        out << "+";
    }
    out << c.imag << "i";
    return out;
}

int main() {
    Complex c1, c2;

    cout << "Enter the first complex number:\n";
    cin >> c1;

    cout << "Enter the second complex number:\n";
    cin >> c2;

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "Sum: " << sum << endl;
    cout << "Product: " << product << endl;

    return 0;
}
