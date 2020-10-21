#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include "contagemVidas.h"

void contagemVidas(){
        
        switch (vidas){
            case 3:
                idTexturaAuxiliar = idTexturaVidas3;
            break;
            case 2:
                idTexturaAuxiliar = idTexturaVidas2;
            break;
            case 1:
                idTexturaAuxiliar = idTexturaVidas1;
            break;
        }
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, idTexturaAuxiliar);
        glBegin(GL_TRIANGLE_FAN);

                    
            glTexCoord2f(0, 0);
            glVertex3f(600, 600,  0);

            glTexCoord2f(1, 0);
            glVertex3f( 700, 600,  0);

            glTexCoord2f(1, 1);
            glVertex3f( 700,  650,  0);

            glTexCoord2f(0, 1);
            glVertex3f(600,  650,  0);
                

        glEnd();
        glDisable(GL_TEXTURE_2D);
    
}