#include <SOIL/SOIL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>
#include "desenhanave.h"
#include "variaveisglobais.h"
#include "atiracaninha.h"

#define tamanhoLadoSprite 80 //o lado do quadrado q contem a sprite do personagem principal tem 80 de largura e altura.
#define xSpriteAtual 0.1 //x para a seleção da imagem da sprite 

float yVerticeSprite=10;

void desenhaNave(){
    
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, idTexturaLulinha);
    glBegin(GL_TRIANGLE_FAN);
        if (costas){
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


        }
        else{
            if(!direita){
                glTexCoord2f(xPosicaoSprite, 0);
                glVertex3f(xVerticeSprite, yVerticeSprite,  0);
                xPosicaoSprite+=xSpriteAtual;
                xVerticeSprite+=tamanhoLadoSprite;

                glTexCoord2f(xPosicaoSprite, 0);
                glVertex3f( xVerticeSprite, yVerticeSprite,  0);
                yVerticeSprite+=tamanhoLadoSprite;

                glTexCoord2f(xPosicaoSprite,1);
                glVertex3f( xVerticeSprite,  yVerticeSprite,  0);
                xPosicaoSprite-=xSpriteAtual;
                xVerticeSprite-=tamanhoLadoSprite;

                glTexCoord2f(xPosicaoSprite, 1);
                glVertex3f(xVerticeSprite,  yVerticeSprite,  0);
                yVerticeSprite-=tamanhoLadoSprite;
            }

            else{
                glTexCoord2f(xPosicaoSprite, 0);
                glVertex3f(xVerticeSprite, yVerticeSprite,  0);
                xPosicaoSprite+=xSpriteAtual;
                xVerticeSprite+=tamanhoLadoSprite;

                glTexCoord2f(xPosicaoSprite, 0);
                glVertex3f( xVerticeSprite, yVerticeSprite,  0);
                yVerticeSprite+=tamanhoLadoSprite;

                glTexCoord2f(xPosicaoSprite,1);
                glVertex3f( xVerticeSprite,  yVerticeSprite,  0);
                xPosicaoSprite-=xSpriteAtual;
                xVerticeSprite-=tamanhoLadoSprite;

                glTexCoord2f(xPosicaoSprite, 1);
                glVertex3f(xVerticeSprite,  yVerticeSprite,  0);
                yVerticeSprite-=tamanhoLadoSprite;
            }
        }

    glEnd();
    glDisable(GL_TEXTURE_2D);
}

