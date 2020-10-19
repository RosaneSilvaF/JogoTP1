#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

#include "desenhanave.h"
#include "desenhaexercito.h"
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
        glVertex3f( 700, 0,  0);

        glTexCoord2f(1, 1);
        glVertex3f( 700,  650,  0);

        glTexCoord2f(0, 1);
        glVertex3f(0,  650,  0);

    glEnd();
    glDisable(GL_TEXTURE_2D);

    desenhaNave();
    abateDeGado();
    abateDeGado2();

    //for (int i = 0; i < 8; i++){ 
        desenhaExercito(); 
    //}
    

    if(tiro){
        atiraCaninha();
        if(yCaninha<700){
                yCaninha+=10;
            }
            else{
                tiro=0;
                yCaninha=80;
            }
    }

    glutSwapBuffers();
}


void atualiza(int periodo) {
    if(continua){
        glutPostRedisplay();
        glutTimerFunc(33,atualiza,0);
    }
    //else{
        //tela fim
    //}
}
