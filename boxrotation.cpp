#include "mygraphics.hpp"

void boxrotation(){
    setCOP(0,0,800,200);

    vertex *P[8];
    P[0] = new vertex(40,40,40);
    P[1] = new vertex(-40,40,40);
    P[2] = new vertex(-40,40,-40);
    P[3] = new vertex(40,40,-40);
    P[4] = new vertex(40,-40,40);
    P[5] = new vertex(-40,-40,40);
    P[6] = new vertex(-40,-40,-40);
    P[7] = new vertex(40,-40,-40);
    int degree = 0;

    for( ;  ; degree = (degree + 1 ) % 360){
        getchar();
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        setAcceptanceStatus(1);
        draw_line_vertex(project(rotation_y(*P[0],degree)), project(rotation_y(*P[1],degree)));
        draw_line_vertex(project(rotation_y(*P[0],degree)), project(rotation_y(*P[3],degree)));
        draw_line_vertex(project(rotation_y(*P[0],degree)), project(rotation_y(*P[4],degree)));

        setAcceptanceStatus(2);
        draw_line_vertex(project(rotation_y(*P[2],degree)), project(rotation_y(*P[1],degree)));
        draw_line_vertex(project(rotation_y(*P[2],degree)), project(rotation_y(*P[3],degree)));
        draw_line_vertex(project(rotation_y(*P[2],degree)), project(rotation_y(*P[6],degree)));

        setAcceptanceStatus(3);
        draw_line_vertex(project(rotation_y(*P[7],degree)), project(rotation_y(*P[3],degree)));
        draw_line_vertex(project(rotation_y(*P[7],degree)), project(rotation_y(*P[6],degree)));
        draw_line_vertex(project(rotation_y(*P[7],degree)), project(rotation_y(*P[4],degree)));

        setAcceptanceStatus(4);
        draw_line_vertex(project(rotation_y(*P[5],degree)), project(rotation_y(*P[1],degree)));
        draw_line_vertex(project(rotation_y(*P[5],degree)), project(rotation_y(*P[4],degree)));
        draw_line_vertex(project(rotation_y(*P[5],degree)), project(rotation_y(*P[6],degree)));
        glFlush();
    }

}
