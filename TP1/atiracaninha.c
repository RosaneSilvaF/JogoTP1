#include "atiracaninha.h"
#include "variaveisglobais.h"

void atiraCaninha(){
	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaCaninha);
    glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.4, 0);
            glVertex3f(xVerticeSprite, yVerticeSprite,  0);
            xVerticeSprite+=tamanhoLadoSprite;

            glTexCoord2f(0.5, 0);
            glVertex3f( xVerticeSprite, yVerticeSprite,  0);
            yVerticeSprite+=tamanhoLadoSprite;

            glTexCoord2f(0.5,1);
            glVertex3f( xVerticeSprite,  yVerticeSprite,  0);
            xVerticeSprite-=tamanhoLadoSprite;

            glTexCoord2f(0.4, 1);
            glVertex3f(xVerticeSprite,  yVerticeSprite,  0);
            yVerticeSprite-=tamanhoLadoSprite;

    glEnd();
    glDisable(GL_TEXTURE_2D);
}