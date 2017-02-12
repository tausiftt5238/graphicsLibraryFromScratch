#include "mygraphics.hpp"
void display(void)
{
    glOrtho (-320,319,-240,239,-1,1);

    int i = 100;
    while(i--){
        int x0 = rand() % 640 - 320;
        int y0 = rand() % 480 - 240;
        int x1 = rand() % 640 - 320;
        int y1 = rand() % 480 - 240;
        printf("(%d %d) (%d %d)\n", x0, y0, x1, y1);
        //draw_line_8_seg(x0,y0,x1,y1);
        //lineClip(x0,y0,x1,y1);
        line_clip_cyrus(x0,y0,x1,y1);

    }
    //line_clip_cyrus(-50,-215,300,215);
	glFlush();
}

