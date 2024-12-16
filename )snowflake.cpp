#include<iostream>
#include<cmath>
#include<stdio.h>
#include<graphics.h>

using namespace std;

// Function prototypes
void koch(int x1, int y1, int x2, int y2, int it);
void drawLine(int x1, int y1, int x2, int y2); // Renamed custom line function to avoid conflict with graphics.h

int main() {
    int x1, y1, x2, y2, x3, y3, it;
    float angle = (60 * M_PI) / 180; // Convert 60 degrees to radians

    // User input
    cout << "Enter x1, y1: " << endl;
    cin >> x1 >> y1;
    cout << "Enter x2, y2: " << endl;
    cin >> x2 >> y2;
    cout << "Enter the number of iterations: " << endl;
    cin >> it;

    // Graphics initialization
    int gd = DETECT, gm;
    initgraph(&gd, &gm, nullptr);

    // Calculate the third vertex of the equilateral triangle
    x3 = x1 + (x2 - x1) * cos(angle) + (y2 - y1) * sin(angle);
    y3 = y1 - (x2 - x1) * sin(angle) + (y2 - y1) * cos(angle);

    // Call the koch function for each side of the triangle
    koch(x2, y2, x1, y1, it);
    koch(x3, y3, x2, y2, it);
    koch(x1, y1, x3, y3, it);

    delay(50000); // Hold the window
    closegraph(); // Close the graphics window
    return 0;
}

// Custom line-drawing function (renamed from `line`)
void drawLine(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;
    int len;

    // Determine the length of the line
    if (abs(dx) >= abs(dy)) {
        len = abs(dx);
    } else {
        len = abs(dy);
    }

    // Calculate incremental steps
    float xin = dx / (float) len;
    float yin = dy / (float) len;

    float x = x1;  // Start point x1
    float y = y1;  // Start point y1

    // Loop to draw the line pixel by pixel
    for (int i = 0; i <= len; i++) {
        putpixel(x, y, RED); // Set pixel at (x, y) to RED
        x += xin; // Increment x
        y += yin; // Increment y
    }
}

// Koch curve function
void koch(int x1, int y1, int x2, int y2, int it) {
    float angle = (60 * M_PI) / 180; // 60-degree angle in radians

    // Calculate points to divide the line segment into 3 parts
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;
    int x4 = (x1 + 2 * x2) / 3;
    int y4 = (y1 + 2 * y2) / 3;

    // Calculate the point that forms the peak of the triangle
    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    // Recursion step: If iterations > 0, apply Koch curve recursively
    if (it > 0) {
        koch(x1, y1, x3, y3, it - 1); // Left segment
        koch(x3, y3, x, y, it - 1);   // Triangle segment
        koch(x, y, x4, y4, it - 1);   // Right segment
        koch(x4, y4, x2, y2, it - 1); // Final segment
    } else {
        // Draw the lines when iteration reaches 0
        drawLine(x1, y1, x3, y3);
        drawLine(x3, y3, x, y);
        drawLine(x, y, x4, y4);
        drawLine(x4, y4, x2, y2);
    }
}
