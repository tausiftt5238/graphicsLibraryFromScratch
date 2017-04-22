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
        glFlush();
    }
}

void myDrawCircleAnti(int a,int b,int R) {
	int x=R,y=0;
	int dN, dNW,temp;
	int dinit = -4*R + 5;
	int i;
	circlePoints(x,y,a,b,5);
	while(x>y) {
		dN = 4*(2*y + 3);
		dNW = 4*(2*y - 2*x + 5);
		if(dinit>=0) {
			//going diagonal
			dinit += dNW;
			x--; y++;
		}
		else {
			dinit += dN;
			y++;
		}
		circlePoints(x,y,a,b,5);
        glFlush();
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
        glVertex2i(y+offsetX,x+offsetY);
        glVertex2i(-y+offsetX,x+offsetY);
        glVertex2i(-x+offsetX,y+offsetY);
        glVertex2i(-x+offsetX,-y+offsetY);
        glVertex2i(-y+offsetX,-x+offsetY);
        glVertex2i(y+offsetX,-x+offsetY);
        glVertex2i(x+offsetX,-y+offsetY);

	glEnd();
}
