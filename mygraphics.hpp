#include<GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

//int acceptance;


class vertex{
public:
    float x;
    float y;
    float z;

    vertex(float xx, float yy, float zz){
        x = xx;
        y = yy;
        z = zz;
    }
    vertex operator- ( vertex &A){
        vertex C(this->x - A.x, this->y - A.y, this->z - A.z);
        return C;
    }
    vertex operator+ ( vertex &A){
        vertex C(this->x + A.x, this->y + A.y, this->z + A.z);
        return C;
    }
};

void display(void);
int zone(int x0,int y0,int x1, int y1);
void drawLine(int x0, int y0 , int x1 , int y1);
void drawPixel(int x, int y );
int getxmax();
int getxmin();
int getymax();
int getymin();
int getZone();
void setZone(int i);
void draw_line_8_seg(int x0, int y0, int x1, int y1);
void lineClip(int x0,int y0, int x1, int y1);
int getAcceptanceStatus();
void setAcceptanceStatus(int a);
void line_clip_cyrus(int x0, int y0, int x1, int y1);
void midPointCircle(int x,int y,int radius, int color);
void circlePoints(int x, int y ,int offsetX, int offsetY, int color);
void drawChaka(int x, int y);
void drawEllipse(int offx,int offy,int a,int b,int color);
void ellipsePoints(int x, int y ,int offsetX, int offsetY, int color);
void ballBounce();
void myDrawCircleAnti(int a,int b,int R);
void setCOP(float cop_x, float cop_y, float cop_z,float z_p);
struct vertex project(struct vertex P);
void draw_line_vertex(vertex P, vertex Q);
vertex rotation_y(vertex P, float B);
void boxrotation();
vertex vectorCross(vertex A, vertex B);
double vectorDot(vertex A, vertex B);
vertex normal(vertex A, vertex B , vertex C);
double vector_mag(vertex A);
void shade(vertex A, vertex B, vertex C,vertex D, vertex G);

