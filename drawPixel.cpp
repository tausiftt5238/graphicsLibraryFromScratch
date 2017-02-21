#include "mygraphics.hpp"

//the drawing pixel function he asked for
void drawPixel(int x, int y ){
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
        switch(getZone()){

            case 0:
            glVertex2i(x,y);
            break;
            case 1:
            glVertex2i(y,x);
            break;
            case 2:
            glVertex2i(-y,x);
            break;
            case 3:
            glVertex2i(-x,y);
            break;
            case 4:
            glVertex2i(-x,-y);
            break;
            case 5:
            glVertex2i(-y,-x);
            break;
            case 6:
            glVertex2i(y,-x);
            break;
            case 7:
            glVertex2i(x,-y);
            break;
        }
	glEnd();
}
