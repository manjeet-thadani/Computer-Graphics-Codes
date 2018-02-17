// 3D Transformation
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

	int maxX = getmaxx();
	int maxY = getmaxy();

	line(maxX/2,0,maxX/2,maxY);
	line(0,maxY/2,maxX,maxY/2);

	setfillstyle(4,WHITE);

	putpixel(maxX/2,maxY/2,BLUE);

	int midx = maxX/2;
	int midy = maxY/2;

	int p1x = midx + 50;
	int p1y = midy - 120;
	int p2x = midx + 120;
	int p2y = midy - 20;
	int depth = 20;

	bar3d(p1x,p1y,p2x,p2y,depth,1);

	int choice;
	cout<<"1. Translation\n2. Scaling\n3. Rotation\n\nEnter Your Choice : ";
	cin>>choice;

	switch(choice){
		case 1:
			int x,y,z;
			cout<<"Enter x, y, z : ";
			cin>>x>>y>>z;

			bar3d(p1x+x,p1y-y,p2x+x,p2y-y,depth+z,1);
			break;
		case 2:
			float x1,y1,z1;
			cout<<"Enter x, y, z : ";
			cin>>x1>>y1>>z1;
			bar3d(midx+(x1*50),midy - (y1*120), midx + (x1*120), midy - (y1*20), depth*z1,1);
			break;
		case 3:
			int angle;
			cout<<"Enter Rotating Angle : ";
			cin>>angle;

			int xa = 50*cos(angle*3.14/180) - 120*sin(angle*3.14/180);
			int ya = 50*sin(angle*3.14/180) + 120*cos(angle*3.14/180);
			int xb = 120*cos(angle*3.14/180) - 20*sin(angle*3.14/180);
			int yb = 120*sin(angle*3.14/180) + 20*cos(angle*3.14/180);
			cout<<"Rotation about z-axis";
			bar3d(midx+xa, midy-ya, midx+xb, midy-yb, depth, 1);
			break;
	}
	getch();
}