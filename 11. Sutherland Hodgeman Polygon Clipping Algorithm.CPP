// Sutherland Hodgeman Polygon Clipping Algorithm
#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<process.h>

// Clip  Window
int x1=100, y1=100, x2=400, y2=100, x3=400, y3=400, x4=100, y4=400;
int xmin=100, ymin=400, xmax=400, ymax=100;

// Stores polygon coordinates -- Before Clipping
int x[5], y[5];
// Stores polygon coordinates -- After Clipping
int xa[5], ya[5];
int n = 0;

void clip(float, float, float);

void main()
{
	clrscr();
	int gd = DETECT, gm;
	int i, vertices;
	float m;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	cout<<"*****Sutherland HodgeMan Polygon Clipping Algorithm*****"<<endl;

	//draws clip window
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);

	cout<<"Enter number of vertices : ";
	cin>>vertices;

	for(i=0 ; i<vertices; i++){
		cout<<"Enter coordinates for "<<i+1<<" vertice : ";
		cin>>x[i]>>y[i];
	}

	// Draws Polygon -- Before Clipping
	for(i=0 ; i<vertices-1 ; i++){
		line(x[i], y[i], x[i+1], y[i+1]);
	}
	line(x[i], y[i], x[0], y[0]);

	// Clipping polygon side by side
	for(i=0 ; i<vertices-1 ; i++){
		m = (y[i+1] - y[i])/(x[i+1] - x[i]);
		clip(x[i], y[i], m);
		clip(x[i+1], y[i+1], m);
	}
	m = (y[i] - y[0])/(x[i] - x[0]);
	clip(x[i], y[i], m);
	clip(x[0], y[0], m);

	setcolor(BLUE);
	for(i=0 ; i<vertices-1 ; i++){
		line(xa[i], ya[i], xa[i+1], ya[i+1]);
	}

	getch();
}

void clip(float e, float f, float m){
	while(e<xmin ||  e>xmax || f<ymin || f>ymax) {
		if(e < xmin){
			f += m*(xmin-e);
			e = xmin;
		}
		else if(e > xmax){
			f += m*(xmax-e);
			e = xmax;
		}
		else if(f < ymin){
			e += (ymin - f)/m;
			f = ymin;
		}
		else if(f > ymax){
			e += (ymax - f)/m;
			f = ymax;
		}
	}
	xa[n] = e;
	ya[n] = f;
	n++;
}