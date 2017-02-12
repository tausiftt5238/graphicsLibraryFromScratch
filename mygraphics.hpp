#include<GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

//int acceptance;

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
