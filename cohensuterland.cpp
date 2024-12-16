#include <iostream>
#include <graphics.h>
#include<math.h>
#include<cstdlib>
using namespace std;

static int LEFT_CODE = 1, RIGHT_CODE = 2, BOTTOM_CODE = 3, TOP_CODE = 8;
static int xmin, xmax, ymin, ymax;

int getcode(int x, int y)
{
    int code = 0;
    if(y > ymax)
        code |= TOP_CODE;
    
    if(y < ymin)
        code |= BOTTOM_CODE;
    
    if(x > xmax)
        code |= RIGHT_CODE;
    
    if(x < xmin)
        code |= LEFT_CODE;
    
    return code;
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);
    
    int x1, y1, x2, y2;
    
    cout << "Enter the endpoints of the line: " << endl;
    cin >> x1 >> y1 >> x2 >> y2;
    
    cout << "Enter the clipping window (xmin, ymin, xmax, ymax): " << endl;
    cin >> xmin >> ymin >> xmax >> ymax;
    
    setcolor(WHITE);
    
    outtextxy(200, 50, (char*)"Before clipping");
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);
    delay(5000);
    
    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    
    int accept = 0;
    
    while (1)
    {
        float m = (float)(y2 - y1) / (x2 - x1);
        
        if (outcode1 == 0 && outcode2 == 0)
        {
            accept = 1;
            break;
        }
        
        else if ((outcode1 & outcode2) != 0)
        {
            break;
        }
        
        else
        {
            int x, y;
            int temp;
        
            if (outcode1 != 0)
                temp = outcode1;
            else 
                temp = outcode2;
        
            if (temp & TOP_CODE)
            {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }   
            else if (temp & BOTTOM_CODE)
            {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            }
            else if (temp & LEFT_CODE)
            {
                x = xmin;
                y = y1 + m * (xmin - x1);
            }  
            else if (temp & RIGHT_CODE)
            {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }  
            
            if (temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }
        
    setcolor(BLUE);
    cleardevice();
    
    if (accept)
    {
        outtextxy(200, 50, (char*)"After clipping");
        rectangle(xmin, ymin, xmax, ymax);
        line(x1, y1, x2, y2);
    }
    else
    {
        outtextxy(200, 50, (char*)"After clipping");
        rectangle(xmin, ymin, xmax, ymax);
    }
    
    getch();
    closegraph();

    return 0;
}
