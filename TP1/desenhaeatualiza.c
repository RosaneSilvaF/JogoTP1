#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "desenhanave.h"
#include "variaveisglobais.h"
#include "desenhaeatualiza.h"

void desenha() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f (1, 1, 1);

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaFundo);
    glBegin(GL_TRIANGLE_FAN);
        
        glTexCoord2f(0, 0);
        glVertex3f(0, 0,  0);

        glTexCoord2f(1, 0);
        glVertex3f( 400, 0,  0);

        glTexCoord2f(1, 1);
        glVertex3f( 400,  600,  0);

        glTexCoord2f(0, 1);
        glVertex3f(0,  600,  0);

    glEnd();
    glDisable(GL_TEXTURE_2D);

    desenhaNave();

    glutSwapBuffers();
}


void atualiza(int periodo) {
    glutPostRedisplay();
    glutTimerFunc(33,atualiza,0);
}