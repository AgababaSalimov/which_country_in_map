#include <stdio.h>
#include <stdlib.h>
#include <glut.h>

void ayarlar(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Arka plan rengini siyah yap
    glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0); // Görüş alanını ayarla
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    // Ev gövdesi
    glColor3f(1.0, 0.5, 0.0); // Turuncu renk
    glBegin(GL_POLYGON);
    glVertex2f(-50, -50);
    glVertex2f(-50, 30);
    glVertex2f(50, 30);
    glVertex2f(50, -50);
    glEnd();

    // Çatı
    glColor3f(0.5, 0.0, 0.0); // Koyu kırmızı
    glBegin(GL_TRIANGLES);
    glVertex2f(-55, 30);
    glVertex2f(55, 30);
    glVertex2f(0, 70);
    glEnd();

    // Kapı
    glColor3f(0.4, 0.2, 0.0); // Kahverengi
    glBegin(GL_POLYGON);
    glVertex2f(-15, -50);
    glVertex2f(-15, 0);
    glVertex2f(15, 0);
    glVertex2f(15, -50);
    glEnd();

    // Pencere (Sol tarafa yerleştirilmiş)
    glColor3f(0.0, 0.5, 1.0); // Mavi
    glBegin(GL_POLYGON);
    glVertex2f(-40, -10);
    glVertex2f(-40, 10);
    glVertex2f(-20, 10);
    glVertex2f(-20, -10);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Ev Çizimi");
    ayarlar();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
