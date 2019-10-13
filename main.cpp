/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

static int xi,yi,xf,yf;

void inicial()
{
    glClearColor(1.0,1.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glPointSize(8.0);
    gluOrtho2D(-10,10,-10,10); //coordenadas entre <-10,10>
}

void setPixel(GLint x,GLint y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

void draw_Line()
{
    int x,y;
    int dx,dy;
    int pk;
    int k;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
    setPixel(xi,yi);
    dx=xf-xi;
    dy=yf-yi;
    pk=2*dy-dx;
    x=xi;
    y=yi;
    for(k=0;k<dx-1;++k)
    {
        if(pk<0)
        {
            pk=pk+2*dy;
        }else
        {
            pk=pk+2*dy-2*dx;
            ++y;
        }
        ++x;
        setPixel(x,y);
    }
        glFlush();
}

int main (int argc,char **argv)
{
    cout<<"INGRESAR LAS COORDENADAS: "<<endl;
    cin>>xi;
    cin>>yi;
    cin>>xf;
    cin>>yf;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(50,25);
    glutInitWindowSize(640,480);
    glutCreateWindow("TAREA GRAFICA");
    inicial();
    glutDisplayFunc(draw_Line);
    glutMainLoop();
    return 0;
}
