#include "mygraphics.hpp"

vertex rotation_y(vertex P, float B){
    float z_ = P.z * cos(B * 3.1416/ 180) - P.x * sin( B * 3.1416/180 ) ;
    float x_ = P.z * sin(B * 3.1416/ 180) + P.x * cos( B * 3.1416/180 ) ;
    return vertex(x_,P.y,z_);
}
