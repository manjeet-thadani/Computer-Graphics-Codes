// MID-POINT Circle Drawing Algorithm
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<Math.h>

void drawCircle(int x,int y,int xc,int yc);

void main()
{
	clrscr();
	int gd = DETECT , gm;
	initgraph(&gd,&gm,"C://TurboC3//BGI");

	int xc,yc,r,x,y;

	cout<<"Enter xc and yc : ";
	cin>>xc>>yc;
	cout<<"Enter Radius : ";
	cin>>r;

	x = 0;
	y =r;

	putpixel(x,y,RED);

	float p = (5/4.0) - r;

	while (x <= y)
	{
		drawCircle(x,y,xc,yc);
		if (p < 0)
		{
			x += 1;
			p = p + 2*x + 1;
		}
		else
		{
			x += 1;
			y -= 1;
			p = p + 2*x - 2*y + 1;
		}
		drawCircle(x,y,xc,yc);
	}
	getch();
}

void drawCircle(int x,int y,int xc,int yc)
{
	putpixel(y+xc,x+yc,RED);
	putpixel(x+xc,y+yc,RED);
	putpixel(-x+xc,y+yc,RED);
	putpixel(-y+xc,x+yc,RED);
	putpixel(-y+xc,-x+yc,RED);
	putpixel(-x+xc,-y+yc,RED);
	putpixel(x+xc,-y+yc,RED);
	putpixel(y+xc,-x+yc,RED);
}