#include "mygraphics.hpp"

vertex vectorCross(vertex A, vertex B){
    double x = A.y*B.z - A.z*B.y;
    double y = A.x*B.z - A.z*B.x;
    double z = A.x*B.y - A.y*B.x;
    return vertex(x,-y,z);
}

double vectorDot(vertex A, vertex B){
    return (A.x*B.x) + (A.y*B.y) + (A.z*B.z);
}

double vector_mag(vertex A){
    return sqrt( A.x * A.x + A.y * A.y+ A.z * A.z );
}
