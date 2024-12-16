

#include<iostream>
#include<graphics.h>
using namespace std;
//void bresc(centx,centy,r);
void dda(int x1,int y1,int x2,int y2)
{
	float dx,dy,len,x,y;
	float xic,yic;
	 int i=1;
	
	x=x1;
	y=y1;
	putpixel(x,y,WHITE);
	dx=abs(x2-x1);
	dy=abs(y2-y1);
	if(dx>dy)
	{
	len=dx;
	}
	else
	{
	len=dy;
	}
	xic=(x2-x1)/len;
	yic=(y2-y1)/len;
	
	
	while(i<=len)
	{
		putpixel(x,y,WHITE);
		x=x+xic;
		y=y+yic;
		i++;
		//delay(2000);
	}
	delay(5000);
	//closegraph();

}

void bresc(int centx,int centy,int r)
{
	int p,x,y;
	x=0;
	y=r;
	p=3-(2*r);
	do
	{
		putpixel(centx+x,centy-y,WHITE);
		putpixel(centx-x,centy-y,WHITE);
		putpixel(centx-x,centy+y,WHITE);
		putpixel(centx+x,centy+y,WHITE);
		
		putpixel(centx+y,centy+x,WHITE);
		putpixel(centx+y,centy-x,WHITE);
		putpixel(centx-y,centy+x,WHITE);
		putpixel(centx-y,centy-x,WHITE);
		if(p<0)
		{
			p=p+(4*x)+6;
		}	
		else
		{
			p=p+(4*(x-y)+10);
			y=y-1;		
		}	
		x=x+1;
	}while(x<y);
	
}
int main()
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);	
	int r,centx,centy;
	
	cout<<"enter x-coordinate of center";
	cin>>centx;	
	
	cout<<"enter y-coordinate of center";
	cin>>centy;	
	
	cout<<"enter the radius of circle";
	cin>>r;
	
	bresc(centx,centy,r);
	bresc(centx,centy,r/2);
	dda(centx,centy-r,centx-0.865*r,centy+r/2);
	dda(centx-0.865*r,centy+r/2,centx+0.865*r,centy+r/2);
	dda(centx+0.865*r,centy+r/2,centx,centy-r);
	closegraph();
}





