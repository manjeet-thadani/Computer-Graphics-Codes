//  2-D Tranformation
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
	int x1 = 500, y1 =100, x2 = 460 , y2 = 160 , x3 = 560 ,y3 = 160;

	// draws axis
	line(400,0,400,450);
	line(150,245,800,245);
	moveto(150,245);
	outtextxy(150,245,"x axis ");

	moveto(550,245);
	outtextxy(590,245,"x axis");

	moveto(450,0);
	outtextxy(450,0,"y axis ");
	putpixel(400,245,RED);

	//draws triangle
	line(500,100,460,160);
	line(460,160,560,160);
	line(560,160,500,100);

	do{
		int c;
		cout<<"			1. Transaltion \n\
			2. Scaling\n\
			3. Reflection\n\
			4. Rotation\n\
			5. Exit\n\
			Enter Choice : ";
		cin>>c;
		switch(c)
		{
			case 1:
				int dx,dy;
				cout<<"Enter dx : ";
				cin>>dx;
				cout<<"Enter dy : ";
				cin>>dy;

				line(x1-dx,y1-dy,x2-dx,y2-dy);
				line(x2-dx,y2-dy,x3-dx,y3-dy);
				line(x3-dx,y3-dy,x1-dx,y1-dy);
				break;

			case 2 :
				double sx,sy;
				cout<<"Enter sx : ";
				cin>>sx;
				cout<<"Enter sy : ";
				cin>>sy;
				sx = sx/100.0;
				sy = sy/100.0;
				line(x1+x1*sx,y1+y1*sy,x2+x2*sx,y2+y2*sy);
				line(x2+x2*sx,y2+y2*sy,x3+x3*sx,y3+y3*sy);
				line(x3+x3*sx,y3+y3*sy,x1+x1*sx,y1+y1*sy);
				break;

			case 3 :
				x1  =x1;
				y1 = y1 + 2*(245-100);
				x2 = x2;
				y2 = y2 + 2*(245-160);
				x3 = x3;
				y3 = y3 + 2*(245-160);
				line(x1,y1,x2,y2);
				line(x2,y2,x3,y3);
				line(x3,y3,x1,y1);
				break;

			case 4 :
				float angle;
				cout<<"Enter Angle : ";
				cin>>angle;
				angle = (3.14/180.0)*angle;

				x3 -= 400;
				y3 -= 245;

				double nx = (x3*cos(angle)) - (y3*sin(angle)) + 400;
				double ny  = (x3*sin(angle)) + (y3*cos(angle)) + 245;

				line(x1,y1,x2,y2);
				line(x2,y2,nx,ny);
				line(nx,ny,x1,y1);
				break;
			case 5 :
				closegraph();
				exit(0);
		}
	}while(1);
	getch();
}