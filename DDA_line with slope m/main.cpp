#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void drawDDALine(int x1, int y1, int x2, int y2) {
    // Calculate differences
    int dx = x2 - x1;
    int dy = y2 - y1;

    // Calculate slope m
    float m = (float)dy / (float)dx;
    cout << "Slope (m) : " << m << endl;

    // Determine the number of steps and increments
    int steps;
    float xInc, yInc;

    if (abs(dx) > abs(dy)) {
        // Case: |dx| > |dy|, i.e., gentle slope (|m| <= 1)
        steps = abs(dx);
        xInc = (dx > 0 ? 1 : -1);  // Increment in x direction
        yInc = m * xInc;           // Corresponding increment in y
    } else {
        // Case: |dy| > |dx|, i.e., steep slope (|m| > 1)
        steps = abs(dy);
        yInc = (dy > 0 ? 1 : -1);  // Increment in y direction
        xInc = (1 / m) * yInc;     // Corresponding increment in x
    }

    // Print steps, xInc, yInc
    cout << "Steps: " << steps << endl;
    cout << "xInc: " << xInc << endl;
    cout << "yInc: " << yInc << endl;

    // Starting points
    float x = x1;
    float y = y1;

    cout << "STEPS\t\tx\t\ty" << endl;

    for (int i = 0; i <= steps; i++) {
        setPixel(round(x), round(y));  // Use round to place pixel at integer coordinates
        cout << i << "\t\t" << x << "\t\t" << y << endl;
        x += xInc;
        y += yInc;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Set line color to red
    glColor3f(1.0, 0.0, 0.0);

    // Coordinates of the line
    int x1, y1, x2, y2;
    cout << "Enter x1 , y1 : ";
    cin >> x1 >> y1;
    cout << "Enter x2 , y2 : ";
    cin >> x2 >> y2;

    // Draw the line using DDA
    drawDDALine(x1, y1, x2, y2);

    glFlush();
}

void init() {
    // Set background color to black
    glClearColor(0.0, 0.0, 0.0, 0.0);

    // Set the projection matrix to a 2D orthographic projection
    gluOrtho2D(0.0, 100.0, 0.0, 100.0);

    // Set the pixel size
    glPointSize(3.0);
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm with slope (m)");

    // Initialize OpenGL
    init();

    // Register Display callback function
    glutDisplayFunc(display);

    // Enter the GLUT main loop
    glutMainLoop();

    return 0;
}
