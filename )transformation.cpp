#include<iostream>
#include<graphics.h>
#include<cmath>
using namespace std;

int main()
{
    int gd = DETECT,gm;
    initgraph(&gd, &gm, NULL);
    initwindow(1000,800);
    float a[3][3];
    int x1,y1,x2,y2,choice;
    cout<<"Enter x1 and y1 coordinates: ";
    cin>>a[0][0]>>a[1][0];
    cout<<"\nEnter x2 and y2 coordinates: ";
    cin>>a[0][1]>>a[1][1];
    cout<<"\nEnter x3 and y3 coordinates: ";
    cin>>a[0][2]>>a[1][2];
    a[2][0] =a[2][1] = a[2][2] = 1;
    line(a[0][0],a[1][0],a[0][1],a[1][1]);
    line(a[0][1],a[1][1],a[0][2],a[1][2]);
    line(a[0][2],a[1][2],a[0][0],a[1][0]);
    delay(10000);
    cout<<"\n1. Translation \n2. Scaling \n3. Rotation";
    cout<<"\nEnter choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        {
            float b[3][3],c[3][3];
            b[0][0] = b[1][1] = b[2][2] = 1;
            b[0][1] = b[1][0] = b[2][0] = b[2][1] = 0;
            cout<<"\nEnter tx and ty: ";
            cin>>b[0][2]>>b[1][2];
            for(int i = 0; i<3; i++)
            {
                for(int j = 0; j<3; j++)
                {
                    c[i][j] = 0;
                    for(int k = 0; k<3; k++)
                    {
                        c[i][j] += b[i][k]*a[k][j];
                    }
                }
            }
            setcolor(BLUE);
            line(c[0][0],c[1][0],c[0][1],c[1][1]);
            line(c[0][1],c[1][1],c[0][2],c[1][2]);
            line(c[0][2],c[1][2],c[0][0],c[1][0]);
            delay(7000);
        }
        break;

    case 2:
        {
            float b[3][3],c[3][3];
            b[0][1] = b[0][2] = b[1][0] = b[1][2] = b[2][0] = b[2][1] = 0;
            b[2][2] = 1;
            cout<<"\nEnter sx and sy: ";
            cin>>b[0][0]>>b[1][1];
            for(int i = 0; i<3; i++)
            {
                for(int j = 0; j<3; j++)
                {
                    c[i][j] = 0;
                    for(int k = 0; k<3; k++)
                    {
                        c[i][j] += b[i][k]*a[k][j];
                    }
                }
            }
            setcolor(BLUE);
            line(c[0][0],c[1][0],c[0][1],c[1][1]);
            line(c[0][1],c[1][1],c[0][2],c[1][2]);
            line(c[0][2],c[1][2],c[0][0],c[1][0]);
            delay(7000);
        }
        break;

    case 3:
        {
            float b[3][3],c[3][3];
            float z;
            cout<<"\nEnter angle: ";
            cin>>z;
            float ang = (z*3.14)/180;
            b[0][2] = b[1][2] = b[2][0] = b[2][1] = 0;
            b[2][2] = 1;
            b[0][0] = cos(ang);
            b[0][1] = sin(ang);
            b[1][0] = -(sin(ang));
            b[1][1] = cos(ang);
            for(int i = 0; i<3; i++)
            {
                for(int j = 0; j<3; j++)
                {
                    c[i][j] = 0;
                    for(int k = 0; k<3; k++)
                    {
                        c[i][j] += b[i][k]*a[k][j];
                    }
                }
            }
            setcolor(BLUE);
            line(c[0][0],c[1][0],c[0][1],c[1][1]);
            line(c[0][1],c[1][1],c[0][2],c[1][2]);
            line(c[0][2],c[1][2],c[0][0],c[1][0]);
            delay(7000);
        }
    }
    closegraph();
    return 0;
}

