#include "mygraphics.hpp"
void ballBounce(){

    double a = 20;
        double b = 20;
        int i = 200;
        int t = 1;
        int limit = 1;
        int fallSpeed = 10000;
        int squeezeSpeed = 30000;
        while(limit < 6){
            for(int k = 0; i >= -200; i -= t){
                if(i > 175) t = 1;
                else if(i > 150) t = 2;
                else if(i > 100) t = 3;
                else if(i > -10) t = 4;
                else t = 5;
                glClear(GL_COLOR_BUFFER_BIT);
                if(i <= -190 && i >= -200){
                    //i += t;
                    if(k >= (5-limit)*5) continue;
                    drawEllipse(0,i-k,a+(k*a*5.0/100.0),b-(k*b*5.0/100.0),4);
                    usleep(squeezeSpeed);
                    glFlush();
                    k+=5;
                    //i--;
                }
                else{
                    drawEllipse(0,i,a,b,4);
                    usleep(fallSpeed);
                    glFlush();
                }
            }

            for(int k = 10; i < 200; i += t){
                if(i > 175) t = 1;
                else if(i > 150) t = 2;
                else if(i > 100) t = 3;
                else if(i > -10) t = 4;
                else t = 5;
                if(limit >= t) break;
                glClear(GL_COLOR_BUFFER_BIT);
                if(i <= -190 && i >= -200){
                    //i -= t;
                    if(k >= (5-limit)*5) continue;
                    drawEllipse(0,i-k,a+(k*a*5.0/100.0),b-(k*b*5.0/100.0),4);
                    usleep(squeezeSpeed);
                    glFlush();
                    //i++;
                    k-=5;
                }
                else{
                    drawEllipse(0,i,a,b,4);
                    usleep(fallSpeed);
                    glFlush();
                }
            }
            limit++;
        }
}
