#include<stdio.h>
#include<math.h>
#include<graphics.h>

void midPointCircle(int x_center,int y_center, int r) {
    int x = r;
    int y = 0;

    putpixel(x + x_center, y + y_center, GREEN);

    if(r>0) {
        putpixel(x+x_center, -y+ y_center, BLUE);
        putpixel(y+x_center, x+ y_center, BLUE);
        putpixel(-y+x_center, x+ y_center, BLUE);
    }

    int P = 1-r;

    while(x>y) {
        y++;

        if(P <= 0){ P = P + 2*y +1;}
        else {
            x--;
            P = P + 2*y - 2*x + 1;
        }

        if(x<y) break;

        putpixel(x+x_center, y+ y_center, RED);
        putpixel(-x+x_center, y+y_center, RED);
        putpixel(x+x_center, -y+ y_center,RED);
        putpixel(-x+x_center, -y+y_center, RED);

        if(x!= y) {
            putpixel(y+x_center, x+ y_center,RED);
            putpixel(-y+x_center, x+y_center,RED);
            putpixel(y+x_center, -x+ y_center,RED);
            putpixel(-y+x_center, -x+y_center,RED);
        }

    }
}

int main () {

    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    midPointCircle(150,150,100);

    delay(100000);

    return 0;
}
