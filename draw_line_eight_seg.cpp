#include "mygraphics.hpp"

void draw_line_vertex(vertex P, vertex Q){
    draw_line_8_seg(P.x,P.y, Q.x, Q.y);
}

void draw_line_8_seg(int x0, int y0, int x1, int y1){
    switch(zone(x0,y0,x1,y1)){
        case 0:
        printf("zone 0\n");
        setZone(0);
        drawLine(x0,y0,x1,y1);
        break;
        case 1:
        printf("zone 1\n");
        setZone(1);
        drawLine(y0,x0,y1,x1);
        break;
        case 2:
        printf("zone 2\n");
        setZone(2);
        drawLine(y0,-x0,y1,-x1);
        break;
        case 3:
        printf("zone 3\n");
        setZone(3);
        drawLine(-x0,y0,-x1,y1);
        break;
        case 4:
        printf("zone 4\n");
        setZone(4);
        drawLine(-x0,-y0,-x1,-y1);
        break;
        case 5:
        printf("zone 5\n");
        setZone(5);
        drawLine(-y0,-x0,-y1,-x1);
        break;
        case 6:
        printf("zone 6\n");
        setZone(6);
        drawLine(-y0,x0,-y1,x1);
        break;
        case 7:
        printf("zone 7\n");
        setZone(7);
        drawLine(x0,-y0,x1,-y1);
        break;
        default:
        break;
    }

}
