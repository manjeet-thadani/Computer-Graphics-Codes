#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<Math.h>

void main()
{
	clrscr();
	int gd = DETECT , gm;
	initgraph(&gd,&gm,"C://TurboC3//BGI");

	int x1,y1,x2,y2,dx,dy,steps, xinc,yinc;

	cout<<"Enter x1 and y1 : ";
	cin>>x1>>y1;
	cout<<"Enter x2 and y2 : ";
	cin>>x2>>y2;

	dx = x2 - x1;
	dy = y2 - y1;

	if (abs(dx) > abs(dy))
		steps = abs(dx);
	else
		steps = abs(dy);

	xinc = dx / steps;
	yinc = dy / steps;

	int x = x1, y= y1;

	putpixel(x,y,RED);

	for (int k = 1 ; k <= steps ; k++ ){
		x += xinc;
		y += yinc;
		putpixel(x,y,RED);
	}
	getch();
}
