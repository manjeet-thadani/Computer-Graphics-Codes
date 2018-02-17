// Reflection of an OBJECT about an ARBITARY POINT
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<process.h>

void main()
{
	clrscr();
	int gd = DETECT , gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
	int x1 = 500, y1 =100, x2 = 500 , y2 = 160 , x3 = 560 ,y3 = 160;

	// draws axis
	line(400,0,400,450);
	line(150,245,800,245);
	moveto(150,245);
	outtextxy(150,245,"x axis ");

	moveto(550,245);
	outtextxy(590,245,"x axis");

	moveto(450,0);
	outtextxy(450,0,"y axis ");
     //	putpixel(400,245,RED);

	//point along which rotation has to be performed
	putpixel(450,200,RED);

	int pointX1 = 450 , pointY1 = 200;


	//draws triangle
	line(500,100,500,160);
	line(500,160,560,160);
	line(560,160,500,100);

	do{
		int c;
		cout<<"1. Reflect \n\
		       2. Exit\n\
		       Enter Choice : ";
		cin>>c;
		switch(c)
		{
			case 1:
				int tempx = pointX1 - 400;
				int tempy = 245 - pointY1;
				putpixel(tempx,tempy,RED);
				x1 -= 2*(x1 - 400);
				y1 += 2*(245 - y1);
				x2 -= 2*(x2 - 400);
				y2 += 2*(245 - y2);
				x3 -= 2*(x3 - 400);
				y3 += 2*(245 - y3);

				x1 += 2*50;
				y1 -= 2*45;
				x2 += 2*50;
				y2 -= 2*45;
				x3 += 2*50;
				y3 -= 2*45;

				line(x1,y1,x2,y2);
				line(x2,y2,x3,y3);
				line(x3,y3,x1,y1);
				break;

			case 2 :
				closegraph();
				exit(0);
		}
	}while(1);
	getch();
}