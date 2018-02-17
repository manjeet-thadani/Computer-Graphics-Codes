// Boundary Fill Algorithm
#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void bFill(int x, int y, int fCol = BLUE, int bCol = RED)
{
	int cColor = getpixel(x,y);
	if ((cColor != bCol) && (cColor != fCol))
	{
		putpixel(x,y,fCol);
		bFill(x+1,y);
		bFill(x-1,y);
		bFill(x,y+1);
		bFill(x,y-1);
	}
}


void main()
{
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C://TurboC3//BGI");
	cout<<"****Boundary Fill Algorithm****"<<endl;
	setcolor(RED);
	rectangle(50,50,100,100);
	bFill(70,70);
	getch();
}
