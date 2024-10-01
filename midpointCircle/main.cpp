#include <GL/glut.h>
#include <iostream>

using namespace std;

int xc, yc, r;

void plot(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(xc + x, yc + y); // Plot (xc + x, yc + y)
    glVertex2i(xc - x, yc + y); // Plot (xc - x, yc + y)
    glVertex2i(xc + x, yc - y); // Plot (xc + x, yc - y)
    glVertex2i(xc - x, yc - y); // Plot (xc - x, yc - y)
    glVertex2i(xc + y, yc + x); // Plot (xc + y, yc + x)
    glVertex2i(xc - y, yc + x); // Plot (xc - y, yc + x)
    glVertex2i(xc + y, yc - x); // Plot (xc + y, yc - x)
    glVertex2i(xc - y, yc - x); // Plot (xc - y, yc - x)
    glEnd();
}

void midpointCircle() {
    int x = 0;
    int y = r;
    int p = 1 - r; // Initial point

    plot(x, y); // Plot initial points
    while (x <= y) {
        x++;
        if (p < 0) {
            p += 2 * x + 1;
        } else {
            y--;
            p += 2 * (x - y) + 1;
        }
        plot(x, y); // Plot points after each calculation
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    midpointCircle();
    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set background color to white
    glColor3f(0.0, 0.0, 0.0);         // Set drawing color to black
    glPointSize(3.0);                 // Set point size
    gluOrtho2D(0, 100, 0, 100);       // Set coordinate system
}

int main(int argc, char** argv) {
    cout << "Enter the center of the circle (xc, yc): ";
    cin >> xc >> yc;
    cout << "Enter the radius of the circle: ";
    cin >> r;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Midpoint Circle Drawing Algorithm");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
