#include "mygraphics.hpp"

int drawZone;

int getZone(){
    return drawZone;
}
void setZone(int i){
    drawZone = i;
}

int zone(int x0, int y0 , int x1 , int y1){
    int dx = x1 - x0;
    int dy = y1 - y0;

    if(abs(dx) >= abs(dy)&& (dx >= 0 && dy >= 0)){
        return 0;
    }
    else if(abs(dy) >= abs(dx) && (dx >= 0 && dy >= 0)){
        return 1;
    }
    else if(abs(dy) >= abs(dx) && (dx <= 0 && dy >= 0)){
        return 2;
    }
    else if(abs(dx) >= abs(dy) && (dx <= 0 && dy >= 0)){
        return 3;
    }
    else if(abs(dx) >= abs(dy) && (dx <= 0 && dy <= 0)){
        return 4;
    }
    else if(abs(dy) >= abs(dx) && (dx <= 0 && dy <= 0)){
        return 5;
    }
    else if(abs(dy) >= abs(dx) && (dx >= 0 && dy <= 0)){
        return 6;
    }
    else if(abs(dx) >= abs(dy) && (dx >= 0 && dy <= 0)){
        return 7;
    }
    return 8;
}
