#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<conio.h>


#define pp(x,y) putpixel(x,y,RED)



void flood(int x, int y, int defaultColor) {
    if(getpixel(x,y) == defaultColor) {
       // delay(1);
        pp(x,y);
        flood(x+1,y, defaultColor);
        flood(x-1,y, defaultColor);
        flood(x,y+1, defaultColor);
        flood(x,y+1, defaultColor);



    }
}


int main () {

    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

   rectangle(50,50,250,250);


    flood(55,55,0);



    delay(100000);

    return 0;
}
