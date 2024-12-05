#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

void ayarlar(void){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	glVertex2f(5.0, 35.0);
	glVertex2f(14.4, 15.0);
	glVertex2f(47.5, 15.0);
	glVertex2f(23.6, -7.8);
	glVertex2f(29.4, -40.0);
	glVertex2f(0.0, -20.0);
	glVertex2f(-29.4, -40.0);
	glVertex2f(-23.6, -7.8);
	glVertex2f(-47.5, 15.0);
	glVertex2f(-14.4, 15.0);
	glEnd();

	glFlush();
}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("yildiz cizimi");
	ayarlar();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
