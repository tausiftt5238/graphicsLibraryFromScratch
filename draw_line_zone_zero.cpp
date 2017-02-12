#include "mygraphics.hpp"

//basically whatever sir wrote on the board :v it works XD
void drawLine(int x0, int y0 , int x1 , int y1){
    printf("%d %d %d %d\n",x0,y0,x1,y1);
    int dy = y1 - y0;
    int dx = x1 - x0;
    int dint = 2 * dy - dx;
    int dE = 2 * dy;
    int dNE = 2* (dy - dx);

    int x = x0, y = y0;
    drawPixel(x,y);

    while(x <= x1){
        if(dint < 0){
            x++;
            dint += dE;
        }else{
            x++;
            y++;
            dint += dNE;
        }
        drawPixel(x,y);
    }
}

