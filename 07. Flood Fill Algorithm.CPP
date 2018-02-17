// Flood Fill Algorithm
#include<iostream.h>
#include<conio.h>
#include<graphics.h>

void fFill(int x, int y, int fCol = BLUE, int oCol = BLACK)
{
	int cColor = getpixel(x,y);
	if (cColor == oCol)
	{
		putpixel(x,y,fCol);
		fFill(x+1,y);
		fFill(x-1,y);
		fFill(x,y+1);
		fFill(x,y-1);
	}
}


void main()
{
	clrscr();
	int gd = DETECT, gm;
	initgraph(&gd,&gm,"C://TurboC3//BGI");
	cout<<"****Flood Fill Algorithm****"<<endl;
	setcolor(RED);
	rectangle(50,50,100,100);
	fFill(70,70);
	getch();
}
