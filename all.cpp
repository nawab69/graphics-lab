#include <graphics.h>
#include <math.h>
#include <stdio.h>

// Function for finding absolute value
int abs(int n) { return ((n > 0) ? n : (n * (-1))); }

int startX = 0;
int startY = 0;

void pp(int x, int y, int color = RED) {
    putpixel(startX+x, startY-y, color);
}

// DDA Function for line generation
void DDA(int X0, int Y0, int X1, int Y1)
{
	// calculate dx & dy
	int dx = X1 - X0;
	int dy = Y1 - Y0;

	// calculate steps required for generating pixels
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	// calculate increment in x & y for each steps
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;

	// Put pixel for each step
	float X = X0;
	float Y = Y0;
	for (int i = 0; i <= steps; i++) {
		pp(round(X), round(Y),
				RED); // put pixel at (X,Y)
		X += Xinc; // increment in x at each step
		Y += Yinc; // increment in y at each step

	}
}



void bresenham(int x0, int y0, int x1, int y1) {
   int  m_new = 2 * (y1-y0);
    int slope = m_new - (x1-x0);

    for(int x = x0, y= y0; x<= x1; x++) {
        pp(x,y);
        slope += m_new;

        if(slope >= 0) {
            y++;
            slope -= m_new;
        }else {
            y--;
            slope+= m_new;
        }

    }
}


void plotCirclePoints(int xc, int yc, int x, int y) {
    pp(xc+x,yc+y);
    pp(xc-x,yc+y);
    pp(xc+x,yc-y);
    pp(xc-x,yc-y);
    pp(xc+y,yc+x);
    pp(xc-y,yc+x);
    pp(xc+y,yc-x);
    pp(xc-y,yc-x);
}


void midPointCircle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int p = 1-r;

    plotCirclePoints(xc,yc,x,y);

    while(x<y) {
        x++;
        if(p<0) {
            p += 2*x + 1;
        }else {
            y--;
            p+= 2 * (x-y) + 1;
        }

        plotCirclePoints(xc,yc,x,y);
    }
}




// Driver program
int main()
{
	int gd = DETECT, gm;

	// Initialize graphics function
	initgraph(&gd, &gm, "");

	int maxx = getmaxx();
	int maxy = getmaxy();

	line(maxx/2,0,maxx/2, maxy);
	line(0,maxy/2,maxx,maxy/2);

    startX = maxx/2;
    startY = maxy/2;

	// Function call
	// bresenham(10,20,70,80);
	DDA(10,10,40,10);
	midPointCircle(10,40,5);

	getch();
	return 0;
}
