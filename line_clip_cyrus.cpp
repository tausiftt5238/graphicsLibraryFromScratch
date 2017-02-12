#include "mygraphics.hpp"

void line_clip_cyrus(int x0, int y0, int x1, int y1){
    double tl = 1, te = 0, t;
    if(x0 == x1 || y0 == y1) return;
    //setAcceptanceStatus(2);
    //draw_line_8_seg(x0,y0,x1,y1);
    setAcceptanceStatus(0);

    t = ((double)y0 - (double)getymax())/(-((double)y1- (double)y0));
    if(y1 > y0){
        if(t < tl){
            tl = t;
        }
    }
    else
        if(t > te){
            te = t;
        }

    t = ((double)y0 - (double)getymin())/(-((double)y1 - (double)y0));
    if(y1 < y0){
        if(t < tl){
            tl = t;
        }
    }
    else
        if(t > te){
            te = t;
        }

    t = ((double)x0 - (double)getxmin())/(-((double)x1 - (double)x0));
    if(x1 < x0){
        if(t < tl){
            tl = t;
        }

    }
    else
        if(t > te){
            te = t;
        }

    t = ((double)x0 - (double)getxmax())/(-((double)x1 - (double)x0));
    if(x1 > x0){
        if(t < tl){
            tl = t;
        }

    }
    else
        if(t > te){
            te = t;
        }
    printf("%lf %lf\n", te,tl);
    if(te < tl){
        //printf("here\n");
        double x_0,y_0,x_1,y_1;
        x_0 = x0 + te*(x1-x0); y_0 = y0 + te*(y1-y0);
        x_1 = x0 + tl*(x1-x0); y_1 = y0 + tl*(y1-y0);
        printf("x0 : %d y0 : %d x1: %d y1 : %d\n",x_0,y_0,x_1,y_1);
        setAcceptanceStatus(2);
        draw_line_8_seg(x0,y0,x_0,y_0);
        setAcceptanceStatus(0);
        draw_line_8_seg((int)x_0,(int)y_0,(int)x_1,(int)y_1);
        setAcceptanceStatus(2);
        draw_line_8_seg(x1,y1,x_1,y_1);
    }
}
