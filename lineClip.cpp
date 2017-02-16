#include "mygraphics.hpp"
#define UP 8
#define DOWN 4
#define RIGHT 2
#define LEFT 1

int makeCode(int x,int y){
    int ret = 0;
    if(x > getxmax()) ret += RIGHT;
    else if(x < getxmin()) ret += LEFT;
    if(y > getymax()) ret += UP;
    else if(y < getymin()) ret += DOWN;
    return ret;
}

void lineClip(int x0,int y0, int x1, int y1){
    int x,y;
    int code, code0, code1;
    code0 = makeCode(x0,y0);
    code1 = makeCode(x1,y1);
    while(true){
        if((code0 | code1) == 0){
            setAcceptanceStatus(0);
            draw_line_8_seg(x0,y0,x1,y1);
            return;
        }
        if(code0 & code1){
            setAcceptanceStatus(2);
            return;
        }
        setAcceptanceStatus(1);
        if(code0) code = code0;
        else code = code1;
        if(code & UP){
            y = getymax();
            x = x0 + ((y - y0)/(y1 - y0))*(x1 - x0);
        }
        else if(code & DOWN){
            y = getymin();
            x = x0 + ((y - y0)/(y1 - y0))*(x1 - x0);
        }
        else if(code & RIGHT){
            x = getxmax();
            y = y0 + ((x - x0) / (x1 - x0)) * (y1- y0);

        }
        else{
            x = getxmin();
            y = y0 + ((x - x0) / (x1 - x0)) * (y1- y0);
        }
        if(code == code0){
            x0 = x, y0 = y, code0 = makeCode(x0,y0);
        }
        else{
            x1 = x, y1 = y, code1 = makeCode(x1,y1);
        }

    }
}
