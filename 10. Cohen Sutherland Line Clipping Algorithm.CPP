// Cohen Sutherland Line Clipping Algorithm
#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<process.h>

// for storing end points
int xa,ya,xb,yb;
//for saving outcodes "TBRL"
int a[4];
int b[4];

// Clip  Window
int x1=100,y1=100,x2=400,y2=100,x3=400,y3=400,x4=100,y4=400;
int xmin=100,ymin=400,xmax=400,ymax=100;

int i;
int x1t,x2t,y1t,y2t;

void getOutCodes();
int visibleRegion();
int getLineSegments(int, int, int, int, int, int[]);

void main()
{
	clrscr();
	int gd = DETECT , gm;
	initgraph(&gd,&gm,"C:\\TurboC3\\BGI");

	cout<<"*****Cohen Sutherland Line Clipping Algorithm*****"<<endl;

	//draws clip window
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);

	cout<<"Enter A (x1,y1) : ";
	cin>>xa>>ya;
	cout<<"Enter B (x2,y2) : ";
	cin>>xb>>yb;

	getOutCodes();
	setcolor(RED);
	line(xa,ya,xb,yb);
	int choice = visibleRegion();
	switch(choice){
		case 0:
			setcolor(BLUE);
			line(xa,ya,xb,yb);
			break;
		case 1:
			break;
		case 2:
			x1t = xa; y1t = ya;
			getLineSegments(xa,ya,xb,yb,1,a); // for getting intersection points
			x2t = xb; y2t = yb;
			getLineSegments(xb,yb,xa,ya,2,b);
			setcolor(BLUE);
//			cout<<x1t<<" "<<y1t<<" "<<x2t<<" "<<y2t;
			line(x1t,y1t,x2t,y2t);
			break;
	}
	getch();
}

void getOutCodes(){
	//Left Clipper
	if (xa<xmin){
		a[3]=1;
		a[2]=0;
		if (ya>ymin){
			a[0]=0;
			a[1]=1;
		}
		else if (ya<ymax){
			a[0]=1;
			a[1]=0;
		}
		else{
			a[0]=0;
			a[1]=0;
		}
	}
	//right clipper
	else if (xa>xmax){
		a[2]=1;
		a[3]=0;
		if (ya<ymax){
			a[0]=1;
			a[1]=0;
		}
		else if (ya>ymax){
			a[0]=0;
			a[1]=1;
		}
		else {
			a[0]=0;
			a[1]=1;
		}
	}
	else if (ya<ymax){
		a[0]=1;
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}
	else if (ya>ymin){
		a[0]=0;
		a[1]=1;
		a[2]=0;
		a[3]=0;
	}
	else{
		a[0]=0; a[1]=0; a[2]=0; a[3]=0;
	}

	if (xb<xmin){
		b[3]=1;
		b[2]=0;
		if (yb>ymin){
			b[0]=0;
			b[1]=1;
		}
		else if (yb<ymax){
			b[0]=1;
			b[1]=0;
		}
		else{
			b[0]=0;
			b[1]=0;
		}
	}
	//right clipper
	else if (xb>xmax){
		b[2]=1;
		b[3]=0;
		if (yb<ymax){
			b[0]=1;
			b[1]=0;
		}
		else if (yb>ymin){
			b[0]=0;
			b[1]=1;
		}
		else {
			b[0]=0;
			b[1]=0;
		}
	}
	else if (yb<ymax){
		b[0]=1;
		b[1]=0;
		b[2]=0;
		b[3]=0;
	}
	else if (yb>ymin){
		b[0]=0;
		b[1]=1;
		b[2]=0;
		b[3]=0;
	}
	else{
		b[0]=0; b[1]=0; b[2]=0; b[3]=0;
	}
}

int visibleRegion(){
	int inside = 1;
	for(i=0; i <4; i++){
		if (!(a[i]==0 && b[i]==0)){
			inside=0;
			break;
		}
	}
	if (inside == 1)
		return 0; // Line is completely inside
	int outside = 0;
	for(i=0;i<4;i++){
		if (a[i]==1 && b[i]==1)
			outside = 1;
	}
	if (outside == 1)
		return 1; //Line is completely outside;
	else
		return 2; // partially visible
}

int getLineSegments(int tempx1, int tempy1, int tempx2, int tempy2,int choice, int code[]){
	float m,n;
	int tempx,tempy;
	if (code[3] == 1) tempx = xmin;
	else if (code[2] == 1) tempx = xmax;
	if (code[3] == 1 || code[2] == 1){
		m = (float) (tempy2 - tempy1)/(tempx2 - tempx1);
		n = tempy1 + (m * (tempx - tempx1));
		if (choice == 1){
			x1t = tempx; y1t = n;
			if (y1t <= ymin && y1t >= ymax)
				return 0;
		}else if (choice == 2){
			x2t = tempx; y2t = n;
			if (y2t <= ymin && y2t >= ymax)
				return 0;
		}
	}

	if (code[0] == 1) // Top Clipping
		tempy = ymax;
	else if (code[1] == 1) // Bottom Clipping
		tempy = ymin;
	if (code[0] == 1 || code[1] == 1){
		m = (float) (tempy2 - tempy1)/(tempx2 - tempx1);
		n = (float)tempx1 + (float)(tempy - tempy1)/m;
		if(choice == 1){  x1t = n; y1t = tempy; }
		else if (choice == 2){  x2t = n; y2t = tempy; }
		return 0;
	}
}