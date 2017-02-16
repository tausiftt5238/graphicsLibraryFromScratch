#include "mygraphics.hpp"

void display(void)
{
    glOrtho (-320,319,-240,239,-1,1);

    int i = 0;
    while(i--){
        int x0 = rand() % 640 - 320;
        int y0 = rand() % 480 - 240;
        int x1 = rand() % 640 - 320;
        int y1 = rand() % 480 - 240;
        printf("(%d %d) (%d %d)\n", x0, y0, x1, y1);
        //draw_line_8_seg(x0,y0,x1,y1);
        //lineClip(x0,y0,x1,y1);
        //line_clip_cyrus(x0,y0,x1,y1);
        midPointCircle(x0,y0, 100,0);
        //midPointCircle(x1, y1, 50,2);

    }
    while(false){
        for( ; i < 100; i++){
        midPointCircle(0, i, 10, 4);
        glFlush();
        usleep(10000);
        midPointCircle(0,i,10,8);
        glFlush();
        }
        for( ; i >= 0 ; i--){
            midPointCircle(0, i, 10, 4);
            glFlush();
            usleep(10000);
            midPointCircle(0,i,10,8);
            glFlush();
        }
    }
    while(true){
        int limit = 360;
        int interval = 90;
        int stopThis = interval;
        for(int i = 0, j = 0 ; i <= limit; i++,stopThis--){

            midPointCircle(50*cos(i / 180.0 * 3.1416), 50*sin(i / 180.0 * 3.1416), 10, 4);
            glFlush();
            usleep(1000);
            if(!stopThis){
                for(; j < i ; j++){
                    //midPointCircle(50*cos(i), 50*sin(i), 10, 4);
                    //glFlush();
                    usleep(1000);
                    midPointCircle(50*cos(j / 180.0 * 3.1416), 50*sin(j / 180.0 * 3.1416), 10, 8);
                    glFlush();
                }
                stopThis = interval;
            }

        }

    }


    //line_clip_cyrus(-50,-215,300,215);
	glFlush();
}

