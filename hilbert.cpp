#include <iostream>
#include <graphics.h> // For visualization (requires graphics.h library)
#include <cmath>

using namespace std;

// Function to draw a line in the graphics window
void drawLine(int x1, int y1, int x2, int y2) {
    line(x1, y1, x2, y2);
}

// Recursive function to draw the Hilbert Curve
void hilbertCurve(int x, int y, int xi, int xj, int yi, int yj, int n) {
    if (n <= 0) {
        int xStart = x + (xi + yi) / 2;
        int yStart = y + (xj + yj) / 2;
        int xEnd = x + (xi - yi) / 2;
        int yEnd = y + (xj - yj) / 2;

        drawLine(xStart, yStart, xEnd, yEnd);
        return;
    }

    // First sub-Hilbert curve
    hilbertCurve(x, y, yi / 2, yj / 2, xi / 2, xj / 2, n - 1);

    // Second sub-Hilbert curve
    hilbertCurve(x + xi / 2, y + xj / 2, xi / 2, xj / 2, yi / 2, yj / 2, n - 1);

    // Third sub-Hilbert curve
    hilbertCurve(x + xi / 2, y + xj / 2, yi / 2, yj / 2, xi / 2, xj / 2, n - 1);

    // Last recursive segment of Hilbert sub-curve
    hilbertCurve(x + (xi + yi) / 2, y + (xj + yj) / 2, yi / -2, yj / 2, xi / -2, xj / 2, n - 1);
}

int main() {
    // Initialize the graphics window
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int screenWidth = getmaxx();
    int screenHeight = getmaxy();

    // Length of Hilbert curve side and number of iterations
    int length = min(screenWidth, screenHeight) - 20;
    int n = 4; // Order of the Hilbert curve

    // Start drawing the Hilbert curve from the center
    hilbertCurve(10, 10, length, 0, 0, length, n);

    // Wait for user input to close the graphics window
    getchar();
    closegraph();

    return 0;
}
