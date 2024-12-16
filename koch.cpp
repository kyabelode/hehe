#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

void koch(int x1, int y1, int x2, int y2, int it)
{
    float angle = 60 * M_PI / 180;
    int x3 = (2 * x1 + x2) / 3;
    int y3 = (2 * y1 + y2) / 3;
    int x4 = (x1 + 2 * x2) / 3;
    int y4 = (y1 + 2 * y2) / 3;
    int x = x3 + (x4 - x3) * cos(angle) + (y4 - y3) * sin(angle);
    int y = y3 - (x4 - x3) * sin(angle) + (y4 - y3) * cos(angle);

    if (it > 0)
    {
        koch(x1, y1, x3, y3, it - 1);
        koch(x3, y3, x, y, it - 1);
        koch(x, y, x4, y4, it - 1);
        koch(x4, y4, x2, y2, it - 1);
    }
    else
    {
        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}

int main(void)
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2, iterations;
    cout << "Enter the coordinates of the first vertex of the triangle (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates of the second vertex of the triangle (x2, y2): ";
    cin >> x2 >> y2;
    cout << "Enter the number of iterations: ";
    cin >> iterations;

    float angle = 60 * M_PI / 180;
    int x3 = x1 + (x2 - x1) * cos(angle) + (y2 - y1) * sin(angle);
    int y3 = y1 - (x2 - x1) * sin(angle) + (y2 - y1) * cos(angle);

    koch(x1, y1, x2, y2, iterations);
    koch(x2, y2, x3, y3, iterations);
    koch(x3, y3, x1, y1, iterations);

    delay(10000);
    closegraph();
    return 0;
}
