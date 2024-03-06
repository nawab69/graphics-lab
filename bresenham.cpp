#include<graphics.h>
#include<stdio.h>
#include<math.h>


void bresenham(int x1, int y1, int x2, int y2) {
    int m_new = 2 * (y2-y1);
    int slope = m_new - (x2-x1);

    for(int x= x1, y= y1; x<=x2; x++) {
        putpixel(x,y,RED);
        slope+= m_new;

        if(slope>= 0) {
            y++;
            slope -= 2 * (y2-y1);
        }
    }
}




int main() {

    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    int x0 = 2;
    int y0 = 4;
    int x1 = 20;
    int y1 = 25;

    bresenham(x0,y0,x1,y1);

    delay(10000);


    return 0;
}
