#include "desenhaTiroInimigo.h"
#include "variaveisglobais.h"

#include <stdio.h>
#include <stdlib.h>

#define tamanhoLadoSprite 80

void desenhaTiroInimigo(){


    glBegin(GL_TRIANGLE_FAN);

                
            glVertex3f(xTiroInimigo, yTiroInimigo ,  0); //baixo esquerda
                
            glVertex3f( xTiroInimigo+10, yTiroInimigo,  0);

            glVertex3f( xTiroInimigo+10,  yTiroInimigo+10,  0);

            glVertex3f( xTiroInimigo,  yTiroInimigo+10,  0);
            

    glEnd();
    
    
}
