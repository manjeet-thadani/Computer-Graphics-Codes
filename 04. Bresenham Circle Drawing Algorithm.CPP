// Bresenham Circle Drawing Algorithm
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

	int xc,yc,r,x,y,p;

	cout<<"Enter xc and yc : ";
	cin>>xc>>yc;
	cout<<"Enter Radius : ";
	cin>>r;

	x = 0;
	y =r;

	putpixel(x,y,RED);

	p = 3 - 2*r;

	while (x <= y){
		drawCircle(x,y,xc,yc);
		if (p < 0){
			x += 1;
			p = p + 4*x + 6;
		}
		else{
			x += 1;
			y -= 1;
			p = p + 4*x - 4*y + 10;
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
