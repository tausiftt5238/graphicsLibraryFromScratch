#include "mygraphics.hpp"
void midPointCircle(int x0, int y0,int radius, int color){
    int x = 0;
    int y = radius;
    int d = 1 - radius;
    int deltaE = 3;
    int deltaSE = -2 * radius + 5;
    circlePoints(x,y,x0,y0,color);
    //setZone(7);
    //drawPixel(x,y);
    while(y > x){
        if(d < 0 ){
            d += deltaE;
            deltaE += 2;
            deltaSE += 2;

        }else{
            d += deltaSE;
            deltaE += 2;
            deltaSE += 4;
            y--;

        }
        x++;
        //setZone(7);
        //drawPixel(x,y);
        circlePoints(x,y,x0,y0,color);
    }
}


void circlePoints(int x, int y ,int offsetX, int offsetY, int color){
    setAcceptanceStatus(color);
    glBegin(GL_POINTS);
        switch(getAcceptanceStatus()){
            case 0:
            glColor3f(0.5,0.5,0.5);
            break;
            case 1:
            glColor3f(0.0,0.0,1.0);
            case 2:
            glColor3f(0.0,1.0,0.0);
            break;
            case 3:
            glColor3f(0.0,1.0,1.0);
            break;
            case 4:
            glColor3f(1.0,0.0,0.0);
            break;
            case 5:
            glColor3f(1.0,0.0,1.0);
            case 6:
            glColor3f(1.0,1.0,0.0);
            break;
            case 7:
            glColor3f(1.0,1.0,1.0);
            default:
            glColor3f(0.0,0.0,0.0);
        }
        glVertex2i(x+offsetX,y+offsetY);
        glVertex2i(y+offsetX,x+offsetY);
        glVertex2i(-y+offsetX,x+offsetY);
        glVertex2i(-x+offsetX,y+offsetY);
        glVertex2i(-x+offsetX,-y+offsetY);
        glVertex2i(-y+offsetX,-x+offsetY);
        glVertex2i(y+offsetX,-x+offsetY);
        glVertex2i(x+offsetX,-y+offsetY);
        glFlush();
	glEnd();
}
