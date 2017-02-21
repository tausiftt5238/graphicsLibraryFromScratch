#include "mygraphics.hpp"

void display(void)
{
    glOrtho (-320,319,-240,239,-1,1);

    drawChaka(-50,0);

    glFlush();
}

