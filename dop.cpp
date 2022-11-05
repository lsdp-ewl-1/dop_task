#include <iostream>
#include <GL/glut.h>
#include <stdlib.h>
//using namespace std;



int count = 0;

// размер окна
int w = 500;
int h = 500;

// координаты курсора в окне
int cx = 320;
int cy = 240;

// границы окна OpenGL


// переводим координаты окна в координаты окна OpenGL
/*double u = double(cx) / w * (x1 - x0) + x0;
double v = double(cy) / h * (y1 - y0) + y0;*/

void draw() {
	int coord_x = 0.5;
	int coord_y = 0.5;
	glPointSize(10.0);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glColor3d(255, 255, 255);
	glVertex2f(coord_x,coord_y);
	glEnd();
	//glutPostRedisplay();

}

void mouse(int button, int state, int x, int y)
{
	int x0 = -1;
	int y0 = 1;
	int x1 = 1;
	int y1 = -1;

	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN) && (count<10) )
	{
		//coord_x = x;
		//coord_y = y;

		double coord_x = double(x) / w * (x1 - x0) + x0;
		double coord_y = double(y) / h * (y1 - y0) + y0;

		count++;
		
		std::cout << coord_x << " " << coord_y << "\n";
		//glutIdleFunc(draw);
		
	}
	//glutPostRedisplay();
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	draw();
	//if (coord_x > 0) {
		/*(10.0);
		glEnable(GL_POINT_SMOOTH);
		glBegin(GL_POINTS);
		glColor3d(0, 255, 0);
		glVertex2f(coord_x, coord_y);
		glEnd();*/
	//}
	//display();
	glPopMatrix();
	glutSwapBuffers();
}
void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

/*void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}*/
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	//glutReshapeFunc(reshape);
	glutMouseFunc(mouse);
	glutMainLoop();
	return 0;   /* ANSI C requires main to return int. */


}
