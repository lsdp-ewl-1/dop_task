#include <gl/glut.h>
#include <iostream>

class Point
{
    int Xvalue, Yvalue;
public:
    void xy(int x, int y)
    {
        Xvalue = x;
        Yvalue = y;
    }

    //return individual x y value
    int x() { return Xvalue; }
    int y() { return Yvalue; }
};

Point point[10];
int count = 0;
int checkRight = 0;

void Display()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT); // clear display window

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    const double w = glutGet(GLUT_WINDOW_WIDTH);
    const double h = glutGet(GLUT_WINDOW_HEIGHT);
    gluOrtho2D(0.0, w, 0.0, h);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(1.0, 1.0, 1.0);

    glPointSize(5.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < count; i++)
    {
        int x = point[i].x();
        int y = point[i].y();

        glColor3f(0, 0, 0);
        glVertex2i(x, h - y);

    }
    glEnd();

    glColor3d(0, 1, 0);
    glBegin(GL_POLYGON);
    if (checkRight == 1) {
        for (int i = 0; i < count; i++) {    
            glVertex3d(point[i].x(), h - point[i].y(), 0);

        }     
    }
    glEnd();

    glFlush();
}



void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && count<10 && checkRight == 0)
    {
        point[count].xy(x, y);
        count++;
    }
    else if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && count >= 3) {
        checkRight = 1;
    }
    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Create Polygon");

    glutMouseFunc(mouse);
    glutDisplayFunc(Display);

    glutMainLoop();
    return 0;
}