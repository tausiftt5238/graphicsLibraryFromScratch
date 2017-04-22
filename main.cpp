#include "mygraphics.hpp"


void Init(void ){
    glClearColor(0,1,0,0.0);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
	//to make it 2D and putting the origin in the middle of the screen
	//glOrtho (-320,319,-240,239,-1,1);

    //draw lines to create axis

	glBegin(GL_LINES);

		glColor3f(1.0,1.0,1.0);
		glVertex2i(-320,0);
		glVertex2i(319,0);
		glVertex2i(0,239);
		glVertex2i(0,-240);

		glVertex2i(getxmin(), getymax());
		glVertex2i(getxmax(), getymax());

		glVertex2i(getxmax(), getymax());
		glVertex2i(getxmax(), getymin());

		glVertex2i(getxmax(), getymin());
		glVertex2i(getxmin(), getymin());

		glVertex2i(getxmin(), getymin());
		glVertex2i(getxmin(), getymax());

	glEnd();

}
void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	//assigning window size
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(200, 200);
	//creating the display here
	glutCreateWindow("Simple GLUT point test");

	glClear(GL_COLOR_BUFFER_BIT);

	Init();

    //call drawing function here
    glutReshapeFunc(Reshape);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
