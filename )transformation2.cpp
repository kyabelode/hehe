#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

class Point {
public:
    float x, y;

    Point(float x = 0, float y = 0) : x(x), y(y) {}

    // Overload + operator for translation
    Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }

    // Overload * operator for scaling
    Point operator*(float scale) const {
        return Point(x * scale, y * scale);
    }

    // Rotate point about the origin
    Point rotate(float angle) const {
        float rad = angle * M_PI / 180.0; // Convert angle to radians
        return Point(
            x * cos(rad) - y * sin(rad),
            x * sin(rad) + y * cos(rad)
        );
    }
};

class Triangle {
public:
    Point p1, p2, p3;

    Triangle(Point a, Point b, Point c) : p1(a), p2(b), p3(c) {}

    // Translation
    Triangle operator+(const Point &t) const {
        return Triangle(p1 + t, p2 + t, p3 + t);
    }

    // Scaling
    Triangle operator*(float scale) const {
        return Triangle(p1 * scale, p2 * scale, p3 * scale);
    }

    // Rotation
    Triangle rotate(float angle) const {
        return Triangle(p1.rotate(angle), p2.rotate(angle), p3.rotate(angle));
    }

    // Draw triangle
    void draw() const {
        line(p1.x, p1.y, p2.x, p2.y);
        line(p2.x, p2.y, p3.x, p3.y);
        line(p3.x, p3.y, p1.x, p1.y);
    }
};

class Rhombus {
public:
    Point p1, p2, p3, p4;

    Rhombus(Point a, Point b, Point c, Point d) : p1(a), p2(b), p3(c), p4(d) {}

    // Translation
    Rhombus operator+(const Point &t) const {
        return Rhombus(p1 + t, p2 + t, p3 + t, p4 + t);
    }

    // Scaling
    Rhombus operator*(float scale) const {
        return Rhombus(p1 * scale, p2 * scale, p3 * scale, p4 * scale);
    }

    // Rotation
    Rhombus rotate(float angle) const {
        return Rhombus(p1.rotate(angle), p2.rotate(angle), p3.rotate(angle), p4.rotate(angle));
    }

    // Draw rhombus
    void draw() const {
        line(p1.x, p1.y, p2.x, p2.y);
        line(p2.x, p2.y, p3.x, p3.y);
        line(p3.x, p3.y, p4.x, p4.y);
        line(p4.x, p4.y, p1.x, p1.y);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // User input for triangle vertices
    cout << "Enter the vertices of the equilateral triangle:" << endl;
    Point t1, t2, t3;
    cout << "Vertex 1 (x y): ";
    cin >> t1.x >> t1.y;
    cout << "Vertex 2 (x y): ";
    cin >> t2.x >> t2.y;
    cout << "Vertex 3 (x y): ";
    cin >> t3.x >> t3.y;

    // User input for rhombus vertices
    cout << "Enter the vertices of the rhombus:" << endl;
    Point r1, r2, r3, r4;
    cout << "Vertex 1 (x y): ";
    cin >> r1.x >> r1.y;
    cout << "Vertex 2 (x y): ";
    cin >> r2.x >> r2.y;
    cout << "Vertex 3 (x y): ";
    cin >> r3.x >> r3.y;
    cout << "Vertex 4 (x y): ";
    cin >> r4.x >> r4.y;

    // Create triangle and rhombus objects
    Triangle triangle(t1, t2, t3);
    Rhombus rhombus(r1, r2, r3, r4);

    // Draw original shapes
    setcolor(WHITE);
    triangle.draw();
    rhombus.draw();

    // User input for translation
    Point translation;
    cout << "Enter translation vector (dx dy): ";
    cin >> translation.x >> translation.y;

    // Translate shapes
    Triangle translatedTriangle = triangle + translation;
    Rhombus translatedRhombus = rhombus + translation;

    setcolor(YELLOW);
    translatedTriangle.draw();
    translatedRhombus.draw();

    // User input for scaling
    float scale;
    cout << "Enter scaling factor: ";
    cin >> scale;

    // Scale shapes
    Triangle scaledTriangle = triangle * scale;
    Rhombus scaledRhombus = rhombus * scale;

    setcolor(GREEN);
    scaledTriangle.draw();
    scaledRhombus.draw();

    // User input for rotation
    float angle;
    cout << "Enter rotation angle (in degrees): ";
    cin >> angle;

    // Rotate shapes
    Triangle rotatedTriangle = triangle.rotate(angle);
    Rhombus rotatedRhombus = rhombus.rotate(angle);

    setcolor(RED);
    rotatedTriangle.draw();
    rotatedRhombus.draw();

    // Wait for user input and close graphics
    getch();
    closegraph();
    return 0;
}
