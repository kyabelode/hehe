#include <iostream>
#include <graphics.h>
using namespace std;

struct edge {
    int x1, y1, x2, y2;
    float slope_inverse;
};

int main() {
    int gd = DETECT, gm, n, i, j, ymin = 480, ymax = 0;
    int x[10], y[10];
    edge edges[10];
    float intersections[10];

    // Initialize graphics mode
    initgraph(&gd, &gm, NULL);

    // Input number of vertices
    cout << "Enter the number of vertices of the polygon: ";
    cin >> n;

    // Input vertices and calculate ymin, ymax
    cout << "Enter the vertices (x y):\n";
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        if (y[i] < ymin) ymin = y[i];
        if (y[i] > ymax) ymax = y[i];
    }

    // Store edge data
    for (i = 0; i < n; i++) {
        edges[i].x1 = x[i];
        edges[i].y1 = y[i];
        edges[i].x2 = x[(i + 1) % n];
        edges[i].y2 = y[(i + 1) % n];

        // Calculate 1/slope for each edge
        if (edges[i].y2 - edges[i].y1 != 0)
            edges[i].slope_inverse = (float)(edges[i].x2 - edges[i].x1) / (edges[i].y2 - edges[i].y1);
        else
            edges[i].slope_inverse = 0; // Horizontal line
    }

    // Draw the polygon
    for (i = 0; i < n; i++) {
        line(edges[i].x1, edges[i].y1, edges[i].x2, edges[i].y2);
    }

    // Scanline fill algorithm
    for (int y = ymax; y >= ymin; y--) {
        int count = 0;

        // Find intersections of scanline with polygon edges
        for (i = 0; i < n; i++) {
            if ((y >= edges[i].y1 && y < edges[i].y2) || (y >= edges[i].y2 && y < edges[i].y1)) {
                intersections[count++] = edges[i].x1 + edges[i].slope_inverse * (y - edges[i].y1);
            }
        }

        // Sort intersections
        for (i = 0; i < count - 1; i++) {
            for (j = 0; j < count - i - 1; j++) {
                if (intersections[j] > intersections[j + 1]) {
                    swap(intersections[j], intersections[j + 1]);
                }
            }
        }

        // Draw horizontal lines between pairs of intersections
        for (i = 0; i < count; i += 2) {
            line((int)intersections[i], y, (int)intersections[i + 1], y);
        }

        delay(50); // Visualization delay
    }

    delay(5000); // Hold final result
    closegraph();
    return 0;
}

/*input
100 100
200 200
300 100
200 50*/