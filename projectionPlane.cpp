#include "mygraphics.hpp"



float qdx, qdy, qdz, zp;

void setCOP(float cop_x, float cop_y, float cop_z,float z_p){
    qdx = cop_x;
    qdy = cop_y;
    qdz = cop_z - z_p;
    zp = z_p;
}

vertex project(vertex P){
    float x_, y_, z_;
    float x,y,z;
    x = P.x; y = P.y; z = P.z;
    x_ = ( x - z * (qdx/qdz) + zp * (qdx/qdz)) / ( - (z/qdz) + 1 + (zp/qdz)) ;
    y_ = ( y - z * (qdy/qdz) + zp * (qdy/qdz)) / ( - (z/qdz) + 1 + (zp/qdz)) ;
    z_ = zp;
    vertex P_(x_,y_,z_);

    return P_;
}
