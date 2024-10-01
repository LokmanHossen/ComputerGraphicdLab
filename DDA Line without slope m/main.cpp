#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>

float x1, x2, y1, y2;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    float dy, dx, step, x, y, i, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy)) {
        step = abs(dx);
    }else
        step = abs(dy);

    Xin = dx / step;
    Yin = dy / step;
    x = x1;
    y = y1;

    glBegin(GL_POINTS);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2i(x, y);
    glEnd();

    for (i = 0; i < step; i++) {
        x += Xin;
        y += Yin;
        glBegin(GL_POINTS);
        glColor3f(1.0, 0.0, 0.0);
        glVertex2i(x, y);
        glEnd();
    }

  glFlush();
}

void myInit (void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 100, 0, 100);
    glPointSize(3);
}

int main(int argc, char ** argv) {

    printf("Value of x1 : ");
    scanf("%f", &x1);
    printf("Value of y1 : ");
    scanf("%f", &y1);
    printf("Value of x2 : ");
    scanf("%f", &x2);
    printf("Value of y2 : ");
    scanf("%f", &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("DDA Algorithm Without M");

    myInit ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
