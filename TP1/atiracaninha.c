#include "atiracaninha.h"
#include "variaveisglobais.h"

void atiraCaninha(){
    float ladoCaninha=20;


	glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaCaninha);
    glPushMatrix();
    glTranslatef(xCaninha, yCaninha, 0);

    glBegin(GL_TRIANGLE_FAN);

            glTexCoord2f(0, 0);
            glVertex3f(-ladoCaninha, -ladoCaninha,  0);


            glTexCoord2f(1, 0);
            glVertex3f( ladoCaninha, -ladoCaninha,  0);

            glTexCoord2f(1,1);
            glVertex3f( ladoCaninha,  ladoCaninha,  0);

            glTexCoord2f(0, 1);
            glVertex3f(-ladoCaninha,  ladoCaninha,  0);

    glEnd();
    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
}