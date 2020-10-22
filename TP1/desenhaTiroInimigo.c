#include "desenhaTiroInimigo.h"
#include "variaveisglobais.h"

#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>


void desenhaTiroInimigo(){

	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaAlgema);
    glBegin(GL_TRIANGLE_FAN);

            glTexCoord2f(0, 0);
            glVertex3f(xTiroInimigo, yTiroInimigo ,  0); //baixo esquerda
            
            glTexCoord2f(1, 0);
            glVertex3f( xTiroInimigo+40, yTiroInimigo,  0);

            glTexCoord2f(1, 1);
            glVertex3f( xTiroInimigo+40,  yTiroInimigo+40,  0);

            glTexCoord2f(0, 1);
            glVertex3f( xTiroInimigo,  yTiroInimigo+40,  0);
            

    glEnd();
    glDisable(GL_TEXTURE_2D);
    
}
