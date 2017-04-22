#include "mygraphics.hpp"
int degree = 0;
void display(void)
{
    glOrtho (-320,319,-240,239,-1,1);

    setCOP(0,0,800,400);

    double a = 40;

    int surface[6][4] = {   { 0 , 1 , 5 , 4 },
                            { 2 , 3 , 7 , 6 },
                            { 0 , 1 , 2 , 3 },
                            { 4 , 5 , 6 , 7 },
                            { 1 , 2 , 6 , 5 },
                            { 0 , 3 , 7 , 4 } };

    vertex *P[8];
    P[0] = new vertex(a,a,-a);
    P[1] = new vertex(a,a,a);
    P[2] = new vertex(-a,a,a);
    P[3] = new vertex(-a,a,-a);
    P[4] = new vertex(a,-a,-a);
    P[5] = new vertex(a,-a,a);
    P[6] = new vertex(-a,-a,a);
    P[7] = new vertex(-a,-a,-a);
    for( ; ; degree++){

    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    shade(*P[1], *P[2], *P[6], *P[5], vertex(0,0,a));
    shade(*P[0], *P[1], *P[5], *P[4], vertex(a,0,0));
    shade(*P[2], *P[3], *P[7], *P[6], vertex(-a,0,0));
    shade(*P[1], *P[0], *P[3], *P[2], vertex(0,a,0));
    shade(*P[4], *P[5], *P[6], *P[7], vertex(0,-a,0));
    shade(*P[3], *P[0], *P[4], *P[7], vertex(0,0,-a));
    getchar();
    }
    /*int degree = 0;
    for( ;  ; degree = (degree + 1 ) % 360){
        getchar();
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        for(int i = 0 ; i < 6; i++){

            glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0);
            for(int j = 0 ; j < 4 ; j++){
                vertex temp_p = project(rotation_y(*P[surface[i][j]],degree));
                glVertex2i(temp_p.x, temp_p.y);
            }

            glEnd();

        }
        glFlush();
    }*/


}

void shade(vertex A, vertex B, vertex C, vertex D,vertex G){
    vertex L(0,0,800);
    A = rotation_y(A,degree);
    B = rotation_y(B,degree);
    C = rotation_y(C,degree);
    D = rotation_y(D,degree);

    vertex normal_temp = normal(A, B, C);
    //normal_temp.x /= 1.41* a; normal_temp.y /= 1.41* a; normal_temp.z /= 1.41* a;
    double normal_temp_mag = vector_mag(normal_temp);

    normal_temp.x /= normal_temp_mag;
    normal_temp.y /= normal_temp_mag;
    normal_temp.z /= normal_temp_mag;

    printf("%lf %lf %lf\n", normal_temp.x, normal_temp.y, normal_temp.z );

    L = L - G;
    double L_mag = vector_mag(L);
    L.x /= L_mag;
    L.y /= L_mag;
    L.z /= L_mag;

    double intensity = vectorDot(normal_temp,L);
    printf("%lf\n", intensity);
    if(intensity < 0 ) return ;

    glBegin(GL_QUADS);
    glColor3f(intensity,intensity,intensity);
    vertex temp_p = project(A);
    glVertex2i(temp_p.x, temp_p.y);

    temp_p = project(B);
    glVertex2i(temp_p.x, temp_p.y);

    temp_p = project(C);
    glVertex2i(temp_p.x, temp_p.y);

    temp_p = project(D);
    glVertex2i(temp_p.x, temp_p.y);

    glEnd();

    glFlush();
}

vertex normal(vertex A, vertex B , vertex C){
    vertex X = A - B;
    vertex Y = B - C;
    return vectorCross(X,Y);
}
