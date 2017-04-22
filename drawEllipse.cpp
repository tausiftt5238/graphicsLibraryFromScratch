#include "mygraphics.hpp"
void drawEllipse(int offx,int offy,int a,int b,int color) {
	int dE,dSE,dS;
	int dinit = 4*b*b - 4*a*a*b + a*a;
	int x=0,y=b,i;
	while(a*a*(y-.5) > b*b*(x+1.0)) {
		dE = 4*b*b*(2*x+3);
		dSE = 4*(b*b*(2*x+3) + a*a*(-2*y+2));
		if(dinit<0) {
			dinit += dE;
			x++;
		}
		else {
			dinit += dSE;
			x++; y--;
		}
		ellipsePoints(x,y,offx,offy,color);
		ellipsePoints(-x,y,offx,offy,color);
		ellipsePoints(x,-y,offx,offy,color);
		ellipsePoints(-x,-y,offx,offy,color);
	}
	dinit = 4*b*b*x*x + 4*b*b*x + b*b + 4*a*a*y*y - 8*a*a*y + 4*a*a - 4*a*a*b*b;
	while(y>=0) {
		dS = 4*a*a*(-2*y + 3);
		dSE = 4*(b*b*(2*x+2) + a*a*(-2*y +3));
		if(dinit>=0) {
			dinit += dS;
			y--;
		}
		else {
			dinit += dSE;
			x++; y--;
		}
		ellipsePoints(x,y,offx,offy,color);
		ellipsePoints(-x,y,offx,offy,color);
		ellipsePoints(x,-y,offx,offy,color);
		ellipsePoints(-x,-y,offx,offy,color);
	}
}

void ellipsePoints(int x, int y ,int offsetX, int offsetY, int color){
    setAcceptanceStatus(color);
    glBegin(GL_POINTS);
        switch(getAcceptanceStatus()){
            case 0:
            glColor3f(0.5,0.5,0.5);
            break;
            case 1:
            glColor3f(0.0,0.0,1.0);
            break;
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
            break;
            case 6:
            glColor3f(1.0,1.0,0.0);
            break;
            case 7:
            glColor3f(1.0,1.0,1.0);
            break;
            default:
            glColor3f(0.0,0.0,0.0);
        }
        glVertex2i(x+offsetX,y+offsetY);
        glVertex2i(-x+offsetX,y+offsetY);
        glVertex2i(-x+offsetX,-y+offsetY);
        glVertex2i(x+offsetX,-y+offsetY);
        glFlush();
	glEnd();
}

