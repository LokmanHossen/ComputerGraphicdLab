//Bressenham's Algorithm
#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

//Function to plot a point (for OpenGL)
void plotPoint(int x, int y){
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
}

//Bresenham's Line Algorithm
void bresenham(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;

    int x = x1;
    int y = y1;

    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;

    plotPoint(x, y);

    if (dx > dy) {
        while (x != x2) {
            x += sx;
            if (p < 0) {
                p += 2 * dy;
            } else {
                y += sy;
                p += 2 * (dy - dx);
            }
            plotPoint(x, y);
        }
    } else {
        while (y != y2) {
            y += sy;
            if (p < 0) {
                p += 2 * dx;
            } else {
                x += sx;
                p += 2 * (dx - dy);
            }
            plotPoint(x, y);
        }
    }
}

//Display callback for GLUT
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    int x1,y1,x2,y2;
    //Getting input from the user
    cout<<"Enter the starting point (x1, y1): ";
    cin>>x1>>y1;
    cout<<"Enter the ending point (x2, y2): ";
    cin>>x2>>y2;
    bresenham(x1,y1,x2,y2);
    glFlush();
}
//Initialize OpenGL
void init()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(3.0);
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
    glPointSize(2.0);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600,400);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Bresenham's Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
