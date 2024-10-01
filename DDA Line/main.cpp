#include <GL/gl.h>
#include<stdio.h>
#include <GL/glut.h>

float x1,y1,x2,y2,m,i,j;
int dx=0,dy=0;
void display(void){

/* clear all pixels */
glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
*	(0.25, 0.25, 0.0) and (0.75, 0.75, 0.0) */
    glColor3f (0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    if(dx==1){
    for(i=x1,j=y1;i<=x2,j<=y2;i=i+1,j=j+m){
    glVertex3f ((i/100), (j/100), 0.0);
    }
}
    else if(dy==1){
    for(i=x1,j=y1;i<=x2,j<=y2;i=(i+(1/m)),j=j+1){
    glVertex3f ((i/100), (j/100), 0.0);
    glVertex3f ((i/100), (j/100), 0.0);
    }
  }
    glEnd();
    glFlush ();
}
    void init (void){
    glClearColor (0.0, 0.0, 0.0, 0.0);         /* select clearing (background) color */
    glMatrixMode(GL_PROJECTION); glLoadIdentity();      /* initialize viewing values */
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    }

int main(int argc, char** argv){
  printf("Value of x1 : ");
  scanf("%f", & x1);
  printf("Value of y1 : ");
  scanf("%f", & y1);
  printf("Value of x2 : ");
  scanf("%f", & x2);
  printf("Value of y2 : ");
  scanf("%f", & y2);

        m=(y2-y1)/(x2-x1);
        if((x1>x2)&&(y1>y2)){
        dx=-1;
        }
        else{
        dx=1;
     }
        glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize (500, 500);
        glutInitWindowPosition (100, 100);
        glutCreateWindow ("DDA Line algorithm");

        init ();
        glutDisplayFunc(display);
        glutMainLoop();
        return 0;

}

