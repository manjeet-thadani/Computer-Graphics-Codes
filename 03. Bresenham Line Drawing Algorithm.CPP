//Bresenham Line Drawing Algorithm
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<Math.h>

void main()
{
	clrscr();
	int gd = DETECT , gm;
	initgraph(&gd,&gm,"C://TurboC3//BGI");

	int x1,y1,x2,y2,dx,dy,steps;

	cout<<"Enter x1 and y1 : ";
	cin>>x1>>y1;
	cout<<"Enter x2 and y2 : ";
	cin>>x2>>y2;

	putpixel(x1,y1,RED);

	dx = x2 - x1;
	dy = y2 - y1;

	int p = 2*dy - dx;

	for (int k = 1 ; k < dx ; k++ ){
		x1 += 1;
		if (p < 0){
			p += 2*dy;
			putpixel(x1,y1,RED);
		}
		else{
			y1 += 1;
			p = p + 2*dy - 2*dx;
			putpixel(x1,y1,RED);
		}
	}
	getch();
}
