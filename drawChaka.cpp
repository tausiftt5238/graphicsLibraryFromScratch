#include "mygraphics.hpp"
#define PI 3.1415


void drawChaka(int x, int y){
    int innerR = 15;
    int outerR = 20;
    float dist = 0;
    while(true)
    for(int offset = 0; offset < 360; offset++){
        float x0 = innerR, y0 = y;
        midPointCircle(x + dist ,y,outerR,1);
        midPointCircle(x + dist,y,innerR,2);
        glFlush();
        setAcceptanceStatus(4);
        for(int i = 0 ; i < 4 ; i++){
            int x1 = x0*cos(-(i*PI/4 + (offset*PI/180))) - y0*sin(-(i*PI/4+ (offset*PI/180)))+ dist + x;
            int y1 = x0*sin(-(i*PI/4+ (offset*PI/180))) + y0*cos(-(i*PI/4+ (offset*PI/180)));
            int x2 = x0*cos(-((i+4)*PI/4 + (offset*PI/180))) - y0*sin(-((i+4)*PI/4 + (offset*PI/180))) + dist + x;
            int y2 = x0*sin(-((i+4)*PI/4 + (offset*PI/180))) + y0*cos(-((i+4)*PI/4 + (offset*PI/180)));
            draw_line_8_seg(x1,y1,x2,y2);
        }
        usleep(1000);
        glFlush();
        setAcceptanceStatus(8);
        for(int i = 0 ; i < 4 ; i++){
            int x1 = x0*cos(-(i*PI/4 + (offset*PI/180))) - y0*sin(-(i*PI/4+ (offset*PI/180)))+ dist + x;
            int y1 = x0*sin(-(i*PI/4+ (offset*PI/180))) + y0*cos(-(i*PI/4+ (offset*PI/180)));
            int x2 = x0*cos(-((i+4)*PI/4 + (offset*PI/180))) - y0*sin(-((i+4)*PI/4 + (offset*PI/180))) + dist + x;
            int y2 = x0*sin(-((i+4)*PI/4 + (offset*PI/180))) + y0*cos(-((i+4)*PI/4 + (offset*PI/180)));
            draw_line_8_seg(x1,y1,x2,y2);
        }
        usleep(1000);
        glFlush();
        midPointCircle(x + dist ,y,outerR,8);
        midPointCircle(x + dist,y,innerR,8);
        glFlush();
        dist += (2* PI * innerR ) / 360;
    }
}

